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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mk=5;
const int mn=(1e5)+mk+4;
int a[mn];
ll f[mk][2][mn];
void go() {
  int n=rint();
  for (int i=0;i<n;i++) f[0][0][i]=f[0][1][i]=a[i]=rint();
  for (int k=1;k<mk;k++) for (int i=0;i<n;i++) {
    f[k][0][i]=LLONG_MIN;
    f[k][1][i]=LLONG_MAX;
  }
  for (int k=0;k<mk-1;k++) {
    for (int i=1;i<n;i++) chkmax(f[k][0][i],f[k][0][i-1]);
    for (int i=1;i<n;i++) chkmin(f[k][1][i],f[k][1][i-1]);
    for (int i=1;i<n;i++) {
      if (f[k][0][i-1] != LLONG_MIN) {
        ll c0=f[k][0][i-1]*a[i];
        chkmax(f[k+1][0][i], c0);
        chkmin(f[k+1][1][i], c0);
      }
      if (f[k][1][i-1] != LLONG_MAX) {
        ll c1=f[k][1][i-1]*a[i];
        chkmax(f[k+1][0][i], c1);
        chkmin(f[k+1][1][i], c1);
      }
    }
  }
  ll ans=LLONG_MIN;
  for (int i=0;i<n;i++) chkmax(ans,f[mk-1][0][i]);
  printf("%lld\n",ans);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t=rint(); for (int i=0;i<t;i++) go();
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