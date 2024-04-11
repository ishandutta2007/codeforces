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

int n, m, N;
string gr[MX];
int a[MX];
vi adj[MX], rev[MX];
int used[MX];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool inside(int x, int y) {return x>=0 && x<n && y>=0 && y<m;}

vi order;
int comp[MX];
void dfs1(int v) {
    used[v] = 1;
    FOR(u,adj[v])
        if(!used[u])
            dfs1(u);
    order.pb(v);
}
void dfs2(int v, int c) {
    used[v] = 1;
    comp[v] = c;
    FOR(u,rev[v])
        if(!used[u])
            dfs2(u,c);
}
vi adj2[MX], rev2[MX];

int mandatory[MX];

void dfs3(int u) {
    if(used[u]) return;
    used[u] = 1;
    FOR(v,adj2[u])
        mandatory[v] = 0, dfs3(v);
}

int minL[MX], maxL[MX];
void dfs4(int u) {
    if(used[u]) return;
    used[u] = 1;
    maxL[u] = minL[u] == 1e9 ? 0 : minL[u];
    FOR(v,adj2[u]) {
        dfs4(v);
        minL[u] = min(minL[u],minL[v]);
        maxL[u] = max(maxL[u],maxL[v]);
    }
}

int sm[MX];
int delta[MX];

vi ed[MX];

void program() {
    IN(n,m); N=n*m;
    RE(i,n) IN(gr[i]);
    RE(i,m) IN(a[i]);

    int tot = 0;
    RE(i,m) tot += a[i];
    if(tot == 0) {
        OUTL(0);
        return;
    }

    RE(i,n) RE(j,m) {
        if(gr[i][j] == '#') {
            RE(d,4) {
                int nx=i+dx[d];
                int ny=j+dy[d];
                if(!inside(nx,ny)) continue;
                if(gr[nx][ny] != '#') continue;
                adj[i+j*n].pb(nx+ny*n);
            }
            int x=i+1, y=j;
            while(x < n && gr[x][y] != '#') {
                RE(d,4) {
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(!inside(nx,ny)) continue;
                    if(gr[nx][ny] != '#') continue;
                    if(nx==i && ny==j) continue;
                    adj[i+j*n].pb(nx+ny*n);
                }
                x++;
            }
        }
    }

    RE(i,N) FOR(j,adj[i]) rev[j].pb(i);

    RE(i,N) used[i] = 0;
    RE(i,N) if(!used[i]) dfs1(i);
    RE(i,N) used[i] = 0;
    reverse(all(order));
    FOR(u,order) if(!used[u]) {
        dfs2(u,u);
    }

    RE(u,N) FOR(v,adj[u]) if(comp[u] != comp[v]) adj2[comp[u]].pb(comp[v]);
    RE(u,N) FOR(v,rev[u]) if(comp[u] != comp[v]) rev2[comp[u]].pb(comp[v]);

    RE(i,N) {
        sort(all(adj2[i]));
        adj2[i].erase(unique(all(adj2[i])), adj2[i].end());
        sort(all(adj2[i]));
        adj2[i].erase(unique(all(adj2[i])), adj2[i].end());
    }

    RE(i,N) minL[i] = 1e9;
    RE(j,m) {
        int x = n-1;
        int cnt = 0;
        while(cnt < a[j]) {
            if(gr[x][j] == '#') {
                cnt++;
                mandatory[comp[x+j*n]] = 1;
                minL[comp[x+j*n]] = min(minL[comp[x+j*n]], j);
            }
            x--;
        }
    }

    RE(i,N) used[i] = 0;
    RE(j,m) {
        int x = n-1;
        int cnt = 0;
        while(cnt < a[j]) {
            if(gr[x][j] == '#') {
                cnt++;
                dfs3(comp[x+j*n]);
            }
            x--;
        }
    }

    RE(i,N) if(!mandatory[i]) minL[i]=1e9, maxL[i] = 0;
    RE(i,N) used[i] = 0;
    RE(i,N) dfs4(i);

    vii ranges;
    RE(i,N) if(minL[i] != 1e9) ranges.pb({minL[i],maxL[i]});

    FOR(p,ranges)
        ed[p.fi].pb(p.se);
    int ans=0;
    int lastX = -1, mxr = 0;
    RE(i,m) {
        bool changed = false;
        FOR(x,ed[i])
            mxr = max(mxr,x), changed = true;
        if(changed && i > lastX) {
            lastX  = mxr+1;
            ans++;
        }
    }
    if(lastX != mxr+1) ans++;

    OUTL(ans);
}