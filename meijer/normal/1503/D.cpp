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

int n;
int a[MX], b[MX], c[MX];
int mn[MX], mx[MX];
int f[MX];
bool possible = 1;

void program() {
    IN(n);
    RE1(i,n) IN(a[i],b[i]), c[i]=0;
    RE1(i,n) {
        if(a[i] > b[i]) swap(a[i],b[i]), c[a[i]] = 1;
        if(a[i] > n) {
            OUTL(-1);
            return;
        }
        f[a[i]] = b[i];
    }
    mn[1] = f[1]; mx[n] = f[n];
    REP(i,2,n) mn[i]=min(mn[i-1],f[i]);
    REV(i,1,n) mx[i]=max(mx[i+1],f[i]);

    auto getRange = [](int l, int r) {
        int low=0, high=0, sm=0;
        REV(i,l,r+1) {
            if(f[i] > high) high = f[i], sm += c[i];
            else if(f[i] > low) low = f[i], sm += 1 - c[i];
            else return -1;
        }
        return min(sm, r-l+1 - sm);
    };

    int ans = 0, prev = 0;
    RE1(i,n) {
        if(i == n || mn[i] > mx[i+1]) {
            int res = getRange(prev+1, i);
            if(res == -1) {
                OUTL(-1);
                return;
            }
            ans += res;
            prev = i;
        }
    }
    OUTL(ans);
}