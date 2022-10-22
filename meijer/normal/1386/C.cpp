#include <bits/stdc++.h>
using namespace std;
 
//macros
typedef long long ll;
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
#define INF 1e9
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//===================//
//  Added libraries  //
//===================//
 
//===================//
//end added libraries//
//===================//
 
void program();
int main() {
    program();
}
 
 
//===================//
//   begin program   //
//===================//
 
const int MX = 2e5+5;
int n, m, q;
ii edges[MX];
vi adj[MX];
int l[MX], r[MX];
iii quer[MX];
int a[MX];
bitset<MX> vis, col;
bool ans;
 
void dfs(int u, bool c = 1) {
    if(vis[u]) {
        if(col[u] != c) ans=0;
        return;
    }
    vis[u] = 1;
    col[u] = c;
    for(int v:adj[u]) dfs(v, !c);
}
 
// dsu
struct dsuState {
    ii u, v;
    int ur, vr;
    bool possible;
};
stack<dsuState> dsuStack;
ii parent[MX];
int R[MX];
bool dsuPos;
void buildDSU(int dsuSize) {
    RE(i,dsuSize) parent[i]={i,0}, R[i]=0;
    dsuPos = 1;
    while(!dsuStack.empty()) dsuStack.pop();
}
pair<int, bool> getSet(int i) {
    if(parent[i].fi != i) {
        pair<int, bool> ret = getSet(parent[i].fi);
        ret.se ^= parent[i].se;
        return ret;
    }
    return parent[i];
}
bool addEdge(int i, int j) {
    ii pa = getSet(i);
    ii pb = getSet(j);
    if(R[pa.fi] < R[pb.fi])
        swap(pa, pb);
    dsuStack.push({parent[pa.fi], parent[pb.fi], R[pa.fi], R[pb.fi], dsuPos});
    if(pa.fi == pb.fi) {
        if(pa.se == pb.se) {
            dsuPos = 0;
            return 0;
        }
    } else {
        parent[pb.fi] = {pa.fi, pa.se^pb.se^1};
        if(R[pa.fi] == R[pb.fi])
            R[pa.fi]++;
    }
    return 1;
}
void rollback() {
    if(dsuStack.empty())
        return;
    dsuState s = dsuStack.top(); dsuStack.pop();
    dsuPos = s.possible;
    parent[s.u.fi] = s.u;
    parent[s.v.fi] = s.v;
    R[s.u.fi] = s.ur;
    R[s.v.fi] = s.vr;
}
 
int last[MX];
void dac(int l1, int l2, int r1, int r2) {
    if(l2 < l1) return;
    if(r2 < r1) return;
    int lmid=(l1+l2)/2;
 
 
    // find rmid
    int added=0;
    REP(i,l1,lmid) {
        ii uv = edges[i];
        addEdge(uv.fi, uv.se);
        added++;
    }
    int rmid=min(m,r2);
    REV(i,r1+1,r2+1) {
        if(!dsuPos) break;
        if(i > m) continue;
        rmid = i-1;
        ii uv = edges[i];
        addEdge(uv.fi, uv.se);
        added++;
    }
    if(dsuPos) rmid=m+1;
    while(added) rollback(), added--;
 
    last[lmid] = rmid;
 
    // range [l1, lmid-1]
    REP(i,rmid+1,r2+1) {
        if(i > m) continue;
        ii uv = edges[i];
        addEdge(uv.fi, uv.se);
        added++;
    }
    dac(l1, lmid-1, r1, rmid);
    while(added) rollback(), added--;
 
    // range [lmid+1, l2]
    REP(i,l1,lmid+1) {
        ii uv = edges[i];
        addEdge(uv.fi, uv.se);
        added++;
    }
    dac(lmid+1, l2, max(lmid+1, rmid), r2);
    while(added) rollback(), added--;
}
 
void program() {
    scanf("%d%d%d", &n, &m, &q);
    RE1(i,m) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        edges[i] = {u,v};
    }
    RE1(i,q) {
        scanf("%d%d", &l[i], &r[i]);
    }
    
 
    buildDSU(n);
    dac(1, m, 1, m+1);
 
    RE1(i,q) {
        a[i] = last[l[i]] >= r[i];
        if(last[l[i]] == m+1) a[i] = 0;
    }
 
    RE1(i,q) a[i] ? printf("YES\n") : printf("NO\n");
}