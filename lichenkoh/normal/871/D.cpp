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
const ll INF=1e18;
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

const int MAXN=1e7+1;
const int MAXP=MAXN;
int mu[MAXP],ptbl[MAXP];
vector<int> primes;
void sieve(int maxp) {
  maxp++;
  mu[1] = ptbl[1] = 1;
  for (int i=2; i<maxp; i++) {
    if (!ptbl[i]) {
      ptbl[i] = i;
      primes.PB(i);
      mu[i] = -1;
    }
    for (auto p : primes) {
      int x = i*p;
      if (x >= maxp) break;
      if (!ptbl[x]) ptbl[x] = p;
      mu[x] = -mu[i];
      if (i%p==0) {
        mu[x] = 0;
        break;
      }
    }
  }
}

const int MAXFAC=24;
pair<int,int> factorize_dest[MAXFAC];
int factorize_tmp[MAXFAC];
int factorize(int x) {
  int tsz=0;
  while(x>1) {
    int p=ptbl[x];
    x/=p;
    factorize_tmp[tsz++]=p;
  }
  sort(factorize_tmp,factorize_tmp+tsz);
  int didx=0;
  for (int tidx=0;tidx<tsz;tidx++) {
    int p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,1);
    }
    else factorize_dest[didx-1].snd++;
  }
  return didx;
}
const int MAXDIV=4096;
int divisors_dest[MAXDIV]; // This needs to be larger than you think
int getdivisors(int x) {
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
  return sz;
}
int quon[MAXN];
int n,sqrtn;

int vp[MAXN];

int spcnt[MAXN];
int main()
{
  scanf("%d",&n);
  sieve(n);
  int special1=3*n-2;
  sqrtn=round(sqrt(n));
  if ((sqrtn*sqrtn)>n) sqrtn--;
  quon[1]=n;
  ll final1=0;
  for (int d=2;d<=n;d++) {
    int mud=mu[d];
    if (mud==0) continue;
    int nd=n/d;
    quon[d]=nd;
    ll contrib=nd*(ll)(mud*nd);
    final1-=contrib;
  }
  final1-=(n-1);
  ll final2=0;
  for (int d=2;d<=n;d++) {
    int mud=mu[d];
    if (mud==0) continue;
    int vpsz=0;
    for (int x = max(2,d); x <= n; x+=d) {
      vp[vpsz++]=ptbl[x];
    }
    sort(vp,vp+vpsz);
    int r=vpsz-1;
    ll collect=0;
    for (int l=0;l<vpsz;l++) {
      int p=vp[l]; int pn=quon[p];
      while(r>=0&&vp[r]>pn) r--;
      collect+=(r+1);
    }
    final2+=collect*mu[d];
  }
  for (int x=2;x<=n;x++) spcnt[ptbl[x]]++;
  for (int x=2;x<=n;x++) spcnt[x]+=spcnt[x-1];
  for (int p=2;p<=n;p++) {
    final2+=(spcnt[p]-spcnt[p-1])*(ll)spcnt[quon[p]];
  }
  ll final0=0;
  for (int a=2;a<=n;a++) {
    int spa=ptbl[a];
    int lower;
    if (spa<= (n>>1)) {
      lower=(n>>1);
    }
    else {
      lower=quon[spa];
    }
    int imin=0,imax=primes.size();
    while(imin<imax) {
      int imid = (imin + imax) >> 1;
      if (primes[imid] <= lower) imin = imid + 1;
      else imax = imid;
    }
    int ans=spcnt[n]-(imin>0?spcnt[primes[imin-1]]:0);
    if (ptbl[a]==a && a > lower) {
      ans-=(spcnt[a]-spcnt[a-1]);
    }
    //printf("a:%d spa:%d ans:%d lower:%d pimin:%d. %d\n",a,spa,ans,lower,primes[imin],spsum[a]);
    final0+=ans;
  }
  ll final3=n*(ll)n-final0-final1-final2-special1;
  //printf("f0:%lld f1:%lld f2:%lld f3:%lld s:%d\n",final0,final1,final2,final3,special1);
  ll final=(final1+2*final2+3*final3)>>1;
  printf("%lld\n",final);
}