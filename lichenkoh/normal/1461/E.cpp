#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include <assert.h>
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
ll lolim,hilim,drink,topup;
const int mn=(1e6)+2;
bitset<mn> seen;
bool solve(ll init, ll days) {
  // Set up until we cannot topup anymore
  if (init+topup<=hilim) init+=topup;
  ll daychange=topup-drink;
  if (daychange==0) {
    return (init-drink)>=lolim;
  }
  else if (daychange<0) {
    ll lastlevel=init+(days-1)*daychange-drink;
    return lastlevel >= lolim;
  } else {
    ll daysToHiLim=(hilim-init)/daychange;
    days-=daysToHiLim;
    init+=daychange * daysToHiLim;
    ll level=init;
    seen[level%drink]=true;
      assert(seen[level%drink]);
      assert(level+topup>hilim);
      assert(lolim<=level);
      assert(level<=hilim);
    while(1) {
      assert(seen[level%drink]);
      assert(level+topup>hilim);
      assert(lolim<=level);
      assert(level<=hilim);
      ll dayToLo = min(days,(level+topup-hilim+drink-1)/drink);
      ll loLevel=level-dayToLo*drink;
      //printf("level:%lld days:%lld dayToLo:%lld loLevel:%lld num:%lld den:%lld\n",
      //  level,days,dayToLo,loLevel,(init+topup-hilim+drink-1),drink);
      if (loLevel<lolim) return false;
      days-=dayToLo;
      if (days<=0) return true;
      ll newLevel=loLevel+topup;
      int newMod=newLevel%drink;
      if (seen[newMod]) return true;
      seen[newMod]=true;
      //printf("level:%lld newLevel:%lld\n",level,newLevel);
      level=newLevel;
    }
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll init,days;
  init=rlong();
  lolim=rlong();
  hilim=rlong();
  days=rlong();
  drink=rlong();
  topup=rlong();
  assert(lolim<=init);
  assert(init<=hilim);
  assert(drink<mn);
  bool ans=solve(init,days);
  printf(ans?"Yes\n":"No\n");
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