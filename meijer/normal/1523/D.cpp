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
const int N = (1<<20);

ll n, m, p;
ll a[MX];
map<ll,ll> cnt;
map<ll,vll> bstPop;

bool check(ll bm) {
    int cnt = 0;
    RE(i,n) if((a[i]&bm) == bm) cnt++;
    return cnt >= (n+1)/2;
}

void program() {
    IN(n,m,p);
    RE(i,n) {
        string s; IN(s);
        a[i] = 0;
        RE(j,m) if(s[j]=='1') a[i] |= (1ll<<ll(j));
    }

    int timeTaken = 0;
    while(timeTaken <= 10000000) {
        int x = rng()%n;
        int y = rng()%n;

        ll comb = a[x]&a[y];
        vll dif;
        RE(j,m) if(comb&(1ll<<ll(j))) dif.pb(j);
        timeTaken += m;

        RE(bm,(1ll<<(dif.size()))) {
            ll nbm=0;
            RE(i,dif.size()) if(bm&(1ll<<i)) nbm |= (1ll<<dif[i]);
            cnt[nbm]++;
        }
        timeTaken += (1ll<<(dif.size()));
    }

    vlll best;
    FOR(p,cnt) best.pb({p.se,p.fi});
    sort(all(best));

    FOR(x,best) bstPop[__builtin_popcountll(x.se)].pb(x.se);

    ll ans = 0;
    FOR(p,bstPop) {
        RE(_,10) {
            if(p.se.empty()) break;
            if(check(p.se.back())) {
                ans = p.se.back();
                break;
            }
            p.se.pop_back();
        }
    }

    RE(i,m) OUT(ans&(1ll<<ll(i)) ? '1' : '0');
    OUTL();
}