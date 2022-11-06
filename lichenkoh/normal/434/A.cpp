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
const ll INF=9e18;
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
const ll mn=1e5+4;
ll a[mn];
vector<int> g[mn];
ll m;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll _n=readInt();
  m=readInt();
  for (ll i=0;i<m;i++) {
    ll x=readInt();
    a[i]=x;
    g[x].PB(i);
  }
  ll base=0;
  for (ll i=0;i<m-1;i++) {
    base+=abs(a[i+1]-a[i]);
  }
  ll delta=0;
  for (ll src=0;src<=_n;src++) {
    vector<int> v;
    for (auto &si:g[src]) {
      if (si-1>=0) {
        int w=a[si-1];
        if (w!=src) v.PB(w);
      }
      if (si+1<m)  {
        int w=a[si+1];
        if (w!=src) v.PB(w);
      }
    }
    sort(v.begin(),v.end());
    if(v.size()>0) {
      ll dest=v[v.size()/2];
      ll old=0,nw=0;
      for (auto &w:v) {
        old+=abs(src-w);
        nw+=abs(dest-w);
      }
      chkmin(delta,nw-old);
    }
  }
  ll final=base+delta;
  printf("%lld\n",final);
}