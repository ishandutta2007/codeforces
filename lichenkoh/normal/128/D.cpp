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

void fail(int t) {
  printf("NO\n"); exit(0);
}
vi a;
const int mn=1e5+4;
map<int,bool> dp[3][mn];
bool f(int ends, int x, int take) {
  //printf("ends:%d x:%d take:%d\n",ends,x,take);
  if (x==a.size()) {
    return (take==0);
  }
  auto it=dp[ends][x].find(take);
  if (it!=dp[ends][x].end()) return it->snd;
  int now=2*a[x]-take;
  if (now<0) return dp[ends][x][take]=false;
  for (int takeend=0;takeend<=min(ends,2);takeend++) {
    int newnow=now-takeend;
    if ((x==a.size()-1) && (newnow==0)) return dp[ends][x][take]=true;
    //printf("ends:%d x:%d take:%d now:%d newnow:%d\n",ends,x,take,now,newnow);
    if (newnow>0 && f(ends-takeend, x+1, newnow)) return dp[ends][x][take]=true;
  }
  return dp[ends][x][take]=false;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  if (n==1) {
    printf("YES\n"); exit(0);
  }
  map<int,int> h;
  for (int i=0;i<n;i++) {
    ++h[rint()];
  }
  int prev=(h.begin())->fst;
  for (auto &w:h) {
    if (w.fst>=prev+2) fail(1);
    prev=w.fst;
  }
  for (auto &w:h) a.PB(w.snd);
  bool final=f(0,0,0);
  if (final) printf("YES\n");
  else printf("NO\n");

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