#pragma GCC optimize("Ofast")
#pragma GCC tet("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

template<typename T> class Dinic {
public:
static const T MAXN = 2004;
struct edge {
  T a, b, cap, flow;
};
/*
Set
dinic_numnodes: number of nodes
dinic_src: Source vertex
dinic_dest: Target vertex
No need to initialize anything else. Run ge.clear() and dinic_graph.clear() between runs.
*/
T dinic_numnodes, dinic_src, dinic_dest, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> dinic_edge;
vector<T> dinic_graph[MAXN];
 
void add_edge (T a, T b, T cap) {
  //printf("%Td->%Td:%Td\n",a,b,cap);
  edge e1 = { a, b, cap, 0 };
  edge e2 = { b, a, 0, 0 };
  dinic_graph[a].push_back ((T) dinic_edge.size());
  dinic_edge.push_back (e1);
  dinic_graph[b].push_back ((T) dinic_edge.size());
  dinic_edge.push_back (e2);
}

bool dinic_bfs() {
  int qh=0, qt=0;
  q[qt++] = dinic_src;
  memset (d, -1, dinic_numnodes * sizeof d[0]);
  d[dinic_src] = 0;
  while (qh < qt && d[dinic_dest] == -1) {
    T v = q[qh++];
    for (size_t i=0; i<dinic_graph[v].size(); ++i) {
      T id = dinic_graph[v][i],
        to = dinic_edge[id].b;
      if (d[to] == -1 && dinic_edge[id].flow < dinic_edge[id].cap) {
        q[qt++] = to;
        d[to] = d[v] + 1;
      }
    }
  }
  return d[dinic_dest] != -1;
}
 
T dinic_dfs (T v, T flow) {
  if (!flow)  return 0;
  if (v == dinic_dest)  return flow;
  for (; ptr[v]<(T)dinic_graph[v].size(); ++ptr[v]) {
    T id = dinic_graph[v][ptr[v]],
      to = dinic_edge[id].b;
    if (d[to] != d[v] + 1)  continue;
    T pushed = dinic_dfs (to, min (flow, dinic_edge[id].cap - dinic_edge[id].flow));
    if (pushed) {
      dinic_edge[id].flow += pushed;
      dinic_edge[id^1].flow -= pushed;
      return pushed;
    }
  }
  return 0;
}
 
T flow(T src, T dest, T numnodes) {
  if (src==dest) return INF;
  dinic_src = src;
  dinic_dest = dest;
  dinic_numnodes = numnodes;
  T flow = 0;
  for (;;) {
    if (!dinic_bfs())  break;
    memset (ptr, 0, dinic_numnodes * sizeof ptr[0]);
    while (T pushed = dinic_dfs (dinic_src, INF))
      flow += pushed;
  }
  return flow;
}
void dinic_clear(T numnodes) {
  dinic_edge.clear();
  for (int v=0;v<numnodes;v++) dinic_graph[v].clear(); 
}
bitset<MAXN> inS;
void _getCut(int x) {
  // Returns nodes connected to source.
  inS[x]=true;
  for (auto &ei:dinic_graph[x]) {
    auto &e=dinic_edge[ei];
    if (e.cap>e.flow) {
      int y=e.b;
      if (!inS[y]) {
        _getCut(y);
      }
    }
  }
}
void getCut() {
  inS.reset(); _getCut(dinic_src);
}

};

template<typename T> int bins(const vector<T> &v, const T key) {
  int imin=0,imax=v.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (v[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
int gid=2;
int SRC=0,DEST=1;
map<pii,int> h[2];
Dinic<int> dinic;
vector<pair<int,pii> > g2t;
int getid(int t, pii p) {
  auto it=h[t].find(p);
  if (it!=h[t].end()) return it->snd;
  h[t][p]=gid;
  g2t.PB(MP(t,p));
  if (t==0) dinic.add_edge(SRC,gid,1);
  else dinic.add_edge(gid,DEST,1);
  return gid++;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  g2t.resize(2);
  int n; cin>>n;
  map<int,vi> x2y[2];
  set<pii> s;
  for (int i=0;i<n;i++) {
    int x,y; cin>>x>>y;
    x2y[0][x].PB(y);
    x2y[1][y].PB(x);
    //printf("x:%d y:%d\n",x,y);
    s.insert(MP(x,y));
  }
  for (int t=0;t<2;t++) for (auto &a:x2y[t]) sort(a.snd.begin(),a.snd.end());
  //int nume=0;
  for (int t=0;t<2;t++) {
    for (auto &a:x2y[t]) {
      //nume+=(int)a.snd.size()-1;
      int py=-1;
      for (auto &ny:a.snd) {
        if (py!=-1) getid(t,MP(a.fst,py));
        py=ny;
      }
    }
  }
  {
    int t=0;
    for (auto &a:x2y[t]) {
    int x=a.fst;
    int py=-1;
    auto yit=x2y[t^1].begin();
    for (auto &ny:a.snd) {
      if (py!=-1) {
        // Find y between py and ny
        while(yit!=x2y[t^1].end()&&yit->fst < py) ++yit;
        while(yit!=x2y[t^1].end()&&yit->fst <= ny) {
          int cix=bins(yit->snd,x);
          for (int ix=max(0,cix-3);ix<min((int)yit->snd.size()-1,cix+3);ix++) {
            int px=yit->snd[ix];
            int nx=yit->snd[ix+1];
            int y=yit->fst;
            if (px<=x&&x<=nx && py<=y&&y<=ny && s.find(MP(x,y))==s.end()) {
              int id1=getid(t,MP(x,py)),id2=getid(t^1,MP(y,px));
              //printf("t:%d x:%d y:%d -> %d. x:%d -> %d. y:%d\n",t,x,py,ny,px,nx,y);
              if (t==1) swap(id1,id2);
              dinic.add_edge(id1,id2,5000);
              //printf("%d -> %d\n",id1,id2);
            }
          }
          ++yit;
        }
        if (yit!=x2y[t^1].begin()) --yit;
      }
      py=ny;
    }
  }}
  int flow=dinic.flow(SRC,DEST,gid);
  dinic.getCut();
  //for (auto &w:S) printf("%d ",w); printf(" end inS\n");
  vector<pair<int,pii> > vans[2];
  for (int t=0;t<2;t++) {
    for (auto &a:x2y[t]) {
      int x=a.fst;
      int ly=-1;
      int py=-1;
      for (auto &ny:a.snd) {
        if (ly==-1) ly=ny;
        if (py!=-1) {
          int id=getid(t,MP(x,py));
          //if (t==0) printf("t:%d x:%d ly:%d py:%d id:%d\n",t,x,ly,py,id);
          if ((t==0)!=(dinic.inS[id])) { // Break
            //if (t==0) printf("break\n");
            vans[t].PB(MP(x,MP(ly,py)));
            ly=ny;
          }
        }
        py=ny;
      }
      if (ly!=-1) {
        vans[t].PB(MP(x,MP(ly,py)));
      }
    }
  }
  printf("%d\n",(int)vans[1].size());
  for (auto &w:vans[1]) {
    printf("%d %d %d %d\n",w.snd.fst,w.fst,w.snd.snd,w.fst);
  }

  printf("%d\n",(int)vans[0].size());
  for (auto &w:vans[0]) {
    printf("%d %d %d %d\n",w.fst,w.snd.fst,w.fst,w.snd.snd);
  }

  int nume=gid-2;
  int ans=2*n-nume+flow;
  //printf("n:%d nume:%d flow:%d ans:%d\n",n,nume,flow,ans);
}