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
const int mn=32;
int tmp[mn];
int n,u,r;
vi b, k, p;
inline void do1(vi &a) {
  for (int x=0;x<n;x++) a[x]^=b[x];
}
inline void do2(vi &a) {
  for (int x=0;x<n;x++) tmp[x]=a[p[x]]+r;
  for (int x=0;x<n;x++) a[x]=tmp[x];
}
ll go(int t, int o, vi a) {
  if (t==0) {
    if (o&1) do1(a);
    ll ans=0;
    for (int x=0;x<n;x++) ans+=a[x]*k[x];
    return ans;
  }
  else {
    ll ans=-(1LL<<62);
    if (o>0) {
      vi na=a;
      do1(na);
      do2(na);
      chkmax(ans,go(t-1,o-1,na));
    }
    do2(a);
    chkmax(ans,go(t-1,o,a));
    return ans;
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),u=rint(),r=rint();
  vi a; a.resize(n),b.resize(n),k.resize(n),p.resize(n);
  for (int x=0;x<n;x++) a[x]=rint();
  for (int x=0;x<n;x++) b[x]=rint();
  for (int x=0;x<n;x++) k[x]=rint();
  for (int x=0;x<n;x++) p[x]=rint()-1;
  ll final=-(1LL<<62);
  for (int t=0;t<=u;t++) {
    int o=u-t;
    ll got=go(t,o,a);
    chkmax(final,got);
  }
  printf("%lld\n",final);
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