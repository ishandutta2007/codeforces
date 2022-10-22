#include <bits/stdc++.h>
using namespace std;

#define int ll

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
signed main() {
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

int n, m, x;
int a[MX];

int p[MX], r[MX], sm[MX];
vii adj[MX], adj2[MX];
void buildDSU(int dsuSize) {
    RE(i,dsuSize) p[i]=i, r[i]=0, sm[i]=a[i];
}
int getSet(int i) {return i==p[i]?i:p[i]=getSet(p[i]);}
bool isSameSet(int i, int j) {return getSet(i)==getSet(j);}
void unionSet(int i, int j) {
    if(!isSameSet(i,j)) {
        i=p[i], j=p[j];
        sm[i] = sm[j] = sm[i]+sm[j];

        if(adj[i].size() > adj[j].size()) swap(adj[i],adj[j]);
        FOR(e,adj[i]) adj[j].pb(e);
        adj[i].clear();

        if(r[i] > r[j]) {
            p[j] = i;
            swap(adj [i],adj [j]);
        } else {
            p[i] = j;
            if(r[i] == r[j]) r[j]++;
        }
    }
}


void program() {
    IN(n,m,x);
    RE(i,n) IN(a[i]);
    RE(i,m) {
        int u, v; IN(u,v); u--; v--;
        adj[u].pb({v,i+1});
        adj[v].pb({u,i+1});
    }
    buildDSU(n);

    priority_queue<ii> pq;
    vi ans;

    RE(i,n) pq.push({sm[i], i});
    while(!pq.empty()) {
        ii p = pq.top(); pq.pop();
        int u = getSet(p.se);
        if(sm[u] != p.fi) {
            pq.push({sm[u],u});
            continue;
        }

        while(!adj[u].empty()) {
            ii p2 = adj[u].back(); adj[u].pop_back();
            int v = getSet(p2.fi);
            if(isSameSet(u,v)) continue;
            if(sm[u] + sm[v] >= x) {
                unionSet(u,v);
                sm[getSet(u)] -= x;
                pq.push({sm[getSet(u)],getSet(u)});
                ans.pb(p2.se);
                break;
            }
        }
    }

    if(ans.size() == n-1) {
        OUTL("YES");
        FOR(i,ans) OUTL(i);
    } else {
        OUTL("NO");
    }
}