#include <bits/stdc++.h>
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


const int MAXN=1e5+4;
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
  int power=1;
  // Needed for factorizing MAXN^3 numbers
  int xsqrt=round(sqrt(x));
  if (xsqrt*(int)xsqrt==x) {
    power=2;
    x=xsqrt;
  }
  // End needed for factorizing MAXN^3 numbers
  int tsz=0;
  while(x>=MAXP) {
    bool found=false;
    for (auto &p:gpv) {
      if (p*(int)p>x) break;
      while ((x%p)==0) {
        //printf("x:%intd p:%d\n",x,p);
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
const int mn=1e5+4;
int f[mn],a[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  sieve();
int ans=0;
  for (int i=0;i<n;i++) {
    int x=a[i];
    int numf=factorize(x);
    int best=0;
    for (int j=0;j<numf;j++) {
      int p=factorize_dest[j].fst;
      chkmax(best,f[p]);
    }
    best++;
    for (int j=0;j<numf;j++) {
      int p=factorize_dest[j].fst;
      chkmax(f[p],best);
    }
    chkmax(ans,best);
  }
  printf("%d\n",ans);

}