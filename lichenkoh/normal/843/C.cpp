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



const int mn=2e5+2;
vector<int> g[mn];
vi gfoundCentroid;
int getCentroid(int u,int p,int n) {
  int cnt = 1;
  bool goodCenter = true;
  for (auto v : g[u]) {
    if (v == p) continue;
    int size = getCentroid(v, u, n);
    goodCenter &= size <= n / 2;
    cnt += size;
  }
  goodCenter &= n - cnt <= n / 2;
  if (goodCenter) gfoundCentroid.PB(u);
  return cnt;
}
vector<pii> gdepthv;
int vparent[mn];
void dfs(int x, int p, int depth) {
  vparent[x]=p;
  gdepthv.PB(MP(depth,x));
  for (auto &y:g[x]) {
    if (y==p) continue;
    dfs(y,x,depth+1);
  }
}
vector<pair<int,pii> > gmoves;
inline void mov(int x, int y, int yp) {
  if (y!=yp&&x!=-1) {
    gmoves.PB(MP(x,MP(y,yp)));
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n-1;i++) {
    int u=rint(),v=rint();
    g[u].PB(v); g[v].PB(u);
  }
  getCentroid(1,-1,n);
  assert(gfoundCentroid.size()<=2);
  assert(gfoundCentroid.size()>=1);
  for (auto &centroid: gfoundCentroid) {
    for (auto &root:g[centroid]) {
      int lastCh=root;
      bool found=0;
      for (auto &w:gfoundCentroid) {
        if (w==root) found=1;
      }
      if (!found) {
        gdepthv.clear();
        dfs(root,centroid,0);
        sort(gdepthv.begin(),gdepthv.end(),greater<pii>());
        for (auto &w:gdepthv) {
          int x=w.snd;
          if (x==root) continue;
          mov(centroid,lastCh,x);
          lastCh=x;
          mov(x,vparent[x],root);
        }
      }
      mov(centroid,lastCh,root);
    }
  }
  printf("%d\n",(int)gmoves.size());
  for (auto &w:gmoves) {
    printf("%d %d %d\n",w.fst,w.snd.fst,w.snd.snd);
  }
}