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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

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

const int MAXN = 200;
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
  dinic_graph[a].push_back ((int) dinic_edge.size());
  dinic_edge.push_back (e1);
  dinic_graph[b].push_back ((int) dinic_edge.size());
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

const int MAXP=2e5+4;
bitset<MAXP+1> sieve_array;
int sp[MAXP+1];
void sieve() {
  sieve_array.set();
  for (int i = 0; i <= MAXP; i++) {
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
      chkmin(sp[i],i);
    }
  }
}

const int mn=102;
typedef pair<int,int> pii;
bool cmp(const pii &x, const pii &y) {
  return x.fst%2<y.fst%2;
}
int gk,gn;
int p[mn],c[mn],l[mn];
bool f(int imid) {
  int big1=-1;
  vector<pii> v;
  for (int i=0;i<gn;i++) {
    if (l[i]>imid) continue;
    if (c[i]==1) chkmax(big1,p[i]);
    else {
      v.PB(MP(c[i],p[i]));
    }
  }
  if (big1!=-1) v.PB(MP(1,big1));
  sort(v.begin(),v.end(),cmp);
  int vsz=v.size();
  //printf("imid:%d vsz:%d\n",imid,vsz);
  int src=vsz,dest=vsz+1;
  int sumall=0;
  for (int x=0;x<vsz;x++) {
    
    int cx=v[x].fst,px=v[x].snd;
    //printf("c[x]:%d p[x]:%d\n",cx,px);
    sumall+=px;
    if (cx%2==0) add_edge(src,x,px);
    else add_edge(x,dest,px);
  }
  for (int x=0;x<vsz;x++) {
    for (int y=x+1;y<vsz;y++) {
      int cx=v[x].fst,cy=v[y].fst;
      if (sieve_array[cx+cy]) {
        add_edge(x,y,INF);
      }
    }
  }
  int flow=dinic(src,dest,dest+1);
  //printf("sumall:%d - flow:%d = %d\n",sumall,flow,sumall-flow);
  dinic_clear(dest+1);
  if (sumall-flow>=gk) return 1;
  else return 0;
}
int main()
{
  sieve();
  ios_base::sync_with_stdio(false); cin.tie(0);
  gn=readInt(),gk=readInt();
  for (int i=0;i<gn;i++) {
    p[i]=readInt(),c[i]=readInt(),l[i]=readInt();
  }
  int imin=1,imax=gn+1;
  while(imin<imax) {
    int imid=(imin+imax)/2;
    if (!f(imid)) imin=imid+1;
    else imax=imid;
  }
  if (imin==gn+1) printf("-1\n");
  else printf("%d\n",imin);
}
//a