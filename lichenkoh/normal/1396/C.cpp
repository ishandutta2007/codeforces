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

const int mn=(1e6)+4;

enum {
  CLEAR,
  BACKFWD,
  BACKLAST,
  enumSize
};

ll n,d;
ll gPISTOL,gLASER,gAWP;

ll a[mn],vevery[mn],vbroken[mn];
ll dp[mn][enumSize];

void EveryBroken(int pos) {
  ll pistol=gPISTOL,laser=gLASER,awp=gAWP;
  chkmin(laser,pistol * (a[pos]+1LL));
  ll every=(pistol*a[pos])+awp;
  ll broken=min(laser+min(laser,pistol), every);
  chkmin(every, broken+2*d);
  vevery[pos]=every;
  vbroken[pos]=broken;
}

ll f(int pos, int state) {
  ll dpval=dp[pos][state];
  if (dpval!=-1) return dp[pos][state];

  ll every=vevery[pos];
  ll broken=vbroken[pos];
  if (pos==n) {
    if (state==BACKFWD) {
      return broken;
    } else {
      return every;
    }
  }
  ll final=LLONG_MAX/2;
  if (state==CLEAR) {
    { // Clear everything, then forward
      chkmin(final, every+d+f(pos+1,CLEAR));
    }
    { // Laser
      chkmin(final, 3*d+broken+f(pos+1,BACKFWD));
      chkmin(final, 2*d+broken+f(pos+1,BACKLAST));
    }
  } else if (state==BACKFWD) {
    { // Laser, then go forward
      chkmin(final, 3*d+broken+f(pos+1,BACKFWD));
    }
    { // Laser, then go backward, then forward again
      chkmin(final, broken+d+f(pos+1,CLEAR));
    }
  } else if (state==BACKLAST) {
    { // Laser, then go forward
      chkmin(final, 2*d+broken+f(pos+1,BACKLAST));
    }
  }
  return dp[pos][state]=final;
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(dp,-1,sizeof dp);
  cin>>n>>gPISTOL>>gLASER>>gAWP>>d;
  chkmin(gPISTOL, gAWP);
  for (int i=1;i<=n;i++) cin>>a[i];
  for (int i=1;i<=n;i++) EveryBroken(i);
  ll finalans=f(1,CLEAR);
  printf("%lld\n",finalans);
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