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

int mod_pow(int a, int n, int mod) {
  int ret = 1; int p = a % mod;
  while (n) {
    if (n & 1) ret = (ret *(ll) p) % mod;
    p = (p *(ll) p) % mod;
    n >>= 1;
  }
  return ret;
}
bool isp(int p) {
  int slim=min(p-1,(int)(ceil(sqrt(p))+2));
  for (int x=2;x<=slim;x++) {
    if (p%x==0) return false;
  }
  return true;
}
const int MAXN=1e6+4;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];
int sp[MAXP+1];
vector<int> gpv;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    sp[i]=1<<30;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = (int)(ceil(sqrt(MAXP)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        chkmin(sp[j],i);
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      chkmin(sp[i],i);
    }
  }
}
map<int,int> factorize(int x) {
  assert(sieve_array[2]);
  map<int,int> h;
  while(x>=MAXP) {
    bool found=false;
    for (auto &p:gpv) {
      if (p*(ll)p>x) break;
      int cnt=0;
      while ((x%p)==0) {
        x/=p;
        cnt++;
      }
      if (cnt>0) {
        h[p]+=cnt;
        found=true;
      }
    }
    if (x<MAXP) break;
    if (!found) break;
  }
  if (x<MAXP) {
    while(x>1) {
    int p=sp[x];
    x/=p;
    h[p]++;
    }
  }
  if (x>1) h[x]++;
  return h;
}

vector<int> exp_cand;
void init_is_primitive_root(int p) {
  map<int,int> fac=factorize(p-1);
  for (auto &w:fac) {
    //printf("p:%d w.fst:%d e:%d\n",p,w.fst,p/w.fst);
    exp_cand.PB(p/w.fst);
  }
}
bool is_primitive_root(int r, int p) {
  r%=p;
  if (r==0) return false;
  for (auto &e:exp_cand) {
    int got=mod_pow(r, e, p);
    if (got==1) return false;
  }
  return true;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),x=rint();
  int p=n+1;
  if (!isp(p)) {
    printf("-1\n");
    return 0;
  }
  sieve();
  init_is_primitive_root(p);
  int blo=max(2,x-p);
  for (int b=x-1;b>=blo;b--) {
    if (is_primitive_root(b,p)) {
      printf("%d\n",b); return 0;
    }
  }
  printf("-1\n");
}