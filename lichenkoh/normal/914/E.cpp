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
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

class S {
public:
  int v;
  ll cur;
  ll past;
  int id;
  S(int v, ll cur, ll past, int id) : v(v),cur(cur),past(past),id(id) {}
};


const int mn=2e5+4;
const int mk=20;
const int mz=1<<mk;
//int col2numvtx[mn];
int st[mn],ft[mn],ver[mn],big[mn],sz[mn],vpar[mn];
ll vfinal[mn];
vector<S> msk2s[mz];
int v2msk[mn];
int inp[mn];
vector<int> g[mn];
vector<int> vwant;

template <typename LST> struct LimitedVec  {
  LST a[2*mn];
  int sz;
  void push_back(LST val) {
    a[sz++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[sz];
  }
  void clear() {
    sz=0;
  }
};

LimitedVec<int> pending;
ll globcount=0;
int gid=1;
void flushpending() {
  for (auto &v:pending) {
    //printf("flush:%d msk:%d\n",v,v2msk[v]);
    msk2s[v2msk[v]].PB(S(v,0,0,gid));
  }
  pending.clear();
}

void addedge(int v, int par, ll cnt) {
  //if (cnt) printf("addedge v:%d par:%d parpar:%d cnt:%d\n",v,par,vpar[par],cnt);
  vfinal[v]+=2*cnt;
  vfinal[par]-=cnt;
  vfinal[vpar[par]]-=cnt;
}

void add(int v, int center, int centerpar) {
  int premsk=v2msk[v]^inp[center];
  int cnt=0;
  for (auto &want:vwant) {
    int msk=want^premsk;
    auto &q=msk2s[msk];
    int qsz=q.size();
    //if(v==1&&want==0) printf("v:%d Looking for:%d. qsz:%d\n",v,msk,qsz);
    if (qsz) {
      cnt+=qsz;
      auto &s=q.back();
      if (s.id!=gid) {
        s.past+=s.cur;
        s.cur=0;
        s.id=gid;
      }
      s.cur++;
      globcount+=qsz;
    }
  }
  //if (cnt)printf("In add: v:%d center:%d cnt:%d\n",v,center,cnt);
  addedge(v,center,cnt);
  pending.PB(v);
}

void rm(int v, int center, int centerpar) {
  int msk=v2msk[v];
  auto &q=msk2s[msk];
  int sz=q.size();
  if (sz==0) return;
  //printf("rm:%d\n",v);
  ll cursum=0;
  ll pastsum=0;
  for (int i=sz-1;i>=0;i--) {
    auto &s=q[i];
    //printf("Process:%d. s.cur:%d s.past:%d\n",s.v,s.cur,s.past);
    if (s.id!=gid) {s.past+=s.cur; s.cur=0;}
    cursum+=s.cur;
    pastsum+=s.past;
    //if (cursum||pastsum)printf("In rm: v:%d center:%d. cur:%d past:%d\n",s.v,center,cursum, pastsum);
    addedge(s.v,center,cursum);
    vfinal[s.v]+=2*pastsum;
  }
  q.clear();
}


void dfs(int v, int par, bool keep){
  int bigChild=big[v];
  for(auto u : g[v]) {
    if(u != par && u != bigChild) {
      dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    }
  }
  if(bigChild != -1) {
    dfs(bigChild, v, 1);  // bigChild marked as big and not cleared from cnt
  }
  //printf("Begin:%d\n",v);
  for(auto u : g[v]) {
    if(u != par && u != bigChild) {
      for(int p = st[u]; p < ft[u]; p++) add(ver[p],v,par);
      flushpending();
    }
  }
  add(v,v,par);
  flushpending();
  //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
  if(keep == 0) {
    //printf("clear:%d\n",v);
    for(int p = st[v]; p < ft[v]; p++) rm(ver[p],v,par);
    globcount=0;
  }
  else {
    //printf("v:%d par:%d both -= globcount:%lld\n",v,par,globcount);
    vfinal[v]-=globcount;
    vfinal[par]-=globcount;
    globcount=0;
    ++gid;
  }
}
int dfs_time=0;
void pre_dfs(int v, int p){
  vpar[v]=p;
  st[v] = dfs_time++;
  ver[ st[v] ] = v;
  sz[v] = 1, big[v] = -1;
  for(auto u : g[v]){
    if (u==p) continue;
    pre_dfs(u,v);
    sz[v] += sz[u];
    if(big[v] == -1 || sz[u] > sz[ big[v] ])
        big[v] = u;
  }
  ft[v] = dfs_time;
}
void init(int x, int p, int msk) {
  msk^=inp[x];
  v2msk[x]=msk;
  for (auto &y:g[x]) {
    if (y==p) continue;
    init(y,x,msk);
  }
}

ll vout[mn];

ll finalize(int x, int p) {
  ll ans=vfinal[x];
  for (auto &y:g[x]) {
    if (y==p) continue;
    ans+=finalize(y,x);
  }
  return vout[x]=ans;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  vwant.PB(0);
  for (int i=0;i<mk;i++) vwant.PB(1<<i);
  int n=rint();
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  for (int i=1;i<=n;i++) inp[i]=1<<(rch()-'a');
  init(1,0,0);
  pre_dfs(1,0);
  dfs(1,0,false);
  finalize(1,0);
  //for (int x=1;x<=n;x++) printf("%d ",vfinal[x]);
  //printf("\n");
  for (int x=1;x<=n;x++) printf("%lld ",vout[x]/2+1);
  printf("\n");
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