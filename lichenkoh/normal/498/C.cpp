#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<int,int> pll;
typedef vector<int> vll;

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

int readInt()
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

const int MAXP=1e6;
bool sieve_array[MAXP+1];
int sp[MAXP+1];
vector<int> gpv;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    sp[i]=INF;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = sqrt(MAXP)+1;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        chkmin(sp[j],i);
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      chkmin(sp[i],i);
    }
  }
}
map<int,int> factorize(int x) {
  map<int,int> h;
  while(x>=MAXP) {
    bool found=false;
    for (auto &p:gpv) {
      if (p*p>x) break;
      int cnt=0;
      while ((x%p)==0) {
        x/=p;
        cnt++;
      }
      if (cnt>0) {
        h[p]+=cnt;
        found=true;
      }
    }
    if (x<MAXP) break;
    if (!found) break;
  }
  if (x<MAXP) {
    while(x>1) {
    int p=sp[x];
    x/=p;
    h[p]++;
    }
  }
  if (x>1) h[x]++;
  return h;
}

const int MAXN = 204;
struct edge {
  int a, b, cap, flow;
};
/*
Set
dinic_numnodes: number of nodes
dinic_src: Source vertex
dinic_dest: Target vertex
No need to initialize anything else. Run ge.clear() and dinic_graph.clear() between runs.
*/
int dinic_numnodes, dinic_src, dinic_dest, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> dinic_edge;
vector<int> dinic_graph[MAXN];
 
void add_edge (int a, int b, int cap) {
  //printf("%lld->%lld:%lld\n",a,b,cap);
  edge e1 = { a, b, cap, 0 };
  edge e2 = { b, a, 0, 0 };
  dinic_graph[a].push_back ((ll) dinic_edge.size());
  dinic_edge.push_back (e1);
  dinic_graph[b].push_back ((ll) dinic_edge.size());
  dinic_edge.push_back (e2);
}

bool bfs() {
  int qh=0, qt=0;
  q[qt++] = dinic_src;
  memset (d, -1, dinic_numnodes * sizeof d[0]);
  d[dinic_src] = 0;
  while (qh < qt && d[dinic_dest] == -1) {
    int v = q[qh++];
    for (size_t i=0; i<dinic_graph[v].size(); ++i) {
      int id = dinic_graph[v][i],
        to = dinic_edge[id].b;
      if (d[to] == -1 && dinic_edge[id].flow < dinic_edge[id].cap) {
        q[qt++] = to;
        d[to] = d[v] + 1;
      }
    }
  }
  return d[dinic_dest] != -1;
}
 
int dfs (int v, int flow) {
  if (!flow)  return 0;
  if (v == dinic_dest)  return flow;
  for (; ptr[v]<(ll)dinic_graph[v].size(); ++ptr[v]) {
    int id = dinic_graph[v][ptr[v]],
      to = dinic_edge[id].b;
    if (d[to] != d[v] + 1)  continue;
    int pushed = dfs (to, min (flow, dinic_edge[id].cap - dinic_edge[id].flow));
    if (pushed) {
      dinic_edge[id].flow += pushed;
      dinic_edge[id^1].flow -= pushed;
      return pushed;
    }
  }
  return 0;
}
 
int dinic(int src, int dest, int numnodes) {
  dinic_src = src;
  dinic_dest = dest;
  dinic_numnodes = numnodes;
  int flow = 0;
  for (;;) {
    if (!bfs())  break;
    memset (ptr, 0, dinic_numnodes * sizeof ptr[0]);
    while (int pushed = dfs (dinic_src, INF))
      flow += pushed;
  }
  return flow;
}
void dinic_clear(int numnodes) {
  dinic_edge.clear();
  for (int v=0;v<numnodes;v++) dinic_graph[v].clear(); 
}

const int  mn=102;
map<int,int> fac[mn];
vector<int> g[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
	int n=readInt(),m=readInt();
  set<int> ps;
  for (int i=1;i<=n;i++) {
    int a=readInt();
    fac[i]=factorize(a);
    for (auto &w:fac[i]) ps.insert(w.fst);
  }
  for (int i=0;i<m;i++) {
    int x=readInt(),y=readInt();
    if (x&1) swap(x,y);
    g[x].PB(y);
  }
  int src=0,dest=n+1;
  int final=0;
  for (auto &prime:ps) {
    vector<int> vnodes;
    for (int x=1;x<=n;x++) {
      auto it=fac[x].find(prime);
      if (it==fac[x].end()) continue;
      int flow=it->snd;
      if (x&1) {
        add_edge(x,dest,flow);
        //printf("x:%d flow:%d dest\n",x,flow);
      }
      else {
        add_edge(src,x,flow);
        //printf("x:%d flow:%d src\n",x,flow);
      }
      vnodes.PB(x);
    }
    for (int x=1;x<=n;x++) for (auto &y:g[x]) {
      //printf("x:%d y:%d\n",x,y);
      add_edge(x,y,INF);
    }
    final+=dinic(src,dest,n+5);
    dinic_clear(n+5);
  }
  printf("%d\n",final);
}