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

int testCases;
int n, m, p[MX];
int good[MX];

int par[MX], r[MX], sets;
void buildDSU(int dsuSize) {
    RE(i,dsuSize) par[i]=i, r[i]=0;
    sets = dsuSize;
}
int getSet(int i) {return i==par[i]?i:par[i]=getSet(par[i]);}
bool isSameSet(int i, int j) {return getSet(i)==getSet(j);}
void unionSet(int i, int j) {
    if(!isSameSet(i,j)) {
        i=par[i], j=par[j];
        sets--;
        if(r[i] > r[j]) {
            par[j] = i;
        } else {
            par[i] = j;
            if(r[i] == r[j]) r[j]++;
        }
    }
}

int f[MX];
bool check(int x) {
    buildDSU(n);
    RE1(i,n) f[i] = ((p[i]+x+n-1)%n)+1;
    RE1(i,n) unionSet(f[i]-1,i-1);
    return m >= n-sets;
}

void program() {
    IN(testCases);
    while(testCases--) {
        IN(n,m);
        RE1(i,n) IN(p[i]);

        RE(i,n) good[i] = 0;
        RE1(i,n)
            good[(i-p[i]+n)%n]++;
        
        vi ans;
        RE(i,n) {
            if(good[i] > (n-10)/3) {
                if(check(i)) {
                    ans.pb(i);
                }
            }
        }

        OUT(ans.size());
        if(ans.size()) OUT(" ");
        OUTL(ans);
    }
}