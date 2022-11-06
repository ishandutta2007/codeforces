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
typedef unsigned int uint;
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

const int MAXN=1e6+4;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];
int ap[MAXP+1];
vector<int> gpv;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    ap[i]=1<<30;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = (int)(ceil(sqrt(MAXP)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        ap[j]=i;
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      ap[i]=i;
    }
  }
}

int factorize_dest[20];
int factorize(int x) {
  int tsz=0;
  while(x>1) {
    int p=ap[x];
    while (x%p==0) x/=p;
    factorize_dest[tsz++]=p;
  }
  return tsz;
}

ll f(int psz, uint hi) {
  if (psz==0) return hi;
  ll ans=0;
  for (int z=0;z<(1<<psz);z++) {
    int c=1;
    for (int i=0;i<psz;i++) {
      if (z&(1<<i)) c*=factorize_dest[i];
      uint contrib=hi/c;
      if (__builtin_popcount(z)&1) ans-=contrib;
      else ans+=contrib;
    }
  }
  return ans;
}

uint solve(int lo, int n, int k) {
    uint imin=lo+1,imax=UINT_MAX;
    int psz=factorize(n);
    ll locnt=f(psz,lo)+k;
    while(imin<imax) {
      uint imid=imin+(imax-imin)/2;
      ll hicnt=f(psz,imid);
      if (hicnt<locnt) imin=imid+1;
      else imax=imid;
    }
    return imin;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  /*const int x=100,y=1;
  for (int lo=x;lo>=y;lo--) for (int n=x;n>=y;n--) for (int k=x;k>=y;k--) {
    uint ans=solve(lo,n,k);
    if (ans>(1<<28)) {
      printf("%d %d %d\n",lo,n,k);
      exit(-1);
    }
  }
  printf("Passed\n");
  */
  
  int tlim=rint();
  for (int ti=0;ti<tlim;ti++) {
    int lo=rint(),n=rint(),k=rint();
    uint imin=solve(lo,n,k);
    assert(imin<(1<<30));
    printf("%u\n",imin);
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