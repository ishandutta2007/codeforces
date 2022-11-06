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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
void bf(int n) {
  vector<vector<int> > f[2];
  for (int i=0;i<n;i++) {
    vector<int> v; v.resize(n);
    v[i]++;
    f[0].PB(v);
  }
  int sign=1;
  int cur=0,nxt=1;
  while(f[cur].size()>1) {
    f[nxt].clear();
    int k=f[cur].size();
    for (int i=0;i<k-1;i++) {
      vector<int> v=f[cur][i];
      for (int j=0;j<n;j++) {
        v[j]+=f[cur][i+1][j]*sign;
      }
      sign=-sign;
      f[nxt].PB(v);
    }
    swap(cur,nxt);
  }
  for (auto &w:f[cur][0]) printf("%d ",w);
  printf(" n:%d\n",n);
}
const int mn=200000+8;

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXFACT=4e5+4;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
void init() {
  ll got=1;
  for (ll x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
  for (ll x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}
ll binom(ll n,ll k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}

ll starbar(ll stars, ll parts) {
  if (parts==0) {
    return (stars==0)?1:0;
  }
  if (parts<=0||stars<0) return 0;
  return binom(stars+parts-1,parts-1);
}

ll a[mn];
ll b[2][mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  init();
	int n=readInt();
  for (int i=0;i<n;i++) a[i]=readInt();
  if (n==1) {
    printf("%lld\n",a[0]%MOD); return 0;
  }
  int k=(n-2)/2;
  int rem=(n-2)%2;
  for (int i=0;i<=k;i++) {
    b[0][i*2]=binom(k,i);
    b[0][i*2+1]=(k%2==0)?b[0][i*2]:-b[0][i*2];
  }
  //for (int i=0;i<2*k+2;i++) printf("%lld ",b[0][i]);
  //printf("\n");
  if (rem) {
    b[1][0]=1;
    for (int i=1;i<n;i++) {
      if (i%2) b[1][i]=b[0][i-1]+b[0][i];
      else b[1][i]=-b[0][i-1]+b[0][i];
    }
  }
  //for (int i=0;i<n;i++) printf("%lld ",b[rem][i]);
  //printf("\n");
  ll ans=0;
  for (int i=0;i<n;i++) {
    ans+=mul(b[rem][i],a[i]);
    if (ans<0) ans+=MOD;
    ans%=MOD;
  }
  printf("%lld\n",ans);

}