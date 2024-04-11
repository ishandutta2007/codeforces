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
const int mn=1e3+2;
bool a[mn][mn];

const int mx=1e2+2;
typedef int UFTYPE;
class UnionFind {
public:

// Custom
    UFTYPE ufIdentity = -1;
    inline UFTYPE combine(UFTYPE x, UFTYPE y) {
      return max(x,y);
    }
    inline UFTYPE getInitialValue(int x) {
      return x;
    }


    int ufParent[mx];
    int rank[mx];
    UFTYPE ufData[mx];
    inline void ufreset(int x) {
      ufParent[x]=x;
      ufData[x]=getInitialValue(x);
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
      int xr = ffind(_x);
      int yr = ffind(_y);
      if (xr==yr) return;
      if (rank[xr] > rank[yr]) swap(xr,yr);
      if (rank[xr]==rank[yr]) rank[yr]++;
      ufParent[xr] = yr;
      ufData[yr]=combine(ufData[xr],ufData[yr]);
    }
    int getDataForPos(int x) {
      return ufData[x];
    }
};

vector<int> vx[1111],vy[1111];
UnionFind uf;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {
    int x=rint(),y=rint();
    vx[x].PB(i);
    vy[y].PB(i);
  }
  uf.init(n);
  for (int x=1;x<=1000;x++) {
    for (int i=1;i<vx[x].size();i++) {
      uf.funion(vx[x][i],vx[x][i-1]);
    }
  }
  for (int x=1;x<=1000;x++) {
    for (int i=1;i<vy[x].size();i++) {
      uf.funion(vy[x][i],vy[x][i-1]);
    }
  }
  int ans=0;
  for (int i=0;i<n;i++) {
    if (uf.ffind(i)==i) {
      ans++;
    }
  }
  ans--;
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