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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// input
template<class T> void IN(T& x) {cin >> x;}
template<class H, class... T> void IN(H& h, T&... t) {IN(h); IN(t...); }
 
// output
template<class T1, class T2> void OUT(const pair<T1,T2>& x);
template<class T> void OUT(const vector<T>& x);
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }
template<class T1, class T2> void OUT(const pair<T1,T2>& x) {OUT(x.fi,' ',x.se);}
template<class T> void OUT(const vector<T>& x) {RE(i,x.size()) OUT(i==0?"":" ",x[i]);}
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
 
const int MX = 5e5;

ll n;
ll p[MX], a[MX];
vi chl[MX];
ll dp[MX], add[MX], sz[MX];

void fillDP(int u) {
    FOR(v,chl[u]) fillDP(v);

    if(chl[u].size() == 0) {
        dp[u] = a[u];
        add[u] = 0;
        sz[u] = 1;
    } else {
        sz[u] = 0; add[u] = 0; dp[u] = 0;
        FOR(v,chl[u]) sz[u] += sz[v];
        FOR(v,chl[u]) dp[u] = max(dp[u], dp[v]);
        FOR(v,chl[u]) add[u] += add[v] + (dp[u]-dp[v])*sz[v];
        if(a[u] <= add[u]) {
            add[u] -= a[u];
            a[u] = 0;
        } else {
            a[u] -= add[u];
            add[u] = 0;
            dp[u] += (a[u]+sz[u]-1)/sz[u];
            add[u] = (sz[u] - (a[u]%sz[u]))%sz[u];
        }
    }
}

void program() {
    IN(n);
    p[1] = 0;
    REI(i,2,n) IN(p[i]);
    RE1(i,n) IN(a[i]);
    RE1(i,n) chl[p[i]].pb(i);
    fillDP(1);
    OUTL(dp[1]);
}