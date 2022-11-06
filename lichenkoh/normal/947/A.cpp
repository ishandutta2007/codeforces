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
int aquo[MAXP+1];
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
      int quo=i;
      for (int j = i*i; j <= MAXP; j+=i,quo++) {
        sieve_array[j] = false;
        ap[j]=i;
        aquo[j]=quo;
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      ap[i]=i;
      aquo[i]=1;
    }
  }
}


template<int _SEGSZ> class MinSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef int S;
  S t[2 * SEGSZ];
  S identity = INT_MAX;
  S combine(const S& lefts, const S& rights) {
    return min(lefts,rights);
  }
  void init(int n) {segn=n; fill(t,t+segn*2,identity);}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  S query(int l, int r) { // sum on interval [l, r]
    r++;
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
};

MinSegTree<MAXN> ms;

int largest_prime(int x) {
  int ans=ap[x];
  while(x>1) {
    int p=ap[x]; chkmax(ans,p);
    x=aquo[x];
  }
  return ans;
}

vi all_primes(int x) {
  vi allp;
  while(x>1) {
    int p=ap[x]; allp.PB(p);
    x=aquo[x];
  }
  return allp;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  ms.init(MAXN);
  for (int x=2;x<MAXN;x++) {
    int p=largest_prime(x);
    int k=x/p;
    int cand=INT_MAX;
    if (p+1>=3) cand=p+1;
    int other=(k-1)*p+1;
    if (other>p&&other>=3) cand=other;
    //if (x==8192) printf("p:%d cand:%d other:%d\n",p,cand,other);
    ms.t[ms.segn+x]=cand;
  }
  ms.build();
  int inp; scanf("%d",&inp);
  vi allp=all_primes(inp);
  int ans=1<<30;
  for (auto &q:allp) {
    int k=inp/q;
    int l=(k-1)*q+1; int r=k*q;
    //printf("inp:%d q:%d k:%d l:%d r:%d\n",inp,q,k,l,r);
    if (l<=r) {
      int cand=ms.query(l,r);
      //printf("cand:%d\n",cand);
      chkmin(ans,cand);
    }
  }
  printf("%d\n",ans);
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