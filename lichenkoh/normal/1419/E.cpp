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

pair<int,int> factorize_dest[500];
int factorize_tmp[500];
int factorize(int x) {
  const int power=1;
  int tsz=0;
  while(x>=MAXP) {
    bool found=false;
    for (auto &p:gpv) {
      if (p*(ll)p>x) break;
      while ((x%p)==0) {
        //printf("x:%lld p:%d\n",x,p);
        x/=p;
        factorize_tmp[tsz++]=p;
        found=true;
      }
    }
    if (x<MAXP) break;
    if (!found) break;
  }
  if (x<MAXP) {
    while(x>1) {
      int p=ap[x];
      x/=p;
      factorize_tmp[tsz++]=p;
    }
  }
  if (x>1) factorize_tmp[tsz++]=x;
  sort(factorize_tmp,factorize_tmp+tsz);
  int didx=0;
  for (int tidx=0;tidx<tsz;tidx++) {
    int p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,power);
    }
    else factorize_dest[didx-1].snd+=power;
  }
  return didx;
}

int divisors_dest[50000]; // This needs to be larger than you think
pii getdivisors(int x) { // MP(numdivisors, numprimes)
  // Puts all divisors into int divisors_dest[], and returns the count
  int numprimes=factorize(x);
  int sz=1;
  divisors_dest[0]=1;
  for (int pi=0;pi<numprimes;pi++) {
    int p=factorize_dest[pi].fst; int elim=factorize_dest[pi].snd;
    int pp=1;
    int prevsz=sz;
    for (int e=1;e<=elim;e++) {
      pp*=p;
      for (int i=0;i<prevsz;i++) {
        divisors_dest[sz++]=divisors_dest[i]*pp;
      }
    }
  }
  return MP(sz,numprimes);
}



void go() {
  int T=rint();
  pii ret=getdivisors(T);
  int nd=ret.fst,np=ret.snd;
  set<int> divs; for (int i=0;i<nd;i++) divs.insert(divisors_dest[i]);
  divs.erase(1);
  vi vans;
  for (int i=0;i<np;i++) {
    int p=factorize_dest[i].fst,e=factorize_dest[i].snd;
    if (np==2&&i==0) {
      int q=factorize_dest[(i+1)%np].fst;
      vans.PB(p*q);
      divs.erase(p*q);
    }
    int x=1;
    for (int k=1;k<=e;k++) {
      x*=p;
      vans.PB(x);
      divs.erase(x);
    }
    for (int k=2;k<=np-2;k++) {
      int q=factorize_dest[(i+k)%np].fst;
      int pq=p*q;
      for (auto it=divs.begin();it!=divs.end();) {
        int d=*it;
        if (d%pq==0) {
          vans.PB(d);
          it=divs.erase(it);
        } else {
          ++it;
        }
      }
    }
    { int k=1;
      int q=factorize_dest[(i+k)%np].fst;
      int pq=p*q;
      for (auto it=divs.begin();it!=divs.end();) {
        int d=*it;
        if (d%pq==0) {
          vans.PB(d);
          it=divs.erase(it);
        } else {
          ++it;
        }
      }
    }
  }
  for (auto &w:vans) printf("%d ",w);
  printf("\n");
  int vn=vans.size();
  int bad=0;
  for (int i=0;i<vn;i++) if (__gcd(vans[i], vans[(i+1)%vn])==1) bad++;
  printf("%d\n",bad);
  assert(vans.size() == nd-1);
  //printf("vans:%d nd:%d\n",(int)vans.size(),nd);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int t=rint(); for (int i=0;i<t;i++) go();
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