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

const int MAXFACT=202+4;
int fact[MAXFACT+1],invfact[MAXFACT+1];
int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }

inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
int _binom(int n,int k) {
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}
int cachebinom[MAXFACT+1][MAXFACT+1];
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
  for (int x=0;x<=MAXFACT;x++) {
    for (int y=0;y<=x;y++) {
      cachebinom[x][y]=_binom(x,y);
    }
  }
}
inline int binom(int n, int k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return cachebinom[n][k];
}

int rint();char rch();long long rlong();
int a[20];
int f[2][204];
int solve(int n) {
  int cur=0,nxt=1;
  memset(f[cur],0,sizeof(int)*(n+2));
  f[cur][0]=1;
  for (int d=0;d<=9;d++) {
    memset(f[nxt],0,sizeof(int)*(n+2));
    int bs=(d==0)?1:0;
    for (int x=0;x<=n;x++) {
      int prev=f[cur][x];
      int l=n-x-bs;
      for (int t = a[d]; t <= l; t++) {
        f[nxt][x+t]=(f[nxt][x+t]+prev*(ll)binom(l,t))%MOD;
      }
    }
    swap(cur,nxt);
  }
  return f[cur][n];
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  int n=rint();
  for (int d=0;d<=9;d++) a[d]=rint();
  int ans=0;
  for (int l=1;l<=n;l++) {
    ans+=solve(l);
    if (ans>=MOD) ans-=MOD;
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