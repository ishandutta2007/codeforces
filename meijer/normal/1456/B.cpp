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

int n, a[MX];

bool isAns(vi& f) {
    REP(i,1,f.size()) {
        if(f[i]<f[i-1]) return 1;
    }
    return 0;
}

void program() {
    IN(n);
    RE(i,n) IN(a[i]);
    
    if(n >= 70) {
        // ans is minimal 2
        int ans = 2;
        RE(i,n-1) {
            vi f;
            if(i) if(a[i]^a[i+1] < a[i-1]) ans = 1;
            if(i!=n-2) if(a[i]^a[i+1] > a[i+2]) ans = 1;
        }
        OUTL(ans);
    } else {
        int ans = 100;
        RE(cent,n+1) {
            RE(l,cent+1) {
                REP(r,cent,n+1) {
                    vi f;
                    RE(i,l) f.pb(a[i]);
                    int len = 0;
                    int sm = 0;
                    if(l != cent) {
                        REP(i,l,cent) sm ^= a[i], len++;
                        f.pb(sm);
                        len--;
                    }
                    sm = 0;
                    if(cent != r) {
                        REP(i,cent,r) sm ^= a[i], len++;
                        f.pb(sm);
                        len--;
                    }
                    REP(i,r,n) f.pb(a[i]);
                    if(isAns(f)) {
                        ans = min(ans, len);
                    }
                }
            }
        }
        if(ans == 100) ans = -1;
        OUTL(ans);
    }
}