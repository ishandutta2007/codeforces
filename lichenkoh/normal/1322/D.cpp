#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mk=12;
const int mn=2000+mk+2;
int g[mn][mk][mn];
int h[mn];
int f[mn];
int p2l[mn],p2s[mn],l2c[mn*2];

int ilog2(int x) {
  return 31 - __builtin_clz(x);
}

void upd(int l, int t, int d) {
  if (t==0) return;
  //int logt=ilog2(t);
  int sumd=d;
  for (int k=0;k<mk;k++) {
    //printf("l:%d k:%d t>>k:%d sumd:%d\n",l,k,t>>k,sumd);
    chkmax(g[l][k][t>>k],sumd);
    sumd+=l2c[l+k] * (t>>k);
  }
  chkmax(h[l],sumd);
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int x=0;x<mn;x++) h[x]=-INF;
  for (int x=0;x<mn;x++) for (int y=0;y<mk;y++) for (int z=0;z<mn;z++) g[x][y][z]=-INF;
  for (int x=0;x<mn;x++) g[x][0][0]=0;
  int n=rint(),m=rint();
  for (int p=1;p<=n;p++) p2l[p]=rint();
  for (int p=1;p<=n;p++) p2s[p]=rint();
  for (int l=1;l<=n+m;l++) l2c[l]=rint();

  for (int p=n;p>=1;p--) {
    for (int t=0;t<mn;t++) f[t]=-INF;
    f[0]=0;
    int l=p2l[p];
    for (int q=0;q<=l-mk;q++) chkmax(f[0], h[q]);
    for (int k=0;k<mk;k++) {
      if (l-k<0) continue;
      for (int t=0;t<=((mn-1)>>k);t++) {
        int got=g[l-k][k][t];
        if (got==-INF) continue;
        //printf("l-k:%d k:%d t:%d g:%d\n",l-k,k,t,got);
        chkmax(f[t], got);
      }
    }
    for (int t=0;t<mn-1;t++) {
      //if (f[t]>0) printf("p:%d t:%d f:%d\n",p,t,f[t]);
      if (f[t]==-INF) continue;
      int d=f[t] - p2s[p];
      upd(l,t+1,d);
    }
  }
  int ans=0;
  for (int l=0;l<mn;l++) {
    for (int t=0;t<mn;t++) {
      int d=g[l][0][t];
      if (d==-INF) continue;
      int od=d;
      for (int k=0;k<mk;k++) {
        d+=l2c[l+k] * (t>>k);
      }
      //if (d>0) printf("l:%d t:%d d:%d od:%d\n",l,t,d,od);
      chkmax(ans,d);
    }
  }
  printf("%d\n",ans);
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