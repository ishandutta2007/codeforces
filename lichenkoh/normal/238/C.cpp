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
const int mn=3002;
vector<int> g[mn];
bool rev[mn][mn];
int n;
int dfsinit(int x, int p) {
  int cost=0;
  for (auto &y:g[x]) {
    if (y==p) continue;
    //printf("x:%d y:%d rev:%d\n",x,y,rev[x][y]);
    cost+=rev[x][y]+dfsinit(y,x);
  }
  //printf("x:%d cost:%d\n",x,cost);
  return cost;
}
int dfsbest;
stack<int> S[2];
void dfs(int x, int p) {
  int dp0=S[0].top();
  int dp1=S[1].top();
  //printf("x:%d dp0:%d dp1:%d\n",x,dp0,dp1);
  chkmin(dfsbest,min(dp0,dp1));
  for (auto &y:g[x]) {
    if (y==p) continue;
    {
      S[1].push(min(dp0,dp1)+(rev[x][y]?-1:1));
    }
    {
      S[0].push(dp0);
    }
    dfs(y,x);
    for (int k=0;k<2;k++) S[k].pop();
  }
}
int go(int init) {
  int origcost=dfsinit(init,-1);
  //printf("origcost:%d\n",origcost);
  dfsbest=0;
  for (int k=0;k<2;k++) S[k].push(0);
  dfs(init,-1);
  for (int k=0;k<2;k++) S[k].pop();
  return origcost+dfsbest;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int i=0;i<n-1;i++) {
    int a=rint()-1,b=rint()-1;
    rev[b][a]=1;
    g[a].PB(b); g[b].PB(a);
  }
  int final=1<<30;
  for (int x=0;x<n;x++) {
  //for (int x=1;x<=1;x++) {
    int cand=go(x);
    //printf("x:%d cand:%d\n",x,cand);
    chkmin(final,cand);
  }
  printf("%d\n",final);
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