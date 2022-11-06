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
const int mn=100;
const int mk=mn*mn;
const int mod=MOD;
int mod_pow(int a, int n) {
  int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret;
}

const int MAXFACT=mn;
int fact[MAXFACT+1],invfact[MAXFACT+1];
int factpow[MAXFACT+1],invfactpow[MAXFACT+1];
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
void init() {
  int got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2);
  for (int x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}
int binom(int n,int k) {
  //if (n<k) return 0;
  //if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}


int f[2][mk+1];
int g[2][mn+1];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; ll m; int k; cin>>n>>m>>k;
  int cur=0,nxt=1;
  init();
  ll baseblocks=m/n;
  for (int blockdelta=0;blockdelta<=1;blockdelta++) {
    int blocks=(baseblocks+blockdelta)%(MOD-1);
    for (int u=0;u<=n;u++) {
      g[blockdelta][u]=mod_pow(binom(n,u),blocks);
    }
  }
  f[cur][0]=1;
  for (int r=0;r<n;r++) {
    int blockdelta=(m-r+n-1)/n - baseblocks;
    memset(f[nxt],0,sizeof f[nxt]);
    for (int x=0;x<=k;x++) {
      int ulim=min(n,k-x);
      int got=f[cur][x];
      if (got==0) continue;
      for (int u=0;u<=ulim;u++) {
        ll toadd=g[blockdelta][u]*(ll)got;
        //if(toadd) printf("r:%d block:%lld x:%d u:%d toadd:%lld\n",r,baseblocks+blockdelta,x,u,toadd);
        f[nxt][x+u]=(f[nxt][x+u]+toadd)%MOD;
      }
    }
    /*for (int x=0;x<=k;x++) {
      if (f[nxt][x]) printf("r:%d x:%d f:%d\n",r,x,f[nxt][x]);
    }*/
    swap(cur,nxt);
  }
  int ans=f[cur][k];
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