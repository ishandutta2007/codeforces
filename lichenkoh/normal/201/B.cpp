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
int a[1002][1002];
int inp[1002][1002];
pair<ll,int> solve(int n, int m) {
  ll sumx=0;
  ll sumd=0;
  for (int x=1;x<=n;x++) {
    for (int y=1;y<=m;y++) {
      int xx=(2+(x-1)*4);
      //printf("x:%d xx:%d\n",x,xx);
      sumx+=xx*a[x][y];
      sumd+=a[x][y];
    }
  }
  if (sumd==0) {
    return MP(0ll,0);
  }
  int avgx=round(sumx/(ld)(4ll*sumd));
  pair<ll,int> best=MP(1LL<<62,0);
  for (int aax=max(0,avgx-3);aax<=min(n,avgx+3);aax++) {
    int ax=aax*4;
    ll dev=0;
    for (int x=1;x<=n;x++) {
      int xx=(2+(x-1)*4);
      int diff=xx-ax;
      ll diff2=diff*(ll)diff;
      for (int y=1;y<=m;y++) {
        dev+=diff2*a[x][y];
        //printf("diff:%d diff2:%lld axy:%d\n",diff,diff2,a[x][y]);
      }
    }
    //printf("dev:%lld ax:%d n:%d\n",dev,ax,n);
    chkmin(best,MP(dev,ax));
  }
  return best;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int x=1;x<=n;x++) {
    for (int y=1;y<=m;y++) {
      a[x][y]=inp[x][y]=rint();
    }
  }
  pair<ll,int> xx=solve(n,m);
  for (int x=1;x<=n;x++) for (int y=1;y<=m;y++) a[y][x]=inp[x][y];
  pair<ll,int> yy=solve(m,n);
  ll dev=xx.fst+yy.fst;
  printf("%lld\n",dev);
  printf("%d %d\n",xx.snd/4,yy.snd/4);
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