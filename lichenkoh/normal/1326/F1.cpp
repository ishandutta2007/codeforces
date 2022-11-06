#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=18;
bitset<mn> g[mn];
ll * f[1<<mn][mn];
inline int next_bit_perm(int v) {
  int t = v | (v - 1);
  return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int x=0;x<n;x++) {
    string s; cin>>s;
    for (int y=0;y<n;y++) g[x][y]=(s[y]=='1');
  }
  for (int x=0;x<n;x++) {
    f[1<<x][x] = new ll[1];
    f[1<<x][x][0]=1;
  }
  for (int b=1;b<n;b++) {
    for (int u = (1 << (b+1)) - 1; u < (1 << n); u = next_bit_perm(u)) {
      int k=b;
      for (int x=0;x<n;x++) {
        f[u][x] = new ll[1<<k];
        for (int s=0;s<(1<<k);s++) f[u][x][s]=0;
      }
    }
    for (int u = (1 << b) - 1; u < (1 << n); u = next_bit_perm(u)) {
      int k=b-1;
      for (int x=0;x<n;x++) {
        if (0==((1<<x)&u)) continue;
        for (int s=0;s<(1<<k);s++) {
          ll now=f[u][x][s];
          for (int y=0;y<n;y++) {
            if ((1<<y)&u) continue;
            int nu=u|(1<<y);
            int ns=s|(int(g[x][y]) << k);
            f[nu][y][ns]+=now;
          }
        }
        delete f[u][x];
      }
    }
  }
  for (int s=0;s<(1<<(n-1));s++) {
    ll ans=0;
    for (int x=0;x<n;x++) {
      ans+=f[(1<<n)-1][x][s];
    }
    printf("%lld ",ans);
  }
  printf("\n");
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