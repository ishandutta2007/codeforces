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
const int mn=5004;
ll h[mn];
int a[mn];
/*void check(int n, int k) {
  for (int x=1;x<=n;x++) assert(a[x]<= -1+(int)(1e9));
  for (int x=2;x<=n;x++) assert(a[x-1]<a[x]);
  int c=0;
  for (int x=1;x<=n;x++) for (int y=1;y<x;y++) for (int z=1;z<y;z++) if (a[z]+a[y]==a[x]) {c++; printf("%d %d %d\n",a[z],a[y],a[x]);}
  assert(c==k);
}*/
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int k=rint();
  for (int x=1;x<=n;x++) {
    int lt=(x-1)/2;
    h[x]=h[x-1]+lt;
    //printf("x:%d h:%lld\n",x,h[x]);
  }
  if (k>h[n]) {printf("-1"); return 0;}
  int T;
  for (int t=1;t<=n;t++) {
    if (h[t]<=k) T=t;
  }
  for (int x=1;x<=T;x++) a[x]=x;
  if (T<n) {
    // T+1 should take leftovers
    int left=k-h[T];
    int diff=T-left*2;
    //printf("left:%d diff:%d\n",left,diff);
    a[T+1]=T+1+diff;
    
    int g=1+a[T+1];
    int s=1e8;
    for (int x=T+2;x<=n;x++) {
      a[x]=s;
      s+=g;
    }
  }
  //check(n,k);
  for (int x=1;x<=n;x++) printf("%d ",a[x]);
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