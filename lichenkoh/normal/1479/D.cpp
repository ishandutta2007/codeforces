#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=300000;

class LcaSparseTable {
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

  void init(vector<vector<int> > &tree, int n, int root) {
    len = 1;
    while ((1 << len) <= n) ++len;
    up = new int*[len];
    for (int i=0;i<len;i++) {up[i]=new int[n]; memset(up[i],0,sizeof(up[i][0])*n);}
    tin = new int[n]; memset(tin,0, sizeof(tin[0])*n);
    tout = new int[n]; memset(tout,0,sizeof(tout[0]*n));
    vdepth = new int[n]; memset(vdepth,0,sizeof(vdepth[0]*n));
    dfs(tree, root, root, 0);
  }

  bool isParent(int parent, int child) {
    return tin[parent] <= tin[child] && tout[child] <= tout[parent];
  }

  int lca(int oa, int ob) {
    // Returns make_pair(LCA, number of edges on shortest path from a to b)
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


int olda[mn];
int uncompa[mn];
int compa[mn];
bitset<mn> hascolor;
int color2compress[mn];
int compress2color[mn];
int nxtcolor[mn];
int prevcolor[mn];

int r2Total[mn];
int vpar[mn];
vi origG[mn];
vvi g;
LcaSparseTable L;

int gdfsnum=-1;
int vtxold2new[mn];
void assignDfsNumber(int x, int p) {
  //printf("x:%d p:%d\n",x,p);
  int xdfsnum=++gdfsnum;
  vtxold2new[x]=xdfsnum;
  //printf("x:%d xdfsnum:%d\n",x,xdfsnum);
  uncompa[xdfsnum]=olda[x];
  for (auto &y:origG[x]) {
    if (y==p) continue;
    int ydfsnum=gdfsnum+1;
    assignDfsNumber(y,x);
    assert(ydfsnum == vtxold2new[y]);
    g[xdfsnum].PB(ydfsnum);
    vpar[ydfsnum]=xdfsnum;
  }
}

struct Query {
  int x,y,lca,l,r;
};
Query vquery[mn];

const int BLK=3*(1<<13);
vector<bitset<BLK> > f;
int vfinal[mn];

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(vfinal,-1,sizeof vfinal);
  int n=rint();
  f.resize(n);
  int qn=rint();
  for (int x=0;x<n;x++) {int r=rint()-1; olda[x]=r; hascolor[r]=true;}
  for (int i=1;i<n;i++) {
    int x=rint()-1; int y=rint()-1;origG[x].PB(y); origG[y].PB(x);
  }
  g.resize(n);
  assignDfsNumber(0,-1);
  L.init(g,n,0);
  int numcompress;
  {
    int compress=0;
    for (int color=0;color<n;color++) {
      if(hascolor[color]) {
        color2compress[color]=compress;
        compress2color[compress]=color;
        compress++;
      }
    }
    numcompress=compress;
  }
  for (int x=0;x<n;x++) compa[x]=color2compress[uncompa[x]];
  {
    int prev=-INF;
    for (int color=0;color<n;color++) {
      if(hascolor[color]) prev=color2compress[color];
      prevcolor[color]=prev;
    }
  }
  {
    int nxt=INF;
    for (int color=n-1;color>=0;color--) {
      if(hascolor[color]) nxt=color2compress[color];
      nxtcolor[color]=nxt;
    }
  }

  for (int qi=0;qi<qn;qi++) {
    int x=vtxold2new[rint()-1];
    int y=vtxold2new[rint()-1];
    if (x>y) swap(x,y);
    int lca=L.lca(x,y);
    //if(lca!=x&&lca==y) {printf("Bad x:%d y:%d lca:%d\n",x,y,lca); exit(0);}
    int l=rint()-1; int r=rint()-1;
    l=nxtcolor[l]; r=prevcolor[r];
    vquery[qi]=Query({x,y,lca,l,r});
    //printf("l:%d r:%d\n",l,r);
    if (l>r) {
      vfinal[qi]=-2;
    }
    if (x==y) {
      if (l<=compa[x]&&compa[x]<=r) vfinal[qi]=compa[x];
      else vfinal[qi]=-2;
    }
  }
  //for (int x=0;x<n;x++) printf("x:%d a:%d\n",x,a[x]);
  for (int baseColor=0;baseColor<numcompress;baseColor+=BLK) {
    f[0].reset();
    {
      int color=compa[0]-baseColor;
      if (0<=color&&color<BLK) {
        f[0][color] = !f[0][color];
      }
    }
    for (int x=1;x<n;x++) {
      int p=vpar[x];
      f[x]=f[p];
      int color=compa[x]-baseColor;
      if (0<=color&&color<BLK) {
        f[x][color] = !f[x][color];
      }
    }
    for (int qi=0;qi<qn;qi++) {
      if (vfinal[qi]!=-1) continue;
      Query const& query=vquery[qi];
      int l=query.l-baseColor,r=query.r-baseColor;
      if (r < 0 || l >= BLK) continue;
      chkmax(l,0);
      int x=query.x,y=query.y;
      if (x==y) continue;
      auto bs = f[x]^f[y];
      int lca=query.lca;
      {
        int lcaColor=compa[lca]-baseColor;
        if (0<=lcaColor&&lcaColor<BLK) {
          bs[lcaColor]=!bs[lcaColor];
        }
      }
      int color;
      if (l==0) color=bs._Find_first();
      else color=bs._Find_next(l-1);
      //printf("Found color:%d\n",color);
      if (color<=min(r,BLK-1)) {
        vfinal[qi]=baseColor+color;
      }
    }
  }
  for (int qi=0;qi<qn;qi++) {
    int ans=vfinal[qi];
    if (ans<0) ans=-1;
    else ans=compress2color[ans]+1;
    printf("%d\n",ans);
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