#include <bits/stdc++.h>
#include <assert.h>
#define _USE_MATH_DEFINES
#include <cmath>
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
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
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
const int mn=1e5+4;
int va[mn];
vector<int> g[mn];
map<int,int> leafh;
map<int,int> nonh;
int vl[mn];
void dfs(int x, int lvl) {
  vl[x]=lvl;
  for (auto &y:g[x]) {
    dfs(y,lvl+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d\n",&n);
  for (int i=1;i<=n;i++) scanf("%d",&va[i]);
  for (int x=2;x<=n;x++) {
    int y;
    scanf("%d",&y);
    g[y].PB(x);
  }
  dfs(1,0);
  int maxl=0; for (int x=1;x<=n;x++) chkmax(maxl,vl[x]);
  ll leafcnt=0;
  int nim=0;
  for (int x=1;x<=n;x++) {
    if ((maxl-vl[x])%2==0) {
      nim^=va[x];
      leafh[va[x]]++;
      leafcnt++;
    }
    else {
      nonh[va[x]]++;
    }
  }
  ll nonleaf=n-leafcnt;
  ll final=0;
  if (nim==0) {
    for (auto &w:leafh) {
      final+=(ll)w.snd*(ll)nonh[w.fst];
    }
    final+=(leafcnt*(leafcnt-1))/2+(nonleaf*(nonleaf-1))/2;
  }
  else {
    for (auto &w:leafh) {
      final+=(ll)w.snd*(ll)nonh[w.fst^nim];
    }
  }
  printf("%lld\n",final);
}