// DP. Only count up to 20 bonuses, otherwise use immediately
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
const int INF=(1<<30)-1;
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

const int mn=3e5+4;
int a[mn];
const int mr=32;
int f[2][mr+1][2];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {
    int x=rint();
    if (x==1000) a[i]=1;
    else a[i]=2;
  }
  int sum=0;
  for (int i=0;i<n;i++) sum+=a[i];
  int cur=0,nxt=1;
  memset(f[cur],-1,sizeof f[cur]);
  f[cur][0][0]=0;
  for (int x=0;x<n;x++) {
    memset(f[nxt],-1,sizeof f[nxt]);
    int val=a[x];    
    for (int r=0;r<=mr;r++) {
      int bonus=r;
      for (int p=0;p<2;p++) {
        int orig=f[cur][r][p];
        if (orig==-1) continue;
        int rval=r+val;
        if (rval<=mr) {
          chkmax(f[nxt][rval][p],orig);
          //printf("nxt:%d rval:%d p:%d orig:%d\n",nxt,rval,p,orig);
          //printf("x:%d r:%d p:%d orig:%d rval:%d\n",x,r,p,orig,rval);
        }
        int np=(val+p)&1;
        int use=min(bonus,val*10);
        int cand=orig+use;
        chkmax(f[nxt][r-use][np], cand);
      }
    }
    swap(cur,nxt);
  }
  int final=0;
  for (int r=0;r<=mr;r++) {
    for (int p=0;p<2;p++) {
      chkmax(final,f[cur][r][p]);
    }
  }
  ll lfinal=sum*1000ll-final*100ll;
  printf("%lld\n",lfinal);
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