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

const int mx=301;
typedef int UFTYPE;
class UnionFind {
public:

// Custom
UFTYPE ufIdentity = 0;
inline UFTYPE combine(UFTYPE x, UFTYPE y) {
  return x+y;
}
inline UFTYPE getInitialValue(int x) {
  return 1;
}


int ufParent[mx];
UFTYPE ufData[mx];
inline void ufreset(int x) {
  ufParent[x]=x;
  ufData[x]=getInitialValue(x);
}
void init() {
  for (int x=0;x<mx;x++) {
    ufreset(x);
  }
}
int ffind(int x) {
  if (ufParent[x] != x) {
    ufParent[x] = ffind(ufParent[x]);
  }
  return ufParent[x];
}
void funion(int _x, int _y) {
  int xr = ffind(_x);
  int yr = ffind(_y);
  if (xr==yr) return;
  if (rand()&1) swap(xr,yr);
  ufParent[xr] = yr;
  ufData[yr]=combine(ufData[xr],ufData[yr]);
}
void funionFast(int xr, int yr) {
  if (xr==yr) return;
  if (rand()&1) swap(xr,yr);
  ufParent[xr] = yr;
  ufData[yr]=combine(ufData[xr],ufData[yr]);
}
int getData(int x) {
  return ufData[ffind(x)];
}
int getDataFast(int x) {
  return ufData[x];
}
};


int extgcd(int a, int b, int& x, int& y) { for (int u = y = 1, v = x = 0; a;) { int q = b / a; swap(x -= q *(ll) u, u); swap(y -= q *(ll) v, v); swap(b -= q *(ll) a, a); } return b; }
int mod_inv(int a, int m) { int x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }


__inline void add(int &a, int b) {
    if ((a += b) >= MOD) {
        a -= MOD;
    }
}

int power(int a, int n) {
    int ret = 1;
    for (int i = 1; i <= n; i <<= 1) {
        if (n & i) {
            ret = 1LL * ret * a % MOD;
        }
        a = 1LL * a * a % MOD;
    }
    return ret;
}

int inverse(int x) {
    return power(x, MOD - 2);
}


const int MAXFACT=602;
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


const int mn=301;
int S[mn][mn];
int f(int n, int k) {
  // Ways to split n vertices into k disjoint paths, divided by n!
  if (S[n][k]!=-1) return S[n][k];
  if (n==0&&k==0) return 1;
  if (n==0||k==0) return 0;
  ll ans=0;
  for (int x=1;x<=n;x++) {
    ans+=f(n-x,k-1);
  }
  return S[n][k]=(ans%MOD);
}

int g(int n, int t) {
  int ans=(mul(fact[n],f(n,t))*(ll)invfact[t])%MOD;
  return ans;
}

int p[2][301];

int solve(int n, vector<int> cliques) {
  int cur=0,nxt=1;
  memset(p,0,sizeof p);
  p[cur][0]=1;
  for (auto &cl:cliques) {
    memset(p[nxt],0,sizeof p[nxt]);
    for (int x=0;x<=n;x++) {
      for (int y=0;y<=n-x;y++) {
        p[nxt][x+y]=(p[nxt][x+y]+p[cur][x]*(ll)g(cl,y))%MOD;
      }
    }
    swap(cur,nxt);
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    int got=mul(p[cur][i], fact[i]);
    if ((i^n)&1) got=MOD-got;
    add(ans, got);
  }
  return (ans+MOD)%MOD;
}


bool issquare(ll inp) {
  ll s=round(sqrt(inp));
  for (ll x=s-1;x<=s+1;x++) {
    if (x*x==inp) return true;
  }
  return false;
}
int a[mn];
UnionFind uf;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  memset(S,-1,sizeof S);
  //for (int k=1;k<=5;k++) {
  //  printf("k:%d\n",k);
  //  for (int t=0;t<=k;t++) printf("t:%d g:%d\n",t,g(k,t));
  //}return 0;
  int n=rint();
  for (int i=0;i<n;i++) {
    a[i]=rint();
  }
  uf.init();
  for (int x=0;x<n;x++) {
    for (int y=0;y<x;y++) {
      if (issquare(a[x]*(ll)a[y])) {
        uf.funion(x,y);
      }
    }
  }
  vector<int> cliques;
  for (int x=0;x<n;x++) {
    if (uf.ufParent[x]==x) {
      cliques.PB(uf.ufData[x]);
    }
  }
  int ans=solve(n,cliques);
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