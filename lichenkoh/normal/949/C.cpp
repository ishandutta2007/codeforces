#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
class SCC {
  static const int N=1e5+4;
public:
  vector<int> g[N];
  int scc[N], nsc, low[N], num[N], mn, st[N], sz;
  void dfs(int p) { low[p] = num[p] = mn++; st[sz++] = p;
    for (int i : g[p]) if (scc[i] == -1) {
      if (num[i] == -1) dfs(i);
      low[p] = min(low[p], low[i]); }
    if (low[p] == num[p]) { while(scc[p] != nsc) scc[st[--sz]] = nsc; ++nsc; } }
  // Set up adj and n first; memset num and scc to -1
  // then after get_scc() you can read scc array and nsc variable
  int get_scc(int n) {
    memset(num,-1,sizeof num); memset(scc,-1,sizeof scc);
    nsc=mn=sz=0; for(int i=1; i<=n; ++i) if (num[i] == -1) dfs(i);
    return nsc;
  }
  int vcnt[N];
  void getCount(int n) {
    for (int x=1;x<=n;x++) vcnt[scc[x]]++;
  }
  vi sccid2vtx[N];
  set<int> sccGraph[N];
  int condensation(int n) {
    for (int x=1;x<=n;x++) sccid2vtx[scc[x]].PB(x);
    for (int x=1;x<=n;x++) {
      for (auto &y:g[x]) {
        if (scc[y]!=scc[x]) sccGraph[scc[x]].insert(scc[y]);
      }
    }
    return nsc;
  }
};
SCC cs;
const int mn=1e5+4;
set<int> gg[mn];
int u[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint(),h=rint();
  for (int c=1;c<=n;c++) {
    u[c]=rint();
  }
  for (int i=0;i<m;i++) {
    int a=rint(),b=rint();
    if (u[b]==(u[a]+1)%h) {
      gg[a].insert(b);
    }
    if (u[a]==(u[b]+1)%h) {
      gg[b].insert(a);
    }
  }
  for (int x=1;x<=n;x++) {
    for (auto &y:gg[x]) cs.g[x].PB(y);
  }
  cs.get_scc(n);
  int nsc=cs.condensation(n);
  pii ans=MP(INF,INF);
  for (int sccid=0;sccid<nsc;sccid++) {
    if (cs.sccGraph[sccid].size()==0) {
      chkmin(ans,MP((int)cs.sccid2vtx[sccid].size(),sccid));
    }
  }
  printf("%d\n",ans.fst);
  for (auto &w:cs.sccid2vtx[ans.snd]) {
    printf("%d ",w);
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