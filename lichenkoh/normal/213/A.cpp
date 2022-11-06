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
const int mn=204;
int n;
vector<int> og[mn];
vector<int> org[mn];
int vc[mn];
int go(int init) {
  vector<int> g[mn],rg[mn];
  int deg[mn];
  for (int x=1;x<=n;x++) {
    g[x]=og[x]; rg[x]=org[x];
  }
  for (int x=1;x<=n;x++) deg[x]=g[x].size();
  queue<int> avail[4];
  for (int x=1;x<=n;x++) {
    if (deg[x]==0) avail[vc[x]].push(x);
  }
  int ans=-1;
  int lft=n;
  int t=init;
  while(lft>0) {
    ans++;
    while(!avail[t].empty()) {
      int x=avail[t].front();
      avail[t].pop();
      ans++;
      lft--;
      for (auto &y:rg[x]) {
        deg[y]--;
        if (deg[y]==0) {
          avail[vc[y]].push(y);
        }
      }
    }
    t=t-1;
    t=t+1;
    t%=3;
    t=t+1;
  }
  return ans;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int i=1;i<=n;i++) vc[i]=rint();
  for (int i=1;i<=n;i++) {
    int k=rint();
    for (int j=0;j<k;j++) {
      int x=i,y=rint();
      og[x].PB(y);
      org[y].PB(x);
    }
  }
  int final=1e9;
  for (int s=1;s<=3;s++) {
    int got=go(s);
    chkmin(final,got);
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