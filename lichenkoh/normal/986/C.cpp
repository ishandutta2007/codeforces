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
const int mn=22;
const int mz=1<<mn;

const int mx=mz;
class UnionFind {
public:
  int ufParent[mx];
  int rank[mx];
  inline void ufreset(int x) {
    ufParent[x]=x;
    rank[x]=0;
  }
  void init(int n) {
    for (int x=0;x<n;x++) {
      ufreset(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    if (_x==-1 || _y==-1) return;
    //printf("funion: %d %d\n",_x,_y);
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
  }
};
UnionFind uf;

bitset<mz> a;
bitset<mz> f;
int g[mz];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int k=rint(),m=rint(); int zlim=1<<k;
  uf.init(1<<k);
  for (int i=0;i<m;i++) {int x=rint();a[x]=true;f[x^(zlim-1)]=true;}
  for (int i=0;i<k;i++) {
    for (int z=0;z<(1<<k);z++) {
      if (0==(z&(1<<i))) {
        f[z]=f[z]||f[z^(1<<i)];
      }
    }
  }
  memset(g,-1,sizeof g);
  for (int z=0;z<(1<<k);z++) if (a[z]) g[z]=z;
  for (int i=0;i<k;i++) {
    for (int z=0;z<(1<<k);z++) {
      if ((z&(1<<i))) {
        if (f[z]) {
          //if (g[z]!=-1&&g[z^(1<<i)]!=-1) printf("z:%d z^(1<<%d):%d\n",z,i,z^(1<<i));
          uf.funion(g[z],g[z^(1<<i)]);
        }
        chkmax(g[z],g[z^(1<<i)]);
      }
    }
  }
  //printf("NEG\n");
  for (int z=0;z<(1<<k);z++) {
    uf.funion(g[z],g[z^(zlim-1)]);
  }
  int ans=0;
  for (int z=0;z<(1<<k);z++) {
    if (a[z] && uf.ffind(z)==z) ans++;
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