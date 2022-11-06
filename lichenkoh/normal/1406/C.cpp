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

int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}


vi getCentroids(vvi const & g) {
  int n=g.size();
  vi centroids;
  vi sz(n);
  function<int (int,int)> dfs = [&](int u, int prev) {
    int szu=1;
    bool is_centroid = true;
    for (auto &v :g[u]) if (v!=prev) {
      int szv=dfs(v,u);
      szu += szv;
      if (szv > n/2) is_centroid = false;
    }
    if (is_centroid && n - szu <= n/2) {
      centroids.PB(u);
    }
    return szu;
  };
  dfs(0,-1);
  return centroids;
}

int getEdge(vvi const & g, int x, int p) {
  for (auto &y:g[x]) {
    if (y!=p) {
      return y;
    }
  }
  assert(0);
  return -1;
}

void go() {
  int n=rint();
  int ex,ey;
  vvi g(n);
  for (int i=1;i<n;i++) {
    int x=rint()-1,y=rint()-1;
    ex=x; ey=y;
    g[x].PB(y); g[y].PB(x);
  }

  vi vc = getCentroids(g);
  if (vc.size()==1) {
    printf("%d %d\n%d %d\n",ex+1,ey+1,ex+1,ey+1);
  } else {
    int s=getEdge(g,vc[0],vc[1]);
    printf("%d %d\n%d %d\n",vc[0]+1,s+1,vc[1]+1,s+1);
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t=rint(); for (int i=0;i<t;i++) go();
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