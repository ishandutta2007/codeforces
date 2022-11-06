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
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
typedef unsigned int uint;
const uint MAXP=300000000;
//const uint MAXP=600;
const uint MAXSP=sqrt(MAXP)+2;
const uint MAXMEM=8000000;
//const uint MAXMEM=400;
bitset<MAXMEM> sieve_array;
bitset<MAXSP+1> primes;

uint tmp[60];
uint final=0;
uint ga,gb,gc,gd,gn;
void handle_prime(uint p) {
  //printf("p:%u\n",p);
  uint n=gn,a=ga,b=gb,c=gc,d=gd;
  if (p>n) return;
    uint ppow=p;
    uint klim=0;
    while(ppow<=n) {
      tmp[klim++]=n/ppow;
      unsigned int res;
      if(__builtin_umul_overflow(p,ppow,&res)) break;
      ppow=res;
    }
    tmp[klim]=0;
    uint fp=d+p*(c+(p*(b+p*a)));
    for (uint k=0;k<klim;k++) {
      uint cnt=tmp[k]-tmp[k+1];
      //printf("p:%d pow:%d cnt:%d fp:%d\n",p,k+1,cnt,fp);
      final+=cnt*(k+1)*fp;
    }
}


void sieve() {
  assert(0==(MAXMEM&1)); // MAXMEM must be even
  primes[2]=true; handle_prime(2);
  for (uint base=2;base<=MAXP;base+=MAXMEM) {
    if (base!=2) sieve_array.reset();
    uint biglim=min(MAXP,base+MAXMEM-1U);
    for (uint p=3;p<=MAXSP;p=primes._Find_next(p)) {
      uint st=max(p*p,(((base+p-1U)/p)|1U)*p);
      if (st>biglim) break;
      for (uint prod=st;prod<=biglim;prod+=(p<<1)) {
        sieve_array[prod-base]=true;
      }
    }
    uint slim=min(MAXSP,base+MAXMEM-1);
    for (uint p=base+1;p<=biglim;p+=2) {
      if (!sieve_array[p-base]) {
        handle_prime(p);
        if (p<=MAXSP) {
          primes[p]=true;
          uint st=max(p*p,(((base+p-1U)/p)|1U)*p);
          for (uint prod=st;prod<=biglim;prod+=(p<<1)) {
            //printf("prod:%d\n",prod);
            sieve_array[prod-base]=true;
          }
        }
      }
    }
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  gn=rint(), ga=rint(),gb=rint(),gc=rint(),gd=rint();
  sieve();
  printf("%u\n",final);
}

int rint()
{
  int x; cin>>x; return x;
}