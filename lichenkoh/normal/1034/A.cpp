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

const int MAXN=1.5e7+4;
const int MAXP=MAXN;
int sp[MAXP+1],sd[MAXP+1];
void sieve() {
  for (int i = 0; i <= MAXP; i++) sp[i]=1<<30;
  int lim = (int)(ceil(sqrt(MAXP)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sp[i]==(1<<30)) {
      for (int j = i+i,d=2; j <= MAXP; j+=i,d++) {
        if (i<sp[j]) {
          sp[j]=i;
          sd[j]=d;
        }
      }
    }
  }
  for (int i=2;i<=MAXP;i++) {
    if (sp[i]==(1<<30)) {sp[i]=i; sd[i]=1;}
  }
}

template <typename LST> struct LimitedVec  {
  LST a[500];
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
  LST& back()
  {
    return a[sz-1];
  }
  void clear() {
    sz=0;
  }
  int size() {
    return sz;
  }
};

LimitedVec<int> vfac;

void factorize(int x) {
  vfac.clear();
  while(x>1) {
    int p=sp[x];
    //assert(sd[x]==x/p);
    x=sd[x];
    if (vfac.size()==0||vfac.back()!=p) vfac.PB(p);
  }
}
const int mn=3e5+4;
int a[mn];
int vans[MAXN];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int n=rint();
  for (int i=0;i<n;i++) {
    a[i]=rint();
  }
  int g=a[0];
  for (int i=1;i<n;i++) g=__gcd(g,a[i]);
  for (int i=0;i<n;i++) {
    factorize(a[i]/g);
    //printf("%d has fac: ",a[i]/g);
    for (auto &w:vfac) {
      //printf("%d ",w);
      vans[w]++;
    }
    //printf("\n");
  }
  int ans=0;
  for (int i=2;i<MAXN;i++) chkmax(ans,vans[i]);
  int final=n-ans;
  if (final==n) final=-1;
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