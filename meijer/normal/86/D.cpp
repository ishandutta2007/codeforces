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
 
const int MX = 1e6+10;
const int N = (1<<20);
const int SQ = 450;

int n, t, a[MX];
int l[MX], r[MX];
vi difa[MX];
vi big;
ll ans[MX];

// fenwick tree
ll FT[MX];
void addFT(int i, ll value) {
    for(i++; i<MX; i+=i&-i) FT[i] += value;
}
ll getFT(int i) {
    ll ans = 0;
    for(i++; i; i-=i&-i) ans += FT[i];
    return ans;
}

vi ql[MX];
vi difb[MX];

void program() {
    IN(n,t);
    RE1(i,n) IN(a[i]);
    RE(i,t) IN(l[i],r[i]);

    RE1(i,n) difa[a[i]].pb(i);
    RE(i,t) ql[l[i]].pb(i);

    RE(i,MX) {
        if(difa[i].size() < SQ) continue;
        RE(j,t) {
            auto it1 = lower_bound(all(difa[i]),l[j]);
            auto it2 = upper_bound(all(difa[i]),r[j]);
            ll len = ll(it2-it1);
            ans[j] += len*len*ll(i);
        }
        FOR(j,difa[i]) a[j] = 0;
    }

    REV(i,1,n+1) {
        if(a[i] != 0) {
            ll sm = a[i];
            FOR(j,difb[a[i]]) {
                addFT(j,-sm);
                sm += a[i]*2ll;
            }
            reverse(all(difb[a[i]]));
            difb[a[i]].pb(i);
            reverse(all(difb[a[i]]));
            sm = a[i];
            FOR(j,difb[a[i]]) {
                addFT(j,sm);
                sm += a[i]*2ll;
            }
        }
        FOR(j,ql[i]) {
            ans[j] += getFT(r[j]);
        }
    }

    RE(i,t) OUTL(ans[i]);
}