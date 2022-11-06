#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using ll=__int128;
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
struct rational_t { ll nu, de;
  rational_t(const ll &n = 0, const ll &d = 1) {
    nu=n; de=d;
    //ll g = gcd(abs(n), abs(d)); nu = n / g; de = d / g;
    if (de < 0) { nu = -nu; de = -de; }
  }
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
using rat=rational_t;
int go() {
  int n; cin>>n;
  vector<long> a(n);
  for (ll i=0;i<n;i++) cin>>a[i];
  if (n==1) return 0;
  int best=INF;
  for (ll l=0;l<n;l++) {
    for (ll r=l+1;r<n;r++) {
      rat m=rat(a[r]-a[l],r-l);
      rat c=rat(a[l],ll(1))-m*rat(l,ll(1));
      int need=0;
      for (ll x=0;x<n;x++) {
        if (m*x+c == rat(a[x],ll(1))) {
        } else {
          need++;
        }
      }
      chkmin(best,need);
    }
  }
  return best;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) {
    int ans=go();
    printf("%d\n",ans);
  }
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