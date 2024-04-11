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

int n;
int c[MX];
vi adj[MX], chl[MX];
ll ans[MX];

void dfsChl(int u, int parent) {
    for(int v:adj[u]) if(v != parent) dfsChl(v, u), chl[u].pb(v);
}

int p[MX], r[MX], sets;
map<int, int> mp[MX];
ll highest[MX], sm[MX];
void buildDSU(int dsuSize) {
    RE(i,dsuSize) p[i]=i, r[i]=0;
    RE(i,dsuSize) {
        mp[i][c[i]]++;
        highest[i] = 1;
        sm[i] = c[i];
    }
    sets = dsuSize;
}
int getSet(int i) {return i==p[i]?i:p[i]=getSet(p[i]);}
bool isSameSet(int i, int j) {return getSet(i)==getSet(j);}
void unionSet(int i, int j) {
    if(!isSameSet(i,j)) {
        i=p[i], j=p[j];
        sets--;
        if(r[i] > r[j]) swap(i,j);
        p[i] = j;
        FOR(p,mp[i]) {
            mp[j][p.fi] += p.se;
            if(mp[j][p.fi] > highest[j]) {
                highest[j] = mp[j][p.fi];
                sm[j] = 0;
            }
            if(mp[j][p.fi] == highest[j]) {
                sm[j] += p.fi;
            }
        }
        if(r[i] == r[j]) r[j]++;
    }
}

void dfs(int u) {
    FOR(v,chl[u]) dfs(v);
    FOR(v,chl[u]) unionSet(u,v);
    ans[u] = sm[getSet(u)];
}


void program() {
    IN(n);
    RE1(i,n) IN(c[i]);
    RE(i,n-1) {
        int u, v;
        IN(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfsChl(1, -1);
    buildDSU(n+2);
    dfs(1);
    RE1(i,n) OUT(i==1?"":" ", ans[i]); OUTL();
}