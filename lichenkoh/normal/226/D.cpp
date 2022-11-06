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
const int mn=100;
int a[mn][mn];
int xs[mn],ys[mn];
bitset<mn> xm,ym;
bitset<mn> xa,ya;
int n,m;
void pt() {
  printf("\n");
  for (int x=0;x<n;x++) {
    for (int y=0;y<m;y++) printf("%d ",a[x][y]/2);
    printf("\n");
  }
  for (int x=0;x<n;x++) printf("x:%d xs:%d\n",x,xs[x]);
  for (int x=0;x<m;x++) printf("y:%d ys:%d\n",x,ys[x]);
  printf("xc%d yc%d\n",xm.count(),ym.count());
  printf("\n");
}
int inp[mn][mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),m=rint();
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
      int v=rint();
      inp[i][j]=v;
      a[i][j]=(v*2);
      xs[i]+=v; ys[j]+=v;
    }
  for (int x=0;x<n;x++) if (xs[x]<0) xm[x]=true;
  for (int y=0;y<m;y++) if (ys[y]<0) ym[y]=true;
  while(1){
    //pt();
    xa^=xm;
    for(int i=xm._Find_first();i< mn;i = xm._Find_next(i)) {
      //printf("Flip x:%d\n",i);
      int x=i;
      xs[x]=-xs[x];
      for (int y=0;y<m;y++) {
        int got=a[x][y];
        ys[y]-=got;
        if (ys[y]<0) ym[y]=true;
        else ym[y]=false;
        a[x][y]=-got;
      }
    }
    xm.reset();
    if (!ym.any()) break;
    //pt();
    ya^=ym;
    for(int i=ym._Find_first();i< mn;i = ym._Find_next(i)) {
      //printf("Flip y:%d\n",i);
      int y=i;
      ys[y]=-ys[y];
      for (int x=0;x<n;x++) {
        int got=a[x][y];
        xs[x]-=got;
        if (xs[x]<0) xm[x]=true;
        else xm[x]=false;
        a[x][y]=-got;
      }
    }
    ym.reset();
    if (!xm.any()) break;
  }

  memcpy(a,inp,sizeof a);
  for(int i=xa._Find_first();i< mn;i = xa._Find_next(i)) {
    for (int y=0;y<m;y++) a[i][y]=-a[i][y];
  }
  for(int i=ya._Find_first();i< mn;i = ya._Find_next(i)) {
    for (int x=0;x<n;x++) a[x][i]=-a[x][i];
  }
  for (int x=0;x<n;x++) {
    int sum=0;
    for (int y=0;y<m;y++) {
      sum+=a[x][y];
    }
    assert(sum>=0);
  }
  for (int y=0;y<m;y++) {
    int sum=0;
    for (int x=0;x<n;x++) {
      sum+=a[x][y];
    }
    assert(sum>=0);
  }

  printf("%d",xa.count());
  for(int i=xa._Find_first();i< mn;i = xa._Find_next(i)) printf(" %d",i+1);
  printf("\n");
  printf("%d",ya.count());
  for(int i=ya._Find_first();i< mn;i = ya._Find_next(i))  printf(" %d",i+1);
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