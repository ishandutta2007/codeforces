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
const int mn=(2e5)+4;
set<int> g[mn];
int dp[mn];
int dfs(int x) {
  if (dp[x]!=-1) return dp[x];
  int ans=0;
  for (auto &y:g[x]) {
    chkmax(ans,dfs(y)+1);
  }
  return dp[x]=ans;
}
vi d2x[mn];
char col[mn];

void solve(int n) {
  for (int d=n+1;d>=0;d--) {
    for (auto &x:d2x[d]) {
      if (col[x]=='?') {
        //printf("%d R\n",x);
        col[x]='R';
        for (auto &y:g[x]) {
          assert(col[y]!='R');
          if (col[y]=='?') {
            //printf("%d marked for N\n",y);
            col[y]='N';
          }
        }
      } else if (col[x] == 'N') {
        //printf("%d N\n",x);
        for (auto &y:g[x]) {
          //printf("%d C\n",y);
          col[y]='C';
        }
      }
    }
  }
}

void go() {
  int n,m; cin>>n>>m;
  for (int x=0;x<=n+1;x++) {
    g[x].clear();
    dp[x]=-1;
    d2x[x].clear();
    col[x]='?';
  }
  for (int i=1;i<=m;i++) {
    int x,y; cin>>x>>y;
    g[x].insert(y);
  }
  for (int x=1;x<=n;x++) {
    d2x[dfs(x)].PB(x);
  }
  solve(n);
  vi vans;
  for (int x=1;x<=n;x++) if (col[x]=='C') vans.PB(x);
  int num=vans.size();
  printf("%d\n",(int)vans.size());
  for (auto &ans:vans) printf("%d ",ans);
  printf("\n");
  if(num > (4*n)/7) {
    printf("%d %d\n",n,m);
    for (int x=1;x<=n;x++) for (auto &y:g[x]) printf("%d %d\n",x,y);
    fflush(stdout);
    assert(0);
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) {
    //printf("test %d\n",i);
    go();
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