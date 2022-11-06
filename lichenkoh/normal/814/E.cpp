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
const int INF=1<<25;
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

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXFACT=100;
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

const int mn=51;
int n;
int deg[mn];
int vc[4][mn];
ll ptwo[mn];
int dpf[mn][mn][mn][mn];
int f(int ia2, int ia3, int b1, int b2) {
  if (b1<0||b2<0) return 0;
  int dpval=dpf[ia2][ia3][b1][b2];
  if (dpval!=-1) return dpval;
  ll ans=0;
  if (ia2==0&&ia3==0) {
    if (b1+b2==0) return 1;
    else return 0;
  }
  int DEG;
  int a2=ia2,a3=ia3;
  if (ia2>0) {
    DEG=2;
    a2--;
  }
  else {
    assert(ia3>0);
    DEG=3;
    a3--;
  }
  for (int b=0;b<=DEG-1;b++) {
    int nb1=b1,nb2=b2;
    int samedeg=DEG-1-b;
    if (b==1) nb1--;
    if (b==2) nb2--;
    for (int ta2=0;ta2<=min(a2,samedeg);ta2++) {
      int ta3=samedeg-ta2;
      if (ta3>a3) continue;
      int tomul=mul(binom(a2,ta2),binom(a3,ta3));
      int prev=f(a2-ta2+ta3,a3-ta3,nb1,nb2);
      ans=(ans+(ll)tomul*(ll)prev)%MOD;
    }
  }
  //if (ans)printf("f ia2:%d ia3:%d b1:%d b2:%d ans:%lld\n",ia2,ia3,b1,b2,ans);
  return dpf[ia2][ia3][b1][b2]=ans;
}
int dpg[mn][mn][mn];
int g(int x, int y, int below) {
  if (y>=n) return 0;
  int dpval=dpg[x][y][below];
  if (dpval!=-1) return dpval;
  ll ans=0;
  for (int b2=0;b2<=below/2;b2++) {
    int b1=below-b2*2;
    ll tomul=mul(fact[below],ptwo[b2]);
    int gotf=f(vc[2][y]-vc[2][x], vc[3][y]-vc[3][x], b1, b2);
    ans=(ans+(ll)gotf*(ll)tomul)%MOD;
  }
  //if (ans)printf("g x:%d y:%d below:%d ans:%lld\n",x,y,below,ans);
  return dpg[x][y][below]=ans;
}
int dph[mn][mn];
int h(int x, int above) {
  if (x>n-1) return 0;
  if (x==n-1) {
    if (above==0) return 1;
    else return 0;
  }
  if (above==0) return 0;
  int dpval=dph[x][above];
  if (dpval!=-1) return dpval;
  ll ans=0;
  for (int below=0;below<n;below++) {
    ans=(ans+(ll)g(x,x+above,below)*(ll)h(x+above,below))%MOD;
  }
  //if (ans)printf("x:%d above:%d ans:%lld\n",x,above,ans);
  return dph[x][above]=ans;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  ptwo[0]=1;
  int itwo=mod_pow(2,MOD-2,MOD);
  for (int i=1;i<mn;i++) {
    ptwo[i]=mul(ptwo[i-1],itwo);
  }
  scanf("%d",&n);
  int deg0; scanf("%d",&deg0);
  for (int i=0;i<n-1;i++) scanf("%d",&deg[i]);
  for (int i=0;i<n-1;i++) {
    vc[deg[i]][i+1]++;
  }
  for (int k=2;k<=3;k++) for (int i=1;i<=n;i++) {
    vc[k][i]+=vc[k][i-1];
  }
  memset(dpf,-1,sizeof dpf);
  memset(dpg,-1,sizeof dpg);
  memset(dph,-1,sizeof dph);
  int ans=h(0,deg0);
  printf("%d\n",ans);
}