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
const ll INF=1LL<<60;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=1e5+4;

const int mx=mn;
int ufParent[mx];
void ufinit(int n) {
  for (int x=1;x<=n;x++) {
    ufParent[x]=x;
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
  if (rand()&1) swap(xr,yr);
  ufParent[xr] = yr;
}

bool isportal[mn];
vector<pii> g[mn];
typedef ll DISTT;
DISTT vdist[mn];
typedef pair<DISTT,int> pdi;
DISTT dij1(int init, int n) {
  priority_queue<pdi,vector<pdi>,greater<pdi> > pq;
  for (int x=1;x<=n;x++) vdist[x]=INF;
  vdist[init]=0; pq.push(MP(0,init));
  while(!pq.empty()) {
    auto got=pq.top(); pq.pop();
    DISTT dist=got.fst; int x=got.snd;
    if (dist>vdist[x]) continue;
    if (isportal[x]) return dist;
    for (auto &gg:g[x]) {
      int y=gg.fst,cost=gg.snd;
      DISTT ndist=dist+cost;
      if (ndist<vdist[y]) {
        vdist[y]=ndist;
        pq.push(MP(ndist,y));
      }
    }
  }
  assert(0);
}

int vbelong[mn];
typedef pair<DISTT,pii> pdii;
DISTT dij2(int n) {
  priority_queue<pdii,vector<pdii>,greater<pdii> > pq;
  for (int x=1;x<=n;x++) {
    if (isportal[x]) {
      vdist[x]=0;
      vbelong[x]=x;
      pq.push(MP(0,MP(x,x)));
    }
    else vdist[x]=INF;
  }
  while(!pq.empty()) {
    auto got=pq.top(); pq.pop();
    DISTT dist=got.fst; int x=got.snd.fst; int belong=got.snd.snd;
    if (dist>vdist[x]) continue;
    for (auto &gg:g[x]) {
      int y=gg.fst,cost=gg.snd;
      DISTT ndist=dist+cost;
      if (ndist<vdist[y]) {
        vdist[y]=ndist;
        vbelong[y]=belong;
        pq.push(MP(ndist,MP(y,belong)));
      }
    }
  }
  vector<pair<DISTT,pii> > vv;
  for (int x=1;x<=n;x++) {
    //printf("x:%d dist:%lld b:%d\n",x,vdist[x],vbelong[x]);
    for (auto &gg:g[x]) {
      int y=gg.fst, cost=gg.snd;
      if (y<x) continue;
      if (vbelong[x]==vbelong[y]) continue;
      DISTT totalcost=cost+vdist[x]+vdist[y];
      vv.PB(MP(totalcost,MP(vbelong[x],vbelong[y])));
    }
  }
  sort(vv.begin(),vv.end());
  ll final=0;
  for (auto &w:vv) {
    ll cost=w.fst,x=w.snd.fst,y=w.snd.snd;
    //printf("cost:%lld x:%d y:%d\n",cost,x,y);
    if (ffind(x) != ffind(y)) {
      funion(x, y);
      final+=cost;
    }
  }
  return final;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  ufinit(n);
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint(),w=rint();
    g[x].PB(MP(y,w));
    g[y].PB(MP(x,w));
  }
  int nump=rint();
  int initp=-1;
  for (int i=0;i<nump;i++) {
    int x=rint();
    isportal[x]=true;
    initp=x;
  }
  ll tax=dij1(1, n);
  ll final=dij2(n);
  ll finalfinal=final+tax;
  printf("%lld\n",finalfinal);
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