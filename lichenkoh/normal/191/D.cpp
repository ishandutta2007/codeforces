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
//#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=1e5+2;

vector<int> vcyc[mn];
vector<int> g[mn];
bitset<mn> seen;
bitset<mn> cyced;
int dfs(int x, int p) {
  if (seen[x]) {
    vcyc[x].PB(x);
    cyced[x]=true;
    return x;
  }
  seen[x]=true;
  int retc=0;
  for (auto &y:g[x]) {
    if (y==p||cyced[y]) continue;
    int c=dfs(y,x);
    if (c==x) c=0;
    if (c) {
      dbg("x:%d y:%d c:%d\n",x,y,c);
      vcyc[c].PB(x);
      cyced[x]=true;
      assert(retc==0);
      retc=c;
    }
  }
  return retc;
}
int f[3][3];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  int final=0;
  dfs(1,-1);
  /*for (int x=1;x<=n;x++) {
    if (!seen[x]) dfs(x,-1);
  }*/
  f[0][0]=2;
  f[0][1]=2;
  f[0][2]=0;
  f[1][0]=2;
  f[1][1]=0;
  f[1][2]=0;
  for (int x=1;x<=n;x++) {
    int sz = vcyc[x].size();
    if (sz) { // Cycle
      int even=0,one=0;
      for (auto &y:vcyc[x]) {
        if (g[y].size()>=4 && (g[y].size()&1)==0) even++;
        if (g[y].size()&1) one++;
        //printf("x%d y%d sz%d\n",x,y,(int)g[y].size());
      }
      int ff=f[min(even,2)][min(one,2)];
      //printf("x%d b%d o%d f:%d\n",x,even,one,ff);
      final+=ff;
    }
  }
  for (int x=1;x<=n;x++) {
    if (1==(g[x].size()&1)) {
      //printf("x:%d\n",x);
      final++;
    }
  }
  //assert(0==(final&1));
  printf("%d %d\n",(final+1)>>1,m);
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