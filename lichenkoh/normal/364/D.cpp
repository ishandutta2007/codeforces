#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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
/*
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

pair<ll,int> factorize_dest[500];
ll factorize_tmp[500];
int factorize(ll x) {
  int power=1;
  // Needed for factorizing MAXN^3 numbers
  int xsqrt=round(sqrt(x));
  if (xsqrt*(ll)xsqrt==x) {
    power=2;
    x=xsqrt;
  }
  // End needed for factorizing MAXN^3 numbers
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
    ll p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,power);
    }
    else factorize_dest[didx-1].snd+=power;
  }
  return didx;
}

ll divisors_dest[50000]; // This needs to be larger than you think
int getdivisors(ll x) {
  // Puts all divisors into int divisors_dest[], and returns the count
  int numprimes=factorize(x);
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
}
*/

const int mn=1e6+4;
ll inp[mn];
bool fail[mn];
time_t LIM=3.5*CLOCKS_PER_SEC;
ll tmp[mn];
pair<ll,int> pe[50000];
int main()
{
  time_t start=clock();
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  int need=(n+1)/2;
  for (int x=0;x<n;x++) inp[x]=rlong();
  /*if (n==1) {
    printf("%lld\n",inp[0]);
    return 0;
  }*/
  srand(time(0));
  for (int x=0;x<n;x++) {
    int b=rand()%n;
    swap(inp[x],inp[b]);
  }
  ll final=1;
  for (int k=0;k<n;k++) {
    if (clock()-start>=LIM) {
      printf("%lld\n",final);
      return 0;
    }
    ll inpk=inp[k];
    if (inpk<=final) continue;
    for (int t=0;t<n;t++) {
      ll g=__gcd(inpk, inp[t]);
      //printf("inpk:%lld inpt:%lld g:%lld\n",inpk,inp[t],g);
      tmp[t]=g;
    }
    sort(tmp,tmp+n);
    int pi=-1;
    for (int t=0;t<n;t++) {
      ll got=tmp[t];
      if (t==0||got!=tmp[t-1]) {
        pe[++pi]=MP(got,1);
      }
      else pe[pi].snd++;
    }
    for (int x=0;x<=pi;x++) {
      ll d=pe[x].fst;
      if (final>=d) continue;
      int have=pe[x].snd;
      //printf("d:%lld\n",d);
      if (have>=need) {
        final=d;
      }
      else for (int y=x+1;y<=pi;y++) {
        if (pe[y].fst%d==0) {
          have+=pe[y].snd;
          if (have>=need) {
            final=d;
            break;
          }
        }
      }
    }
  }
  printf("%lld\n",final);
}