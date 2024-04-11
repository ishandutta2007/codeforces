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
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
void makeunique(vector<int> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
/*
vi eulerCycleUndirected(vvi & graph, int u) {
  set<ll> usedEdges;
  int n = graph.size();
  vi curEdge(n);
  vi res;
  dfs(graph, curEdge, usedEdges, res, u);
  reverse(res.begin(),res.end());
  return res;
}

void dfs(vvi & graph, vi & curEdge, set<ll> & usedEdges, vi & res, int u) {
  while (curEdge[u] < graph[u].size()) {
    int v = graph[u][curEdge[u]++];
    if (usedEdges.insert(( ((ll)min(u, v)) << 32) | max(u, v)))
      dfs(graph, curEdge, usedEdges, res, v);
  }
  res.add(u);
}
*/
using Graph = vector<vector<pii> >;
void isconn(Graph const & graph, vector<bool> & seen, int x) {
  if (seen[x]) return;
  seen[x]=true;
  for (auto &y:graph[x]) isconn(graph,seen,y.fst);
}

bool hasEulerCycle(Graph const & graph, int u) {
  for (int x=0;x<graph.size();x++) {if ((int)graph[x].size()%2 != 0) return false;}
  vector<bool> seen(graph.size());
  isconn(graph,seen,u);
  for (int x=0;x<graph.size();x++) if (graph[x].size() && !seen[x]) return false;
  return true;
}

  vi eulerCycleUndirected2(Graph & graph, int u) {
    vi curEdge(graph.size());
    vi res;
    stack<int> stack;
    set<int> usedEdges;
    stack.push(u);
    while (!stack.empty()) {
      u = stack.top(); stack.pop();
      while (curEdge[u] < graph[u].size()) {
        pii e = graph[u][curEdge[u]++];
        int v = e.fst;
        if (usedEdges.insert(e.snd).snd) {
          //printf("stack PB u:%d v:%d\n",u,v);
          stack.push(u);
          u = v;
        }
      }
      //printf("res PB u:%d\n",u);
      res.PB(u);
    }
    reverse(res.begin(),res.end());
    return res;
  }
int getsig(int x, int k) {
  return x&((1<<k) -1);
}
const int mn=(5e5)+4;
int a[mn][2];
int n;
bool f(int k) {
  int q=1<<k;
  Graph g;
  g.resize(q);
  int initu=0;
  for (int i=0;i<n;i++) {
    int x=getsig(a[i][0],k),y=getsig(a[i][1],k);
    initu=x;
    g[x].PB(MP(y,i)); g[y].PB(MP(x,i));
  }
  return hasEulerCycle(g,initu);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int i=0;i<n;i++) {
    a[i][0]=rint(); a[i][1]=rint();
  }
  int imin=0,imax=21;
  while(imin<imax) {
    int imid=(imin+imax)/2;
    if (f(imid)) imin=imid+1;
    else imax=imid;
  }
  int k=imin-1;
  printf("%d\n",k);
  {
    int q=1<<k;
    Graph g;
    g.resize(q);
    map<pii,vector<pii> > h;
    int initu=0;
    for (int i=0;i<n;i++) {
      int x=getsig(a[i][0],k),y=getsig(a[i][1],k);
      initu=x;
      g[x].PB(MP(y,i)); g[y].PB(MP(x,i));
      int rev=0;
      if (x>y) {swap(x,y); rev=1;}
      h[MP(x,y)].PB(MP(i,rev));
      //printf("x:%d y:%d i:%d\n",x,y,i);
    }
    map<pii,int> hi;
    {
      vi res=eulerCycleUndirected2(g,initu);
      assert(res.size()==n+1);
      for (int t=0;t<n;t++) {
        int x=res[t],y=res[t+1];
        int rev=0;
        if (x>y) {swap(x,y); rev=1;}
        pii got=h[MP(x,y)][hi[MP(x,y)]++];
        rev^=got.snd;
        if (!rev) {
          printf("%d %d ", got.fst*2+1,got.fst*2+2);
        } else {
          printf("%d %d ", got.fst*2+2,got.fst*2+1);
        }
      }
      printf("\n");
      exit(0);
    }
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