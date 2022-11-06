#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}



int n;

vi query(int l, int r) { // sum on interval [l, r]
  vi res;
  if (l>r) return res;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
      res.PB(l++);
    }
    if (r&1) {
      res.PB(--r);
    }
  }
  return res;
}
using vvpii=vector<vpii>;

vll vdist;
vi par;
vvpii g;
void dij(ll init) {
  priority_queue<pll,vector<pll>,greater<pll> > pq;
  vdist[init]=0; pq.push(MP(0,init));
  while(!pq.empty()) {
    auto got=pq.top(); pq.pop();
    ll dist=got.fst,x=got.snd;
    if (dist>vdist[x]) continue;
    for (auto &gg:g[x]) {
      ll y=gg.fst,cost=gg.snd;
      ll ndist=dist+cost;
      if (ndist<vdist[y]) {
        par[y]=x;
        vdist[y]=ndist;
        pq.push(MP(ndist,y));
      }
    }
  }
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n;
  ++n;
  vi a(n),b(n);
  for (int i=1;i<n;i++) {
    cin>>a[i];
  }
  for (int i=1;i<n;i++) {
    cin>>b[i];
  }
  g.resize(3*n);
  for (int i = n - 1; i > 0; --i) {
    {
      int y=i<<1;
      g[i].PB(MP(y,0));
    }
    {
      int y=(i<<1)|1;
      g[i].PB(MP(y,0));
    }
  }
  for (int i=1;i<n;i++) {
    int x=n+i;
    int y=2*n+i+b[i];
    g[x].PB(MP(y,0));
  }
  for (int i=1;i<n;i++) {
    int x=2*n+i;
    int l=i-a[i],r=i;
    for (auto &y:query(l,r)) {
      g[x].PB(MP(y,1));
    }
  }
  vdist.resize(3*n,INF);
  par.resize(3*n,-1);
  ll target=n+0;
  ll src=2*n+(n-1);
  dij(src);
  if (vdist[target] >= INF/2) {
    printf("-1\n");
    exit(0);
  }
  vi rest;
  vi jump;
  ll x=target;
  if (x>=2*n) jump.PB(x);
  else if (n<=x&&x<2*n) rest.PB(x);
  while(x!=src) {
    ll y=par[x];
    x=y;
    if (x>=2*n) jump.PB(x);
    else if (n<=x&&x<2*n) rest.PB(x);
  }
  assert(jump.size()==rest.size());
  int k=jump.size();
  vi vfinal;
  for (int i=k-1;i>=0;i--) {
    int r=rest[i]-n;
    int j=jump[i]-2*n;
    vfinal.PB(r);
  }
  printf("%d\n",k);
  for (auto &ans:vfinal) {
    printf("%d ",ans);
  }
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