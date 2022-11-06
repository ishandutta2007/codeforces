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
const int mn=2e5+4;
vector<int> g[mn];
int dp[mn];
int dfs(int x, int p) {
  int c[4]; memset(c,0,sizeof c);
  for (auto &y:g[x]) {
    if (y==p) continue;
    int t=dfs(y,x);
    c[t]++;
  }
  int ans=0;
  for (int d=0;d<2;d++) {
    int after=c[1<<1]+1-d;
    if ((after%2==0)||c[3]) {
      ans|=1<<d;
    }
  }
  if (ans==0) {
    printf("NO\n"); exit(0);
  }
  return dp[x]=ans;
}
vector<int> vfinal;
void go(int x, int d, int p) {
  assert(dp[x]&(1<<d));
  //printf("x:%d\n",x);
  vector<int> c[4];
  for (auto &y:g[x]) {
    //printf("y:%d dp:%d\n",y,dp[y]);
    if (y==p) continue;
    c[dp[y]].PB(y);
  }
  for (auto &y:c[1<<0]) {
    go(y,0,x);
  }
  int st=((c[1<<1].size()+1-d)%2!=0)?1:0;
  for (int i=st;i<c[3].size();i++) {
    go(c[3][i],0,x);
  }
  vfinal.PB(x);
  if (st) go(c[3][0],1,x);
  for (auto &y:c[1<<1]) {
    go(y,1,x);
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=1;i<=n;i++) {
    int pi=rint();
    if (pi!=0) {
      g[pi].PB(i);
      g[i].PB(pi);
    }
  }
  int got=dfs(1,-1);
  if (got&(1<<1)) {
    printf("YES\n");
    go(1,1,-1);
    for (auto &w:vfinal) printf("%d\n",w);
  }
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