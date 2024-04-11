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
const int INF=((1<<30)-1);
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
const int mn=1e5+2;
pii a[mn];
int b[mn];
int vans[mn];
int l,s;
int h;
int f(int x) {
  if (x<l) return (x&1)^s;
  return 0;
}
int g(int x, int y) {
  int cand=b[x]+b[y];
  if (f(x)!=f(y)) cand+=h;
  return cand;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();h=rint();
  for (int i=0;i<n;i++) {
    a[i].fst=rint();
    a[i].snd=i;
  }
  sort(a,a+n);
  for (int i=0;i<n;i++) b[i]=a[i].fst;
  int final=INF;
  pii setting=MP(-1,-1);
  for (l=0;l<=n;l++) {
    for (s=0;s<2;s++) {
      int hi=0;
      {
        int ilo=max(0,n-4);
        for (int x=ilo;x<n;x++) {
          for (int y=ilo;y<x;y++) {
            int cand=g(x,y);
            chkmax(hi,cand);
          }
        }
        for (int x=max(0,l-4);x<l;x++) {
          for (int y=ilo;y<n;y++) {
            if (x==y) continue;
            int cand=g(x,y);
            chkmax(hi,cand);
          }
        }
      }
      int lo=hi;
      {
        int ihi=min(n-1,4);
        for (int x=0;x<ihi;x++) {
          for (int y=0;y<x;y++) {
            int cand=g(x,y);
            chkmin(lo,cand);
          }
        }
      }
      int got=hi-lo;
      //if (got==2) printf("lo:%d hi:%d\n",lo,hi);
      if (got<final) {
        final=got;
        setting=MP(l,s);
      }
    }
  }
  printf("%d\n",final);
  l=setting.fst; s=setting.snd;
  for (int i=0;i<n;i++) {
    vans[a[i].snd]=f(i)+1;
  }
  for (int i=0;i<n;i++) printf("%d ",vans[i]);
  printf("\n");
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