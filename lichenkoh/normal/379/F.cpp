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

const int MK=3;
template <typename LST> struct LimitedVec  {
  LST a[MK];
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
};
//typedef struct LimitedVecStruct LimitedVec;



const int mn=1e6+8;
LimitedVec<int> g[mn];
bool iscentroid[mn];
int getCentroid(int u,int p,int n) {
    int cnt = 1;
    bool goodCenter = true;
    for (auto w : g[u]) {
      int v=w;
      if (v == p||iscentroid[v]) continue;
      int res = getCentroid(v, u, n);
      if (res >= 0)
        return res;
      int size = -res;
      goodCenter &= size <= n / 2;
      cnt += size;
    }
    goodCenter &= n - cnt <= n / 2;
    return goodCenter ? u : -cnt;
  }
int getSubtreeSize(int x,int p) {
  int selfSubtreeSize=1;
  for (auto &w:g[x]) {
    int y=w;
    if (y==p||iscentroid[y]) continue;
    int childSubtreeSize=getSubtreeSize(y,x);
    selfSubtreeSize+=childSubtreeSize;
  }
  return selfSubtreeSize;
}

/* Custom functions go here */
typedef ll ms;
int x2ts[mn];
ms ts2d[mn];
int ts2dsz;
int gid;
const int SHF=4;
const int MSK=(1<<SHF)-1;
inline int getid(int x) {
  return x&MSK;
}
inline int getdepth(int x) {
  return x>>SHF;
}
void getts2depth(int x, int p, int depth, int mts) {
  if (iscentroid[x]) return;
  chkmax(mts, x2ts[x]);
  ts2d[ts2dsz++]=((ll)mts<<32)|(depth<<SHF)|gid;
  for (auto &y:g[x]) {
    if (y==p) continue;
    getts2depth(y,x,depth+1,mts);
  }
}
int best[3];
const int mq=500002;
int vfinal[mq];
/* Custom functions end here */
void fullCentroidDecomposition(int initv,int p,int n) {
  LimitedVec<pii> subtreeRootsWithSizes;
  subtreeRootsWithSizes.sz=0;
  int centroid=getCentroid(initv,p,n);
  //subtreeRootsWithSizes.sz=0;
  for (auto &w:g[centroid]) {
    int y=w;
    if (y!=p&&(!iscentroid[y])) {
      int sz=getSubtreeSize(y,centroid);
      subtreeRootsWithSizes.PB(MP(y,sz));
    }
  }
  /* Custom code starts here. Should take linear time. Do not consider nodes with iscentroid=true, or nodes beyond them.*/
  ts2dsz=0;
  for (int id=0;id<g[centroid].sz;id++) {
    int y=g[centroid].a[id];
    gid=id+1;
    getts2depth(y,centroid,1,x2ts[centroid]);
  }
  sort(ts2d,ts2d+ts2dsz);
  memset(best,0,sizeof best);
  for (int i=0;i<ts2dsz;i++) {
    ll got=ts2d[i];
    int gotfst=got>>32;
    int gotsnd=got&0xffffffff;
    int gotid=getid(gotsnd);
    //if (centroid==6) printf("centroid:%d id:%d ts:%d depth:%d\n",centroid,gotid,gotfst,getdepth(gotsnd));
    for (int k=2;k>=1;k--) {
      if (gotid!=getid(best[k])) {
        chkmax(vfinal[gotfst], getdepth(gotsnd)+getdepth(best[k]));
        /*if (got.ts==1&&got.depth+best[k].depth==4) {
          printf("centroid:%d id:%d ts:%d depth:%d\n",centroid,got.id,got.ts,got.depth);
          printf("bestk id:%d ts:%d depth:%d\n",centroid,best[k].id,best[k].ts,best[k].depth);
        }*/
      }
    }
    best[0]=gotsnd;
    sort(best,best+3);
    if (getid(best[1])==getid(best[2])) best[1]=best[0];
  }
  /* Custom code ends here. Continue decomposing subtree.*/
  iscentroid[centroid]=true;
  for (auto &got:subtreeRootsWithSizes) {
    fullCentroidDecomposition(got.first,centroid,got.second);
  }
}
int vq[mq];
bool nonleaf[mn];
void ae(int s, int t) {
  if (nonleaf[t]) {
    g[s].PB(t);
    g[t].PB(s);
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int q=rint();
  for (int t=1;t<=q;t++) {
    int x=rint();
    vq[t]=x;
    nonleaf[x]=true;
  }
  x2ts[1]=0;
  for (int y=2;y<=4;y++) {
    ae(1,y);
  }
  int n=4;
  for (int t=1;t<=q;t++) {
    int x=vq[t];
    x2ts[x]=t;
    for (int y=n+1;y<=n+2;y++) {
      ae(x,y);
    }
    n+=2;
  }
  fullCentroidDecomposition(1,-1,1+q);
  int ans=0;
  for (int t=1;t<=q;t++) {
    chkmax(ans,vfinal[t]);
    printf("%d\n",ans+2);
  }
}