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
const int mn=5004;
int a[mn];
int f[mn][mn];
int pre[mn];
int query(int l, int r) {
  return pre[r+1]-pre[l];
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int x=0;x<n;x++) a[x]=rint();
  for (int x=0;x<n;x++) pre[x+1]=pre[x]+a[x];
  for (int x=0;x<=n;x++) for (int c=0;c<=n;c++) f[x][c]=INT_MAX;
  f[0][0]=0;
  for (int x=0;x<n;x++) {
    int ax=a[x];
    for (int c=0;c<=n;c++) {
      int prev=f[x][c];
      if (prev==INT_MAX) continue;
      {
        int imin=x,imax=n;
        while(imin<imax) {
          int imid=(imin+imax)>>1;
          if (query(x,imid)<prev) imin=imid+1;
          else imax=imid;
        }
        if (imin<n) {
          int qq=query(x,imin);
          chkmin(f[imin+1][c+imin-x],qq);
        }
      }
      {
        chkmin(f[x+1][c+1],prev+ax);
      }
    }
  }
  for (int c=0;c<=n;c++) {
    if (f[n][c]!=INT_MAX) {
      printf("%d\n",c);
      return 0;
    }
  }
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