#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<vpii> vvpii;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=(2e5)+4;

template<typename T> void makeunique(vector<T> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
template<typename T> int bins(vector<T> &vx, T x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

// Answering LCA queries in O(1) with O(n*log(n)) preprocessing
class LcaSvparseTable {
public:
  int len=0;
  int** up;
  int* tin;
  int* tout;
  int timestamp=0;
  int* vdepth;

  void dfs(vector<vector<int> > &tree, int u, int p, int depth) {
    vdepth[u] = depth;
    tin[u] = timestamp++;
    up[0][u] = p;
    for (int i = 1; i < len; i++)
      up[i][u] = up[i - 1][up[i - 1][u]];
    for (int v : tree[u])
      if (v != p)
        dfs(tree, v, u, depth+1);
    tout[u] = timestamp++;
  }

  void init(vector<vector<int> > &tree, int root) {
    int n=tree.size();
    len = 1;
    while ((1 << len) <= n) ++len;
    up = new int*[len];
    for (int i=0;i<len;i++) {up[i]=new int[n]; memset(up[i],0,sizeof(up[i][0])*n);}
    tin = new int[n]; memset(tin,0, sizeof(tin[0])*n);
    tout = new int[n]; memset(tout,0,sizeof(tout[0]*n));
    vdepth = new int[n]; memset(vdepth,0,sizeof(vdepth[0]*n));
    dfs(tree, root, root, 0);
  }

  bool isParent(int vparent, int child) {
    return tin[vparent] <= tin[child] && tout[child] <= tout[vparent];
  }

  int lca(int oa, int ob) {
    // Returns only the lca
    int a=oa,b=ob;
    if (isParent(a, b))
      return a;
    if (isParent(b, a))
      return b;
    for (int i = len - 1; i >= 0; i--)
      if (!isParent(up[i][a], b))
        a = up[i][a];
    int ancestor=up[0][a];
    return ancestor;
  }
};

LcaSvparseTable L;

const int mx=mn;
int gdepth[mn];
class UnionFind {
  typedef int UFTYPE;
public:
  inline UFTYPE combine(UFTYPE x, UFTYPE y) {
    return (gdepth[x] < gdepth[y])?x:y;
  }
  inline UFTYPE getInitialValue(int x) {
    return x;
  }
  int ufParent[mx];
  int rank[mx];
  UFTYPE ufData[mx];
  inline void ufreset(int x) {
    ufParent[x]=x;
    ufData[x]=getInitialValue(x);
    rank[x]=0;
  }
  void init(int n) {
    for (int x=0;x<n;x++) {
      ufreset(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
    ufData[yr]=combine(ufData[xr],ufData[yr]);
  }
  UFTYPE getData(int x) {
    return ufData[ffind(x)];
  }
};

UnionFind uf;


vvi g;

int center[mn],speed[mn],impt[mn],va[mn];
pii vpar[mn];
vvpii h;
pii vtimevir[mn];
int rem[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  g.resize(n+1);
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  L.init(g, 1);
  int qn=rint();
  for (int qi=0;qi<qn;qi++) {
    int nv=rint(); int nc=rint();
    for (int k=0;k<nv;k++) {
      center[k]=rint(); speed[k]=rint();
    }
    for (int ci=0;ci<nc;ci++) {
      impt[ci]=rint();
    }
    vpii ev; ev.reserve(nv+nc);
    for (int k=0;k<nv;k++) {
      int x=center[k];
      ev.PB(MP(L.tin[x],x));
    }
    for (int ci=0;ci<nc;ci++) {
      int x=impt[ci];
      ev.PB(MP(L.tin[x],x));
    }
    makeunique(ev);
    int evsz=ev.size();
    vi allv; allv.reserve(2 * evsz - 1);
    for (auto &w:ev) {
      allv.PB(w.snd);
      vpar[w.snd]=MP(INF,INF);
    }

    vector<pair<int,pair<int,pii > > > vda; vda.reserve(evsz-1);
    for (int i=1;i<evsz;i++) {
      int l=ev[i-1].snd;
      int r=ev[i].snd;
      int a=L.lca(l,r);
      if (a!=l && a!=r) allv.PB(a);
      vda.PB(MP(-L.vdepth[a],MP(a,MP(l,r))));
    }
    sort(vda.begin(),vda.end());
    makeunique(allv);
    h.clear(); h.resize(allv.size());
    uf.init(allv.size());
    for (int x=0;x<allv.size();x++) gdepth[x]=L.vdepth[allv[x]];
    for (auto &w:vda) {
      int a=bins(allv, w.snd.fst);
      int x[2];
      x[0]=uf.getData(bins(allv, w.snd.snd.fst));
      x[1]=uf.getData(bins(allv, w.snd.snd.snd));
      for (int t=0;t<2;t++) {
        int l=x[t];
        if (l!=a) {
          int d=gdepth[l]-gdepth[a];
          //printf("a:%d l:%d d:%d\n",allv[a],allv[l],d);
          h[a].PB(MP(l,d));
          h[l].PB(MP(a,d));
          uf.funion(a,l);
        }
      }
    }

    int hsz=h.size();
    using pqt=pair<pii,int>;
    priority_queue<pqt,vector<pqt>,greater<pqt> > pq;
    for (int x=0;x<hsz;x++) {vtimevir[x]=MP(INF,INF); rem[x]=INF;}
    for (int k=0;k<nv;k++) {
      int x=bins(allv,center[k]);
      //printf("center:%d x:%d\n",center[k],x);
      vtimevir[x]=MP(0,k);
      rem[x]=0;
      pq.push(MP(vtimevir[x],x));
    }
    while(!pq.empty()) {
      auto got=pq.top(); pq.pop();
      int x=got.snd;
      if (got.fst!=vtimevir[x]) continue;
      int time=got.fst.fst;
      int vir=got.fst.snd;
      //printf("v:%d time:%d vir:%d rem:%d\n",allv[x],time,vir,rem[x]);
      for (auto &yd:h[x]) {
        int y=yd.fst,dist=yd.snd;

        int remy=rem[x] - dist;
        int ntime;
        if (remy >= 0) {
          ntime=time;
        } else {
          remy=-remy;
          int needtime=(remy+speed[vir] - 1)/speed[vir];
          ntime=time+needtime;
          remy=needtime * speed[vir] - remy;
        }
        pii ntimevir = MP(ntime,vir);
        if (ntimevir < vtimevir[y]) {
          rem[y]=remy;
          vtimevir[y]=ntimevir;
          //printf("%d -> %d\n",allv[x],allv[y]);
          pq.push(MP(ntimevir,y));
        }
        /* else if (ntimevir==vtimevir[y]) {
          chkmin(rem[y],remy);
          printf("Huh? vy:%d\n",allv[y]);
          exit(1); // Doubt this code is executed lol.
        }*/
      }
    }

    for (int ci=0;ci<nc;ci++) {
      int x=bins(allv,impt[ci]);
      printf("%d ",vtimevir[x].snd+1);
    }
    printf("\n");
  }

}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
  size_t remaining = stdinDataEnd - stdinPos;
  if (remaining < amount) {
     memmove(stdinBuffer, stdinPos, remaining);
     size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
     stdinPos = stdinBuffer;
     stdinDataEnd = stdinBuffer + remaining + sz;
     if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
     *stdinDataEnd = 0;
  }
}

int rint()
{
  readAhead(16);

  int x = 0;
  bool neg = false;
  while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
  if (*stdinPos == '-') {
     ++stdinPos;
     neg = true;
  }

  while (*stdinPos >= '0' && *stdinPos <= '9') {
     x *= 10;
     x += *stdinPos - '0';
     ++stdinPos;
  }

  return neg ? -x : x;
}
char rch()
{
  readAhead(16);
  while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
  char ans=*stdinPos;
  ++stdinPos;
  return ans;
}
long long rlong()
{
  readAhead(32);

  long long x = 0;
  bool neg = false;
  while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
  if (*stdinPos == '-') {
     ++stdinPos;
     neg = true;
  }

  while (*stdinPos >= '0' && *stdinPos <= '9') {
     x *= 10;
     x += *stdinPos - '0';
     ++stdinPos;
  }

  return neg ? -x : x;
}