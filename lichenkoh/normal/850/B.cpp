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
int factorize_dest[500];
int factorize_tmp[500];
int factorize(int x) {
  const int power=1;
  // Needed for factorizing MAXN^3 numbers
  //int xsqrt=round(sqrt(x));
  //if (xsqrt*(ll)xsqrt==x) {
  //  power=2;
  //  x=xsqrt;
  //}
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
    int p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=p;
    }
  }
  return didx;
}

bool seen[MAXP];
bool facced[MAXP];
const int mn=5e5+2;
int a[mn];
//int vkey[mn];
//int vcnt[mn];
int b[mn];
//int bcnt[mn];
const time_t TIMELIM=1.8*CLOCKS_PER_SEC;
int vr[MAXP];
int main()
{
  time_t st = clock();
  sieve();
  //ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),x=rint(),y=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  int bsz=0;
  for (int i=0;i<n;i++) {
    int val=a[i]; if (val!=1) {b[bsz++]=val;}
  }
  ll final=x*(ll)n;
  int klim=(x-1)/y;
  {
    int cnt=0;
    for (int i=0;i<n;i++) {
      cnt+=a[i]&1;
    }
    ll sum=cnt*(ll)min(x,y);
    chkmin(final,sum);
  }
  int lft=0;
  for (int i=0;i<bsz;i++) {
    int val=b[i];
    if (!facced[val]) {facced[val]=true; lft++;}
  }
  memset(facced,0,sizeof facced);
  if (bsz) while(lft>0) {
    time_t now=clock();
    if (now-st > TIMELIM) {
      printf("%lld\n",final); return 0;
    }
    srand(now);
    int val=b[rand()%bsz];
    for (int k=0;k<10000;k++) {
      if (!facced[val]) break;
      val=b[rand()%bsz];
    }
    if (facced[val]) continue;
    facced[val]=true;
    lft--;
    int didx=factorize(val);
    for (int di=0;di<didx;di++) {
      int p=factorize_dest[di];
      if (seen[p]) continue;
      for (int i=1;i<p;i++) vr[i]=p-i;
      for (int i=p;i<MAXP;i++) vr[i]=vr[i-p];
      ll sum=0;
      for (int i=0;i<n;i++) {
        int need=vr[a[i]];
        if (need<=klim) sum+=need*(ll)y;
        else sum+=x;
      }
      chkmin(final,sum);
      if (clock()-st > TIMELIM) {
        printf("%lld\n",final); return 0;
      }
    }
  }
  printf("%lld\n",final);
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