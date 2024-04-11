#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=2e5;
int a[mn][2][2];
int b[mn][2][2];
int u[mn][2][2],g[2][2];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int i=1;i<=n;i++) {
     for (int s=0;s<2;s++)for (int c=0;c<2;c++) cin>>a[i][c][s];
  }

  for (int c=0;c<2;c++) {
    for (int s=0;s<2;s++) {
      if (s==0) b[0][c][s]=-INF;
      else b[0][c][s]=INF;
      if (s==0) u[n+1][c][s]=-INF;
      else u[n+1][c][s]=INF;
      for (int i=1;i<=n;i++) {
        if (s==0) b[i][c][s]=max(b[i-1][c][s],a[i][c][s]);
        else b[i][c][s]=min(b[i-1][c][s],a[i][c][s]);
      }
      for (int i=n;i>=1;i--) {
        if (s==0) u[i][c][s]=max(u[i+1][c][s],a[i][c][s]);
        else u[i][c][s]=min(u[i+1][c][s],a[i][c][s]);
      }
    }
  }

  for (int i=1;i<=n;i++) {
    for (int c=0;c<2;c++) for (int s=0;s<2;s++) {
      if (s==0) g[c][s]=max(b[i-1][c][s],u[i+1][c][s]);
      else g[c][s]=min(b[i-1][c][s],u[i+1][c][s]);
    }
    bool ok=1;
    for (int c=0;c<2;c++) {
      if(g[c][0]>g[c][1]) ok=0;
    }
    if (ok) {
      cout<<g[0][0]<<" "<<g[1][0]<<endl;
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