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
const ll INF=9187201950435737471;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
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
const int mn=51;
const int mx=5001;
ll f[2][mn][mn][mx];
pii a[mn];

//ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
struct rational_t { ll nu, de;
  rational_t(const ll &n = 0, const ll &d = 1) {
    //ll g = gcd(abs(n), abs(d)); nu = n / g; de = d / g;
    nu=n; de=d;
    if (de < 0) { nu = -nu; de = -de; } }
  rational_t operator+(const rational_t& b) const
  { return rational_t( nu*b.de+de*b.nu, de*b.de ); }
  rational_t operator-(const rational_t& b) const
  { return rational_t( nu*b.de-de*b.nu, de*b.de ); }
  rational_t operator-() { return rational_t(-nu, de); }
  rational_t operator*(const rational_t& b) const
  { return rational_t( nu*b.nu, de*b.de ); }
  rational_t operator/(const rational_t& b) const
  { return rational_t( nu*b.de, de*b.nu ); }
  bool operator== (const rational_t & b) const {return nu * b.de == b.nu * de;}
  bool operator== (const ll &k) const { return nu == k * de; }
  bool operator< (const rational_t& b) const { return nu * b.de < b.nu * de; }
  bool operator<= (const rational_t& b) const { return nu * b.de <= b.nu * de; }
  bool operator> (const rational_t& b) const { return nu * b.de > b.nu * de; }
  bool operator>= (const rational_t& b) const { return nu * b.de >= b.nu * de; }
};
typedef rational_t rat;
void rst(int cur) {
  memset(f[cur],0x7f,sizeof f[cur]);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) a[i].fst=rint();
  for (int i=0;i<n;i++) a[i].snd=rint();
  sort(a,a+n); reverse(a,a+n);
  //for (int i=0;i<n;i++) printf("%d %d\n",a[i].fst,a[i].snd);
  rst(0);
  f[0][0][0][0]=0;
  int cur=0,nxt=1;
  int clim=0;
  for (int i=0;i<n;i++) {
    rst(nxt);
    int xlim=i*100;
    if (i>0&&a[i].fst!=a[i-1].fst) {
      for (int s=0;s<=i;s++) for (int c=0;c<=i-s;c++) for (int x=0;x<=xlim;x++) {
        chkmin(f[cur][s+c][0][x],f[cur][s][c][x]);
      }
      clim=0;
    }
    for (int s=0;s<=i;s++) for (int c=0;c<=i-s;c++) for (int x=0;x<=xlim;x++) {
      ll now=f[cur][s][c][x];
      if (now==INF) continue;
      if (s>0) chkmin(f[nxt][s-1][c][x],now);
      chkmin(f[nxt][s][c+1][x+a[i].snd], now+a[i].fst);
    }
    swap(cur,nxt);
  }
  rat best=rat(((ll)5e9)+100LL,1);
  for (int s=0;s<mn;s++) for (int c=0;c<mn;c++) for (int x=1;x<mx;x++) {
    ll now=min(f[cur][0][s][x],f[cur][1][s][x]);
    if (now==INF) continue;
    chkmin(best, rat(now,x));
  }
  //printf("%lld %lld\n",best.nu,best.de);
  ll ans=((best.nu*1000LL)+best.de-1LL)/best.de;
  printf("%lld\n",ans);
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