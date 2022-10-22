#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    program();
}


//===================//
//   begin program   //
//===================//

const int MX = 2005;
int testCases;
int n;
string s, t;
int dp[MX][MX];
int cnts[30][MX], cntt[30][MX];

int getAns(int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];
    char x = t[j-1];
    int inS = cnts[x][n] - cnts[x][i];
    int inT = cntt[x][n] - cntt[x][j];
    int ans = INF;
    if(j > 0 && inS > inT) ans = min(ans, getAns(i,j-1));
    if(j > 0 && s[i-1] == t[j-1]) ans = min(ans, getAns(i-1, j-1));
    ans = min(ans, getAns(i-1, j)+1);
    return dp[i][j] = ans;
}

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n;
        cin>>s>>t;
        RE(i,n) s[i] -= 'a';
        RE(i,n) t[i] -= 'a';
        RE(i,30) {
            cnts[i][0] = 0;
            RE1(j,n) cnts[i][j] = cnts[i][j-1] + (s[j-1]==i?1:0);
            cntt[i][0] = 0;
            RE1(j,n) cntt[i][j] = cntt[i][j-1] + (t[j-1]==i?1:0);
        }
        RE(i,n+2) RE(j,n+2) dp[i][j] = -1;
        RE(j,n+2) dp[0][j] = 0;
        RE(j,n+2) dp[j][0] = j;
        bool pos = 1;
        RE(i,30) if(cnts[i][n] != cntt[i][n]) {
            pos = 0;
        }
        if(!pos) {
            cout<<-1<<endl;
            continue;
        }
        cout<<getAns(n, n)<<endl;
    }
}