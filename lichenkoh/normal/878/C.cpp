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
const int mn=50000,mk=10;
int b[mk],s[mn][mk];
int hi[mk];
ll inp[mk][mn];
int win[mn];
int wid=1;
int k;
int ans=1;
int active=1;
void dfs(int x) {
  //if (win[x]==wid) return;
  win[x]=wid;
  ans++;
  for (int y=0;y<k;y++) {
    int l=s[x][y];
    int r=b[y];
    if (l<r) {
      b[y]=l;
      for (int t=l+1;t<r;t++) {
        int ch=inp[y][t]&0xffffffff;
        if (ch<active&&win[ch]!=wid) dfs(ch);
      }
    }
  }
}
inline ll MK(int x, int y) {
  return (((ll)x)<<32)|y;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  win[0]=1;
  int n=rint();k=rint();
  for (int x=0;x<n;x++) {
    for (int y=0;y<k;y++) {
      int val=rint();
      inp[y][x]=MK(val,x);
    }
  }
  for (int y=0;y<k;y++) {
    sort(inp[y],inp[y]+n);
    for (int i=0;i<n;i++) {
      int x=inp[y][i]&0xffffffff;
      s[x][y]=i;
    }
  }
  for (int y=0;y<k;y++) hi[y]=b[y]=s[0][y];
  printf("1\n");
  for (;active<n;active++) {
    int x=active;
    bool winall=1;
    for (int y=0;y<k;y++) {
      if (s[x][y]<hi[y]) winall=0;
    }
    if (winall) {
      for (int y=0;y<k;y++) b[y]=s[x][y];
      ans=1;
      ++wid;
      win[x]=wid;
    }
    else {
      bool canwin=0;
      for (int y=0;y<k;y++) {
        if (s[x][y]>b[y]) {
          canwin=1;
        }
      }
      if (canwin) {
        dfs(x);
      }
    }
    for (int y=0;y<k;y++) chkmax(hi[y],s[x][y]);
    printf("%d\n",ans);
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