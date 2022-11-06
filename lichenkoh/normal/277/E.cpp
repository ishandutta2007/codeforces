#include <bits/stdc++.h>
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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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



typedef long long ll;
typedef pair<ll,ll> pll;

const ll maxnodes = 2*400+4;

ll nodes = maxnodes;
ll prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

struct Edge {
  ll to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(ll s, ll t, ll cap, ll cost) {
  //printf("%lld %lld %lld %lld\n",s,t,cap,cost);
  Edge a = {t, 0, cap, cost, graph[t].size()};
  Edge b = {s, 0, 0, -cost, graph[s].size()};
  graph[s].push_back(a);
  graph[t].push_back(b);
}

void bellmanFord(ll s, ll dist[]) {
  fill(dist, dist + nodes, LLONG_MAX);
  dist[s] = 0;
  ll qt = 0;
  q[qt++] = s;
  for (ll qh = 0; (qh - qt) % nodes != 0; qh++) {
    ll u = q[qh % nodes];
    inqueue[u] = false;
    for (ll i = 0; i < (ll) graph[u].size(); i++) {
      Edge &e = graph[u][i];
      if (e.cap <= e.f) continue;
      ll v = e.to;
      ll ndist = dist[u] + e.cost;
      if (dist[v] > ndist) {
        dist[v] = ndist;
        if (!inqueue[v]) {
          inqueue[v] = true;
          q[qt++ % nodes] = v;
        }
      }
    }
  }
}

pll minCostFlow(ll s, ll t, ll maxf) {
  // bellmanFord can be safely commented if edges costs are non-negative
  //bellmanFord(s, pot);
  ll flow = 0;
  ll flowCost = 0;
  while (flow < maxf) {
    priority_queue<pll, vector<pll>, greater<pll> > q;
    q.push(MP(0LL,s));
    fill(prio, prio + nodes, LLONG_MAX);
    prio[s] = 0;
    curflow[s] = LLONG_MAX;
    while (!q.empty()) {
      pll cur = q.top();
      ll d = cur.first;
      ll u = cur.second;
      q.pop();
      if (d != prio[u])
        continue;
      for (ll i = 0; i < (ll) graph[u].size(); i++) {
        Edge &e = graph[u][i];
        ll v = e.to;
        if (e.cap <= e.f) continue;
        ll nprio = prio[u] + e.cost + pot[u] - pot[v];
        if (prio[v] > nprio) {
          prio[v] = nprio;
          q.push(MP(nprio,v));
          prevnode[v] = u;
          prevedge[v] = i;
          curflow[v] = min(curflow[u], e.cap - e.f);
        }
      }
    }
    if (prio[t] == LLONG_MAX)
      break;
    for (ll i = 0; i < nodes; i++)
      pot[i] += prio[i];
    ll df = min(curflow[t], maxf - flow);
    flow += df;
    for (ll v = t; v != s; v = prevnode[v]) {
      Edge &e = graph[prevnode[v]][prevedge[v]];
      e.f += df;
      graph[v][e.rev].f -= df;
      flowCost += df * e.cost;
    }
  }
  return make_pair(flow, flowCost);
}
const int mn=404;
int px[mn],py[mn];
const ll C=1000LL*1000LL*1000LL*1000LL;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=0;i<n;i++) {
    px[i]=rint(),py[i]=rint();
  }
  int src=2*n,dest=2*n+1;
  for (int x=0;x<n;x++) {
    addEdge(src,x,1,0);
    addEdge(x+n,dest,2,0);
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (py[i]<py[j]) {
        int dx=px[i]-px[j];
        int dy=py[i]-py[j];
        int dist2=dx*dx+dy*dy;
        ld dist=sqrt((ld)dist2);
        ll cost=round(dist*C);
        addEdge(i,j+n,1,cost);
      }
    }
  }
  int needflow=n-1;
  pll got=minCostFlow(src, dest, needflow);
  if (got.fst!=needflow) {
    printf("-1\n"); return 0;
  }
  else {
    ll gotcost=got.snd;
    ld final=((ld)gotcost)/C;
    printf("%.10f\n",(double)final);
  }
}