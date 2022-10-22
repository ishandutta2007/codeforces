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

int testCases;
int n;
int a[MX];
set<int> adjS[MX], adj[MX];
queue<int> col[3];
bitset<MX> REM;

void program() {
    IN(testCases);
    while(testCases--) {
        IN(n);
        RE1(i,n) IN(a[i]);
        RE1(i,n) adjS[i].clear();
        RE(i,n-1) {
            int u, v; IN(u,v);
            adjS[u].insert(v);
            adjS[v].insert(u);
        }

        int ans = 1e9;
        RE1(beg,2) {
            RE1(i,n) adj[i] = adjS[i], REM[i] = 0;
            int cur = beg;
            RE1(i,n) if(adj[i].size() <= 1) col[a[i]].push(i), REM[i] = 1;

            int removed = 0;
            int cnt = 0;
            while(removed != n) {
                cnt++;
                while(!col[0].empty() || !col[cur].empty()) {
                    removed++;
                    int u = 0;
                    if(!col[0].empty()) {
                        u = col[0].front(); col[0].pop();
                    } else {
                        u = col[cur].front(); col[cur].pop();
                    }
                    FOR(v,adj[u]) {
                        adj[v].erase(u);
                        if(adj[v].size() <= 1 && !REM[v])
                            col[a[v]].push(v), REM[v] = 1;
                    }
                }
                cur = 3-cur;
            }
            ans = min(ans, cnt);
        }
        OUTL(ans);
    }
}