#include <bits/stdc++.h>
using namespace std;

// macros
typedef long long ll;
typedef long double ld;
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
#define FOR(a,b) for(auto& a : b)
#define all(a) a.begin(), a.end()
#define INF 1e18
#define EPS 1e-9
#define pb push_back
#define popb pop_back
#define fi first
#define se second
#define sz size()
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// input
template<class T> void IN(T& x) {cin >> x;}
template<class H, class... T> void IN(H& h, T&... t) {IN(h); IN(t...); }

// output
template<class T1, class T2> void OUT(const pair<T1,T2>& x);
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }
template<class T1, class T2> void OUT(const pair<T1,T2>& x) {OUT(x.fi,' ',x.se);}
template<class... T> void OUTL(const T&... t) {OUT(t..., "\n"); }
template<class H> void OUTLS(const H& h) {OUTL(h); }
template<class H, class... T> void OUTLS(const H& h, const T&... t) {OUT(h,' '); OUTLS(t...); }

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

const int MX = 1e6+10;

ll n, a[MX];
ll r[3], d;

ll dp[MX][2][2]; // dp[i][j][k] = minimum time to finish levels [i, n] where boss i has j+1 lives left, if k then return at i-1

void program() {
    IN(n);
    RE(i,3) IN(r[i]);
    IN(d);
    RE(i,n) IN(a[i]);
    
    ll bestNormalKill = min(r[0], min(r[1],r[2]));

    dp[n-1][0][0] = bestNormalKill;
    dp[n-1][1][0] = min(r[1] + bestNormalKill + d*2, a[n-1]*bestNormalKill + r[2]);
    dp[n-1][1][0] = min(dp[n-1][1][0], a[n-1]*bestNormalKill + r[0]*2 + d*2);
    RE(i,2) dp[n-1][i][1] = dp[n-1][i][0]+d;
    
    REV(i,0,n-1) RE(hp,2) RE(k,2) {
        dp[i][hp][k] = INF;
        if(hp == 0) {
            dp[i][hp][k] = min(dp[i][hp][k], bestNormalKill + d + dp[i+1][1][k]);
        } else {
            ll minRet = min(r[1], a[i+1]*bestNormalKill + r[0]);

            dp[i][hp][k] = min(dp[i][hp][k], r[1] + bestNormalKill + minRet + d*3 + dp[i+1][0][k]);
            dp[i][hp][k] = min(dp[i][hp][k], a[i]*bestNormalKill + r[0]*2 + minRet + d*3 + dp[i+1][0][k]);

            dp[i][hp][k] = min(dp[i][hp][k], r[1] + bestNormalKill + d*3 + dp[i+1][1][k]);
            dp[i][hp][k] = min(dp[i][hp][k], r[1] + bestNormalKill + d   + dp[i+1][1][1]);
            dp[i][hp][k] = min(dp[i][hp][k], a[i]*bestNormalKill + r[0]*2 + d*3 + dp[i+1][1][k]);
            dp[i][hp][k] = min(dp[i][hp][k], a[i]*bestNormalKill + r[0]*2 + d + dp[i+1][1][1]);
            dp[i][hp][k] = min(dp[i][hp][k], a[i]*bestNormalKill + r[2] + d + dp[i+1][1][k]);
        }
        if(k) dp[i][hp][k] += d;
    }
    OUTL(dp[0][1][0]);
}