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

const int mn=102;
int a[6][mn];
int l;
vi vb,vr,vc;
void succ() {
  int t=vb.size();
  printf("%d\n",t);
  for (int i=0;i<t;i++) {
    printf("%d %d %d\n",vb[i],vr[i],vc[i]);
  }
  exit(0);
}
bool ch=0;
void mv(int orow, int oc, int r, int c) {
  int i=a[orow][oc];
  if (i==0) return;
  ch=1;
  a[orow][oc]=0;
  //printf("i:%d r:%d c:%d\n",i,r,c);
  vb.PB(i);vr.PB(r);vc.PB(c);
  a[r][c]=i;
}
void park(int orow,int oc, int r, int c) {
  mv(orow,oc,r,c);
  --l;
  if (l==0) succ();
}
void fail() {
  printf("-1\n"); exit(0);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),k=rint();
  for (int r=1;r<=4;r++) for (int c=1;c<=n;c++) a[r][c]=rint();
  l=k;
  while(1) {
    ch=0;
    for (int d=0;d<2;d++) {
    for (int k=0;k<2;k++) {
      for (int r=2;r<=3;r++) {
        int o=(r==2)?1:4;
        for (int c=1;c<=n;c++) {
          if (a[r][c]!=0&&a[r][c]==a[o][c]) {
            park(r,c,o,c);
          }
        }
      }
      {
        int r=2;
        for (int c=n;c>=2;c--) {
          if (a[r][c-1]!=0&&a[r][c]==0) mv(r,c-1,r,c);
        }
        if (a[3][1]!=0&&a[2][1]==0) mv(3,1,2,1);
      }
      {
        int r=3;
        for (int c=1;c<=n-1;c++) {
          if (a[r][c+1]!=0&&a[r][c]==0) mv(r,c+1,r,c);
        }
      }
    }
    if (a[2][n]!=0&&a[3][n]==0) mv(2,n,3,n);}

    if (!ch) {
      fail();
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