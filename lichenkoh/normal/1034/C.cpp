#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=1e6+4;
ll a[mn]; int oa[mn];
uint b[mn];
int p[mn];
int n;
uint hia=0;
bool fint(uint t) {
  if ((uint)hia>(uint)t) return false;
  for (int x=1;x<n;x++) b[x]=oa[x];
  for (int x=0;x<=n-2;x++) {
    int par=p[x];
    if (b[x]<t) {
      b[par]+=b[x];
      if (b[par]>t) return false;
      //printf("Push up: b[%d]=%lld\n",par,b[par]);
    }
  }
  return (b[n-1]==t);
}
bool f(ll t) {
  if (t + hia < UINT_MAX) return fint(t);
  for (int x=1;x<n;x++) a[x]=oa[x];
  for (int x=0;x<=n-2;x++) {
    int par=p[x];
    if (a[x]<t) {
      a[par]+=a[x];
      if (a[par]>t) return false;
      //printf("Push up: a[%d]=%lld\n",par,a[par]);
    }
  }
  return (a[n-1]==t);
}



vector<pair<ll,int> > pliv;
void compress(vector<ll> &v) {
  sort(v.begin(),v.end());
  int cnt=1;
  for (int i=1;i<v.size();i++) {
    if (v[i]!=v[i-1]) {
      pliv.PB(MP(v[i-1],cnt));
      cnt=1;
    }
    else cnt++;
  }
  if (cnt) pliv.PB(MP(v.back(),cnt));
  /*for (auto &w:pliv) {
    printf("(%lld, %d)\n",w.fst,w.snd);
  }*/
}
ll gt;
int gocc;
void countOcc(int vl, int vr, ll kl, ll kr) {
  // Counts occurrences in [vl,vr] and [kl,kr]
  // Assured that if x in v[vl..vr] is a multiple of t, then kl*t <= x <= kr*t
  //printf("vl:%d vr:%d kl:%d kr:%d\n",vl,vr,kl,kr);
  if (vl>vr||kl>kr) return;
  if (vl==vr) {
    if (kl==kr) {
      if (pliv[vl].fst==kl) gocc+=pliv[vl].snd;
    }
    else {
      if (0==pliv[vl].fst%gt) gocc+=pliv[vl].snd;
    }
    return;
  }
  int vmid=(vl+vr)/2;
  if (kl==kr) {
    if (pliv[vmid].fst >= kl) {
      countOcc(vl,vmid,kl,kl); return;
    }
    else {
      countOcc(vmid+1,vr,kl,kl);  return;
    }
  }
  else {
    ll kmid=(pliv[vmid].fst/gt)*gt;
    countOcc(vl,vmid,kl,kmid);
    countOcc(vmid+1,vr,kmid+gt,kr);
  }
}
ll suma=0;
bool can(int g, ll d) {
  gt=d;
  gocc=0;
  countOcc(0,pliv.size()-1,d,suma);
  //printf("d:%lld g:%d gocc:%d\n",d,g,gocc);
  return gocc==g;
}
const int slim=1e6/180;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int y=1;y<=n;y++) {
    uint got=rint();
    chkmax(hia,got);
    oa[n-y]=got;
    suma+=got;
  }
  a[0]=b[0]=oa[0];
  for (int y=2;y<=n;y++) {
    p[n-y]=n-rint();
  }
  //for (int x=0;x<n;x++) printf("x:%d p:%d\n",x,p[x]);
  map<ll,int, greater<ll> > h;
  {
    // If numgroups > n/2, that implies at least one a[x] is in its own group. That must be the largest a[x].
    ll d=hia;
    if (f(d)) h[d]=0;
  }
  assert(slim>=2);
  for (int g=n/2;g>=slim;g--) {
    if (suma%g==0) {
      ll d=suma/g;
      if (f(d)) h[d]=0;
    }
  }

  vector<ll> sumsubtree(n);
  for (int x=0;x<n;x++) sumsubtree[x]=oa[x];
  for (int x=0;x<=n-2;x++) sumsubtree[p[x]]+=sumsubtree[x];
  //for (int x=1;x<=n;x++) printf("sub[%d]=%lld\n",x,sumsubtree[n-x]);
  compress(sumsubtree);
  for (int g=slim-1;g>=2;g--) {
    if (suma%g==0) {
      ll d=suma/g;
      if (d>=hia&&can(g,d)) h[d]=0;
    }
  }
  h[suma]=1;
  int final=0;
  for (auto it=h.begin();it!=h.end();++it) {
    int add=it->snd;
    //printf("it->fst:%d add:%d\n",it->fst,add);
    final+=add; if (final>=MOD) final-=MOD;
    auto jt=it; ++jt;
    for (;jt!=h.end();++jt) {
      if (it->fst%(jt->fst)!=0) continue;
      int ans=jt->snd+add;
      //printf("add:%d jt->fst:%d\n",add,jt->fst);
      if (ans>=MOD) ans-=MOD;
      jt->snd=ans;
    }
  }
  printf("%d\n",final);
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