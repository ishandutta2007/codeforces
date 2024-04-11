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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vtii;typedef vector<pll> vtll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=(3e5)+4;


const int SRC=0,BT=SRC+1;
vi vx,vy; int n;
//pii vt[mn];
int getx(int x) {
  return BT+n+bins(vx,x);
}
int gety(int y) {
  return BT+n+vx.size()+bins(vy,y);
}
int getAll() {
  return BT+n+vx.size()+vy.size();
}

string explain(int x) {
  if (x==0) return "SRC";
  if (x<BT+n) return "teleport " + to_string(x-BT);
  if (x<BT+n+vx.size()) return "x line " + to_string(vx[x-BT-n]);
  return "y line " + to_string(vy[x-BT-n-vx.size()]);
}

vector<pii> g[mn];
int vdist[mn];
void addEdge(int x, int y, int d) {
  //printf("x:%s y:%s d:%d\n",x,y,d);
  g[x].PB(MP(y,d));
  g[y].PB(MP(x,d));
}
void dij(int n) {
  priority_queue<pii,vector<pii>,greater<pii> > pq;
  for (int x=0;x<n;x++) vdist[x]=INF;
  vdist[0]=0; pq.push(MP(0,0));
  while(!pq.empty()) {
    auto got=pq.top(); pq.pop();
    int dist=got.fst,x=got.snd;
    if (dist>vdist[x]) continue;
    for (auto &gg:g[x]) {
      int y=gg.fst,cost=gg.snd;
      ll ndist=dist+(ll)cost;
      if (ndist<vdist[y]) {
        //printf("%s->%s  Dist: %lld\n",explain(x).c_str(),explain(y).c_str(),ndist);
        vdist[y]=ndist;
        pq.push(MP(ndist,y));
      }
    }
  }
}
pii vt[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int unused;
  cin>>unused>>n;
  int sx,sy,fx,fy; cin>>sx>>sy>>fx>>fy;
  map<int,vi> x2t,y2t;
  for (int t=0;t<n;t++) {
    int x,y; cin>>x>>y;
    vx.PB(x); vy.PB(y);
    vt[t]=MP(x,y);
    x2t[x].PB(t);
    y2t[y].PB(t);
  }
  makeunique(vx); makeunique(vy);
  int pxv=-1;
  int px=-1;
  for (auto &w:x2t) {
    int xv=getx(w.fst);
    addEdge(xv,SRC,abs(sx-w.fst));
    if (pxv!=-1) addEdge(xv,pxv,abs(w.fst-px));
    for (auto &t:w.snd) {
      addEdge(xv,BT+t,0);
    }
    px=w.fst;
    pxv=xv;
  }
  int pyv=-1;
  int py=-1;
  for (auto &w:y2t) {
    int yv=gety(w.fst);
    addEdge(yv,SRC,abs(sy-w.fst));
    if (pyv!=-1) addEdge(yv,pyv,abs(w.fst-py));
    for (auto &t:w.snd) {
      addEdge(yv,BT+t,0);
    }
    py=w.fst;
    pyv=yv;
  }
  dij(getAll());
  ll cand=LLONG_MAX;
  for (int t=0;t<n;t++) chkmin(cand,vdist[BT+t]+(ll)abs(fx-vt[t].fst)+(ll)abs(fy-vt[t].snd));
  ll orig=abs(fx-sx)+abs(fy-sy);
  ll final=min(cand,orig);
  printf("%lld\n",final);
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