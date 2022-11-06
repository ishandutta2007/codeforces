#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define fst first
#define snd second
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
const int MOD=1000000007;
int extgcd(int a, int b, int& x, int& y) { for (int u = y = 1, v = x = 0; a;) { int q = b / a; swap(x -= q *(ll) u, u); swap(y -= q *(ll) v, v); swap(b -= q *(ll) a, a); } return b; }
int mod_inv(int a, int m) { int x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }

const int MAXFACT=2e6+4;
int fact[MAXFACT+1],invfact[MAXFACT+1];
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
void init() {
  int got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
  for (int x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}
int binom(int n,int k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}

const int mn=1000000+2;
int a[mn];
//vector<pii> v;
map<int,int> h;

int f(int n, int L, int y) {
  // sum (L choose x) * (x+y-1+(n-L-y))! * (n-(x+y-1+(n-L-y))-1)!*y from x=0 to x=L
  return mul(mul(y,fact[n]),mod_inv(n-L,MOD));
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  int n=rint();
  for (int i=0;i<n;i++) {
    int x=rint();
    h[x]++;
  }
  auto last=*(h.rbegin());
  int L=0;
  int ans=0;
  for (auto it=h.begin();it!=h.end();++it) {
    auto w=*it;
    if (w==last) break;
    int C=f(n,L,w.snd);
    int contrib=mul(C,w.fst);
    //printf("n:%d L:%d w.snd:%d C:%d contrib:%d\n",n,L,w.snd,C,contrib);
    ans=(ans+contrib)%MOD;
    L+=w.snd;
  }
  int final=ans;
  printf("%d\n",final);
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