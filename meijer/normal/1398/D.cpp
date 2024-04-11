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
#define INF 1e9
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

const int MX = 201;

ll r, g, b;
ll R[MX], G[MX], B[MX];
ll dp[MX][MX][MX];

void program() {
    IN(r,g,b);
    RE(i,r) IN(R[i]);
    RE(i,g) IN(G[i]);
    RE(i,b) IN(B[i]);
    sort(R,R+r,greater<ll>());
    sort(G,G+g,greater<ll>());
    sort(B,B+b,greater<ll>());
    REV(i,0,r+1) REV(j,0,g+1) REV(k,0,b+1) {
        dp[i][j][k] = 0;
        if(i != r && j != g) dp[i][j][k] = max(dp[i][j][k], dp[i+1][j+1][k]+R[i]*G[j]);
        if(i != r && k != b) dp[i][j][k] = max(dp[i][j][k], dp[i+1][j][k+1]+R[i]*B[k]);
        if(j != g && k != b) dp[i][j][k] = max(dp[i][j][k], dp[i][j+1][k+1]+G[j]*B[k]);
    }
    OUTL(dp[0][0][0]);
}