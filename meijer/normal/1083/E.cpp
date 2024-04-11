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
 
// dp
template<class T> bool ckmin(T&a, T&b) { bool bl = a > b; a = min(a,b); return bl;}
template<class T> bool ckmax(T&a, T&b) { bool bl = a < b; a = max(a,b); return bl;}
 
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
 
const int MX = 1e6+20;
const int N = (1<<20);

int n;
ll x[MX], y[MX], a[MX];
int sx[MX];
ll dp[MX];

ll eval(lll line, ll x) {
    return line.fi*x + line.se;
}
ld intersectX(lll a, lll b) {
    return ld(a.se - b.se)/ld(b.fi - a.fi);
}

void program() {
    IN(n);
    RE(i,n) IN(x[i],y[i],a[i]);

    RE(i,n) sx[i]=i;
    sort(sx,sx+n,[](int i, int j) {
        return x[i]<x[j];
    });

    deque<lll> dq;
    dq.push_front({0,0});

    ll ans = 0;
    RE(i,n) {
        while(dq.size() >= 2 && eval(dq[0], y[sx[i]]) <= eval(dq[1], y[sx[i]]))
            dq.pop_front();

        dp[i] = x[sx[i]]*y[sx[i]] - a[sx[i]] + eval(dq[0], y[sx[i]]);

        ans = max(ans, dp[i]);

        lll cur = {-x[sx[i]], dp[i]};
        while(dq.size() >= 2 && intersectX(dq.back(), cur) >= intersectX(dq.back(), dq[dq.size()-2]))
            dq.pop_back();
        dq.pb(cur);
    }

    OUTL(ans);
}