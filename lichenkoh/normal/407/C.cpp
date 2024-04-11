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

int readInt()
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

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const int MAXFACT=1e5+100+4;
int fact[MAXFACT+1],invfact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}

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
int binomcache[101][101];
const int mn=1e5+4;
int inp[mn];
int f[101][101];
pair<int,int> v[2*mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt();
  for (int i=1;i<=n;i++) inp[i]=readInt();
  init();
  for (int x=0;x<=100;x++) for (int y=0;y<=x;y++) binomcache[x][y]=binom(x,y);
  for (int j=0;j<m;j++) {
    int l=readInt(),r=readInt(),k=readInt();
    v[j<<1]=(MP(l,k<<20));
    r++;
    v[(j<<1)|1]=(MP(r,(k<<20)|(r-l+k)));
  }
  sort(v,v+2*m);
  int vidx=0;
  for (int x=1;x<=n;x++) {
    for (int k=0;k<=100;k++) {
      for (int y=100;y>=1;y--) {
        f[k][y]+=f[k][y-1];
        if (f[k][y]>=MOD) f[k][y]-=MOD;
      }
    }
    while(v[vidx].fst<x&&vidx<2*m) vidx++;
    while(v[vidx].fst==x&&vidx<2*m) {
      int sec=v[vidx].snd;
      int k=sec>>20,extra=sec&((1<<20)-1);
      //printf("x:%d k:%d extra:%d\n",x,k,extra);
      if (extra==0) {
        for (int y=0;y<=k;y++) {
          f[k][y]+=binomcache[k][y];
          if (f[k][y]>=MOD) f[k][y]-=MOD;
        }
      }
      else {
        for (int y=0;y<=k;y++) {
          f[k][y]-=binom(extra,y);
          if (f[k][y]<0) f[k][y]+=MOD;
        }
      }
      vidx++;
    }
    ll ans=inp[x];
    for (int k=0;k<=100;k++) {
      ans+=f[k][k];
    }
    //printf("x:%d ans:%d\n",x,(int)(ans%MOD));
    printf("%d ",(int)(ans%MOD));
  }
  printf("\n");
}