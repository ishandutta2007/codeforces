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
 
const int MX = 5e5;
const int N = (1<<18);

int testCases;
ll n, a[MX];
ll b[MX];

ll gcd(ll x, ll y) {return y == 0 ? x : gcd(y,x%y);}

#pragma region segtree Seg
ll Seg[N*2];

ll getEmptySeg() {return 0;}
void resetSeg(ll& x, int i) {x = b[i];}
ll combineSeg(ll l, ll r) {return gcd(l,r);}

void buildSeg(int p=1, int l=0, int r=N-1) {
    if(l == r) {resetSeg(Seg[p], l); return;}
    int m=(l+r)/2;
    buildSeg(p*2  , l  , m);
    buildSeg(p*2+1, m+1, r);
    Seg[p] = combineSeg(Seg[p*2], Seg[p*2+1]);
}
void setSeg(int i, ll v, int p=1, int l=0, int r=N-1) {
    if(i < l || i > r) return;
    if(l == r) {Seg[p] = v; return;}
    int m=(l+r)/2;
    setSeg(i, v, p*2  , l  , m);
    setSeg(i, v, p*2+1, m+1, r);
    Seg[p] = combineSeg(Seg[p*2], Seg[p*2+1]);
}
ll getSeg(int i, int j, int p=1, int l=0, int r=N-1) {
    if(j < l || i > r) return getEmptySeg();
    if(i <= l && j >= r) return Seg[p];
    int m=(l+r)/2;
    ll a=getSeg(i, j, p*2  , l  , m);
    ll b=getSeg(i, j, p*2+1, m+1, r);
    return combineSeg(a,b);
}
#pragma endregion



void program() {
    buildSeg();
    IN(testCases);
    while(testCases--) {
        IN(n);
        RE(i,n) IN(a[i]);
        RE(i,n-1) b[i] = abs(a[i]-a[i+1]);

        RE(i,n-1)
            setSeg(i,b[i]);
        
        ll ans = 1;
        ll lb = 0, ub = 0;
        while(ub != n-1) {
            while(lb != ub && getSeg(lb,ub) == 1)
                lb++;
            if(getSeg(lb,ub) != 1)
                ans = max(ans, ub-lb+2);
            ub++;
        }

        OUTL(ans);
    }
}