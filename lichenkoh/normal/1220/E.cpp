#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
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
const int mx=(2e5)+2;
const int MAXN=mx;
int wt[mx];
class UnionFind {
  typedef pair<ll,int> UFTYPE;
public:
  UFTYPE ufIdentity = MP(0,0);
  inline UFTYPE combine(UFTYPE x, UFTYPE y) {
    return MP(x.fst+y.fst,x.snd+y.snd);
  }
  inline UFTYPE getInitialValue(int x) {
    return MP(wt[x],1);
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


int cutvertex[MAXN],low[MAXN],number[MAXN],parent[MAXN],I;
vi a[MAXN]; // adjacency list
vpii bridge; vector<vpii> component; //biconn-cmps
stack<pii> s; stack<int> roots, verts;
bool inS[MAXN]; vvi tecomp;  //2-edge conn cmps
void biconnected(int u){
  low[u] = number[u] = ++I; int child = 0;
  roots.push(u); verts.push(u); inS[u] = true;
  for (auto i = 0u; i < a[u].size(); i++) {
    int v = a[u][i];
    if (!number[v]) {
      s.push(make_pair(u,v)); parent[v] = u, child++;
      biconnected(v); low[u] = min(low[u], low[v]);
      if(parent[u]!=-1 && low[v]>=number[u]) cutvertex[u] = 1;
      if(low[v]>number[u]) bridge.push_back(make_pair(u,v)), s.pop();
      else if(low[v]==number[u]) {
        component.resize(component.size()+1);
        while(s.top()!=make_pair(u,v) && s.top() != make_pair(v,u))
          component.back().push_back(s.top()), s.pop();
        component.back().push_back(make_pair(u,v)); s.pop(); } }
    else if(number[v]<number[u] && v!=parent[u]){
      low[u] = min(low[u], number[v]), s.push(make_pair(u,v));
      while (number[roots.top()] > number[v]) roots.pop(); } }
  if (u == roots.top()) { tecomp.push_back(vi());
    while (true) {
      int w = verts.top(); verts.pop(); inS[w] = false;
      tecomp.back().push_back(w); if (u == w) break; }
    roots.pop(); }
  if(parent[u]==-1 && child>=2) cutvertex[u]=1; }
void doit(int n) {
  I = 0; component.clear(),bridge.clear(),tecomp.clear();
  memset(number,0,sizeof(number));
  memset(cutvertex,0,sizeof(cutvertex));
  memset(parent,0,sizeof(parent));
  memset(inS,0,sizeof(inS));
  for(int i=0; i < n; i++) if(!number[i]) parent[i]=-1, biconnected(i); }

void makeunique(vector<int> &vx) {
  if (vx.size()==0) return;
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}

UnionFind uf;
vector<vector<int> > h;
void makeCompressedGraph(int n) {
  h.resize(n);
  uf.init(n);
  for (auto &te:tecomp) {
    //for (auto &w:te) printf("%d ",w+1);
    //printf("\n");
    for (int i=1;i<te.size();i++) {
      uf.funion(te[0],te[i]);
    }
    //pair<ll,int> dat=uf.getData(uf.ffind(te[0]));
    //printf("ufdat:%lld %d\n",dat.fst,dat.snd);
  }
  
  for (int x=0;x<n;x++) {
    for (auto &y:a[x]) {
      if (x<y) {
        int rx=uf.ffind(x),ry=uf.ffind(y);
        if (rx!=ry) {
          h[rx].PB(ry);
          h[ry].PB(rx);
        }
      }
    }
  }
  for (int x=0;x<n;x++) makeunique(h[x]);
}


pair<pair<ll,bool>,ll> dfs(int x, int p) { // fst-> biggest with return. snd->biggest without return
  pair<pair<ll,bool>,ll> ans=MP(MP(0,false),0);
  ll hinoret=0;
  for (auto &y:h[x]) {
    if (y==p) continue;
    pair<pair<ll,bool>,ll> got=dfs(y,x);
    ll gotfst=0;
    if (got.fst.snd) {
      ans.fst.snd=true;
      gotfst=got.fst.fst;
      ans.fst.fst+=gotfst;
      ans.snd+=gotfst;
    }
    chkmax(hinoret,got.snd-gotfst);
  }
  ans.snd+=hinoret;
  pair<ll,ll> dat=uf.getData(x);
  ll xwt=dat.fst; bool xcyc=(dat.snd>=2);
  if (ans.fst.snd || xcyc) {
    ans.fst.fst+=xwt;
    ans.fst.snd = true;
  }
  ans.snd+=xwt;
  if(ans.fst.snd) chkmax(ans.snd,ans.fst.fst);
  //printf("x:%d ret:%lld no:%lld\n",1+x,ans.fst,ans.snd);
  return ans;
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int m=rint();
  for (int x=0;x<n;x++) wt[x]=rint();
  for (int i=0;i<m;i++) {
    int x=rint()-1; int y=rint()-1;
    a[x].PB(y); a[y].PB(x);
  }
  int src=rint()-1;
  doit(n);
  makeCompressedGraph(n);
  pair<pair<ll,bool>,ll> ans=dfs(uf.ffind(src),-1);
  printf("%lld\n",ans.snd);

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