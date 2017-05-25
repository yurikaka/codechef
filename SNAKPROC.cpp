//Snake Procession
//The annual snake festival is upon us, and all the snakes of the kingdom have gathered to participate in the procession. Chef has been tasked with reporting on the procession, and for this he decides to first keep track of all the snakes. When he sees a snake first, it'll be its Head, and hence he will mark a 'H'. The snakes are long, and when he sees the snake finally slither away, he'll mark a 'T' to denote its tail. In the time in between, when the snake is moving past him, or the time between one snake and the next snake, he marks with '.'s.
//
//Because the snakes come in a procession, and one by one, a valid report would be something like "..H..T...HTH....T.", or "...", or "HT", whereas "T...H..H.T", "H..T..H", "H..H..T..T" would be invalid reports (See explanations at the bottom).
//
//Formally, a snake is represented by a 'H' followed by some (possibly zero) '.'s, and then a 'T'. A valid report is one such that it begins with a (possibly zero length) string of '.'s, and then some (possibly zero) snakes between which there can be some '.'s, and then finally ends with some (possibly zero) '.'s.
//
//Chef had binged on the festival food and had been very drowsy. So his report might be invalid. You need to help him find out if his report is valid or not.
//
//Input
//        The first line contains a single integer, R, which denotes the number of reports to be checked. The description of each report follows after this.
//The first line of each report contains a single integer, L, the length of that report.
//The second line of each report contains a string of length L. The string contains only the characters '.', 'H', and 'T'.
//Output
//        For each report, output the string "Valid" or "Invalid" in a new line, depending on whether it was a valid report or not.
//Constraints
//1 ≤ R ≤ 500
//1 ≤ length of each report ≤ 500
//Example
//        Input:
//6
//18
//..H..T...HTH....T.
//3
//...
//10
//H..H..T..T
//2
//HT
//11
//.T...H..H.T
//7
//H..T..H
//
//        Output:
//Valid
//        Valid
//Invalid
//        Valid
//Invalid
//        Invalid
//Explanation
//"H..H..T..T" is invalid because the second snake starts before the first snake ends, which is not allowed.
//
//".T...H..H.T" is invalid because it has a 'T' before a 'H'. A tail can come only after its head.
//
//"H..T..H" is invalid because the last 'H' does not have a corresponding 'T'.

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <functional>
#include <iomanip>
#include <algorithm>
#include <math.h>


#define small

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;

typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;


#define MOD 1000000007
#define INF 0x3f3f3f3f

#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define REPE(i,s,t) for(int i=(s);i<=(t);++i)
#define FILL(x,v) memset(x,v,sizeof(x))
#define pb push_back
#define fin(filename) freopen(filename,"r",stdin)
#define fout(filename) freopen(filename,"w",stdout)

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

int xx[] = {0,0,0,0,-1,1};
int yy[] = {0,0,-1,1,0,0};
int zz[] = {1,-1,0,0,0,0};







int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
//    fin("test.in");
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        int cnt = 0;
        string s;
        cin >> s;
        bool valid = true;
        for(int i = 0; i < n; ++i){
            if(s[i] == '.')continue;
            if(s[i] == 'H') cnt++;
            if(cnt > 1){
                valid = false;
                break;
            }
            if(s[i] == 'T') cnt --;
            if(cnt < 0){
                valid = false;
                break;
            }
        }
        if(cnt != 0)valid = false;
        if(!valid)cout << "Invalid" << endl;
        else{
            cout << "Valid" << endl;
        }
    }
    return 0;
}