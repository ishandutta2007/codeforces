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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint();char rch();long long rlong();
const int MAXP=1e6+1;
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



int factorize_tmp[128];
void factorize(int *inp, vpii &factorize_dest) {
  const int power=1;
  int tsz=0;
  for (int i=0;i<3;i++) {
    int x=inp[i];
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
  }
  sort(factorize_tmp,factorize_tmp+tsz);
  int didx=0;
  factorize_dest.resize(128);
  for (int tidx=0;tidx<tsz;tidx++) {
    ll p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,power);
    }
    else factorize_dest[didx-1].snd+=power;
  }
  factorize_dest.resize(didx);
}


vpii gcd(const vpii &af,const vpii &bf) {
  vpii ans;
  int bsz=bf.size();
  int bi=0;
  for (auto &aw:af) {
    int p=aw.fst;
    while(bi<bf.size()&&bf[bi].fst<p) {bi++;}
    int e=0;
    if (bi<bf.size()&&p==bf[bi].fst) {
      e=min(aw.snd,bf[bi].snd);
    }
    ans.PB(MP(p,e));
  }
  assert(ans.size()==af.size());
  return ans;
}
ll divisors_dest[500000]; // This needs to be larger than you think
int countdivisors(const vpii &factorize_dest, const ll lim) {
  // Puts all divisors into int divisors_dest[], and returns the count
  int numprimes=factorize_dest.size();
  int sz=1;
  divisors_dest[0]=1;
  for (int pi=0;pi<numprimes;pi++) {
    ll p=factorize_dest[pi].fst; int elim=factorize_dest[pi].snd;
    ll pp=1;
    int prevsz=sz;
    for (int e=1;e<=elim;e++) {
      pp*=p;
      for (int i=0;i<prevsz;i++) {
        ll res=divisors_dest[i]*pp;
        if (res<=lim) {
          divisors_dest[sz++]=divisors_dest[i]*pp;
        }
      }
    }
  }
  return sz;
}

/*ll divisors_dest[50000]; // This needs to be larger than you think
int getdivisors(const vpii &factorize_dest) {
  // Puts all divisors into int divisors_dest[], and returns the count
  int numprimes=factorize_dest.size();
  int sz=1;
  divisors_dest[0]=1;
  for (int pi=0;pi<numprimes;pi++) {
    ll p=factorize_dest[pi].fst; int elim=factorize_dest[pi].snd;
    ll pp=1;
    int prevsz=sz;
    for (int e=1;e<=elim;e++) {
      pp*=p;
      for (int i=0;i<prevsz;i++) {
        divisors_dest[sz++]=divisors_dest[i]*pp;
      }
    }
  }
  return sz;
}*/

vpii af,bf,sf;
int va[3],vb[3],vs[3];
ll solve() {
  af.clear(); bf.clear(); sf.clear();
  vs[0]*=2;
  ll a=va[0]*(ll)va[1]*(ll)va[2];
  ll b=vb[0]*(ll)vb[1]*(ll)vb[2];
  //ll s=vs[0]*(ll)vs[1]*(ll)vs[2];
  factorize(va,af);
  factorize(vs,sf);
  vpii gcdsa=gcd(af,sf);
  vector<ll> res;
  for (int i=0;i<af.size();i++) {
    int p=af[i].fst;
    int ae=af[i].snd,ge=gcdsa[i].snd;
    if (ae>ge) {
      ll pp=1;
      for (int j=0;j<ge+1;j++) pp*=p;
      res.PB(pp);
    }
  }
  int k=res.size();
  int zlim=1<<k;
  ll ans1=0;
  for (int z=0;z<zlim;z++) {
    ll base=1;
    for (int i=0;i<k;i++) {
      if (z&(1<<i)) {
        base*=-res[i];
      }
    }
    ans1+=b/base;
  }

  //factorize(vb,bf);
  //vpii g=gcd(bf,sf);
  int ans2=countdivisors(sf,a);
  /*int divs=getdivisors(sf);
  int ans2=0;
  for (int di=0;di<divs;di++) {
    //printf("p:%d e:%d\n",w.fst,w.snd);
    ll d=divisors_dest[di];
    if (d<=a) {
      //printf("d:%d\n",d);
      ans2++;
    }
  }*/
  //printf("ans1:%lld ans2:%d\n",ans1,ans2);
  ll final=ans1+ans2;
  return final;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int t=rint();
  for (int ti=0;ti<t;ti++) {
    
    for (int i=0;i<3;i++) va[i]=rint();
    for (int i=0;i<3;i++) vb[i]=rint();
    for (int i=0;i<3;i++) vs[i]=rint();
    ll ans=solve();
    printf("%lld\n",ans);
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