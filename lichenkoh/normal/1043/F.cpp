#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
template<typename T> void makeunique(vector<T> &v) {
  sort(v.begin(),v.end());
  auto it=unique(v.begin(),v.end());
  v.resize(it-v.begin());
}

const int MAXN=300000+1;
const int MAXP=MAXN;
int sp[MAXP+1];
void sieve() {
  for (int i = 0; i <= MAXP; i++) sp[i]=1<<30;
  int lim = (int)(ceil(sqrt(MAXP)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sp[i]==(1<<30)) {
      for (int j = i+i; j <= MAXP; j+=i) {chkmin(sp[j],i);}
    }
  }
  for (int i=2;i<=MAXP;i++) {
    if (sp[i]==(1<<30)) sp[i]=i;
  }
}
vi factorize(int x) {
  int ox=x;
  vi v;
  while(x>1) {
    int p=sp[x];
    //assert(p<=300000);
    x/=p;
    if (v.size()==0||v.back()!=p) v.PB(p);
  }
  //assert(x==1);
  if (x>1) v.PB(x);
  //for (auto &w:v) printf("%d ",w); printf(" ox:%d\n",ox);
  return v;
}
const int mn=MAXN;
vi vp[mn];
int vprod[mn];
bitset<mn> exists;
int *z2cnt[mn];


template<typename T> void InverseNotFastSubsetConvolution(T *f, int k) {
  // Reverse operation: f_out[S]=sum_{T \superseteq S} f_in[S] (superset instead of subset)
  for (int i=0;i<k;i++) {
    for (int z=(1<<k)-1;z>=0;z--) {
      if (0==(z&(1<<i))) {
        f[z]-=f[z^(1<<i)];
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int _n=rint();
  vi a(_n);
  for (int i=0;i<_n;i++) a[i]=(rint());
  sort(a.begin(),a.end());
  if (a[0]==1) {
    printf("1\n"); exit(0);
  }
  int mx=a.back();
  for (int x=1;x<=mx;x++) {
    vp[x]=factorize(x);
    int y=1;
    for (auto &w:vp[x]) {
      y*=w;
      /*if (y>mx) {
        printf("x:%d y:%d w:%d\n",x,y,w);
      }*/
    }
    vprod[x]=y;
  }
  for (auto &w:a) {
    //printf("w:%d prod:%d\n",w,vprod[w]);
    w=vprod[w];
  }
  makeunique(a);
  mx=a.back();

  int n=a.size();
  for (int prod=1;prod<=mx;prod++) if(vprod[prod]==prod) z2cnt[prod]=new int[1<<vp[prod].size()]();
  int maxk=0;
  for (int i=0;i<n;i++) {
    int x=a[i];
    int prod=vprod[x];
    exists[prod]=true;
    auto &vpx=vp[x];
    int k=vpx.size();
    chkmax(maxk,k);
    int zlim=1<<k;
    for (int z=0;z<zlim;z++) { // Add signature to all divisors
      int d=1;
      for (int j=0;j<k;j++) if(z&(1<<j)) d*=vpx[j];
      //printf("i:%d x:%d d:%d z:%d inz:%d\n",i,x,d,z,(1<<__builtin_popcount(z)) - 1);
      z2cnt[d][(1<<__builtin_popcount(z)) - 1]++;
    }
  }
  int *g=new int[1<<maxk];
  int *h=new int[1<<maxk];
  int final=INT_MAX/4;
  for (int x=1;x<=mx;x++) {
    if (!exists[x]) continue;
    int kx=vp[x].size();
    int xzlim=1<<kx;
    auto &vpx=vp[x];
    fill(g,g+xzlim,0);
    for (int dmsk=0;dmsk<xzlim;dmsk++) { // Get a divisor
      int d=1;
      int inner2outer[30];
      int inner=0;
      for (int j=0;j<kx;j++) {
        if(dmsk&(1<<j)) {
          inner2outer[inner++]=1<<j;
          d*=vpx[j];
        }
      }
      int innerzlim=1<<inner;
      for (int z=0;z<innerzlim;z++) { // Process a single z
        int now=z2cnt[d][z];
        if (now==0) continue;
        int outer=0;
        for (int i=0;i<inner;i++) {
          if (z&(1<<i)) outer|=inner2outer[i];
        }
        //printf("x:%d d:%d outer:%d now:%d\n",x,d,outer,now);
        g[outer]+=now;
      }
    }
    InverseNotFastSubsetConvolution(g,kx);
    fill(h,h+xzlim,INT_MAX/4);
    h[xzlim-1]=1;
    for (int w=0;w<xzlim;w++) {
      if (g[w]==0) continue;
      for (int z=0;z<xzlim;z++) {
        chkmin(h[z&w],h[z]+1);
      }
    }
    //printf("x:%d h:%d\n",x,h[0]);
    chkmin(final,h[0]);
  }
  if (final>n+5) final=-1;
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