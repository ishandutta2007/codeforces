#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
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

const int MX = 2e5;
int testCases;
int n;
string s;
int cnt[MX][26];
int dp[MX][26];

int getAns(int x, int c) {
    if(dp[x][c] != -1) return dp[x][c];

    int ans = INF;
    int len = n/(1<<c);

    if(len == 1) {
        return dp[x][c] = (s[x] != c);
    }

    // left
    ans = min(ans, getAns(x,c+1) + len/2 - (cnt[x+len][c]-cnt[x+len/2][c]));

    // right
    ans = min(ans, getAns(x+len/2,c+1) + len/2 - (cnt[x+len/2][c]-cnt[x][c]));

    return dp[x][c] = ans;
}

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>s;
        RE(i,n) s[i]-='a';
        RE(i,26) cnt[0][i] = 0;
        RE(i,n) RE(j,26) cnt[i+1][j] = cnt[i][j] + (s[i]==j);
        RE(i,n) RE(j,26) dp[i][j] = -1;
        cout<<getAns(0,0)<<endl;
    }
}