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
//#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

const int mn=23;
const int mz=1<<mn;
int gn;
bitset<mz> f;
unsigned char g[mz];
int go() {
  int n=gn;
  int zlim=1<<n;
  for (int k=0;k<n;k++) {
    int msk=1<<k;
    for (int z=0;z<zlim;z++) {
      if (msk&z) {
        f[z]=f[z]||f[z^msk];
      }
    }
  }
  for (int z=0;z<zlim;z++) {
    if (!f[z]) {
      for (int k=0;k<n;k++) {
        int msk=1<<k;
        if (z&msk) {
          f[z^msk]=1;
        }
      }
    }
  }
  vector<int> b;
  for (int z=0;z<zlim;z++) {
    if (!f[z]) {
      b.PB(z);
    }
  }
  memset(g,-1,sizeof g);
  g[0]=0;
  for (int z=0;z<zlim;z++) {
    unsigned char gz=g[z]+1;
    if (gz==(unsigned char)0) continue;
    dbg("z:%d gz:%d\n",z,g[z]);
    for (auto &w:b) {
      chkmin(g[w|z],gz);
    }
  }
  return g[zlim-1];
}

const int mx=47;
typedef int UFTYPE;
class UnionFind {
public:

// Custom
UFTYPE ufIdentity = 0;
inline UFTYPE combine(UFTYPE x, UFTYPE y) {
  return x+y;
}
inline UFTYPE getInitialValue(int x) {
  return 1;
}


int ufParent[mx];
UFTYPE ufData[mx];
inline void ufreset(int x) {
  ufParent[x]=x;
  ufData[x]=getInitialValue(x);
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
  if (rand()&1) swap(xr,yr);
  ufParent[xr] = yr;
  ufData[yr]=combine(ufData[xr],ufData[yr]);
}
void funionFast(int xr, int yr) {
  if (xr==yr) return;
  if (rand()&1) swap(xr,yr);
  ufParent[xr] = yr;
  ufData[yr]=combine(ufData[xr],ufData[yr]);
}
int getData(int x) {
  return ufData[ffind(x)];
}
int getDataFast(int x) {
  return ufData[x];
}
};
UnionFind uf;
string a[mx];
int v2i[mx];
void fail(int t) {
  //printf("Failed with type: %d\n",t);
  printf("-1\n");
  exit(0);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //test(); return 0;
  int n; cin>>n;
  for (int x=0;x<n;x++) {
    cin>>a[x];
  }
  uf.init(n);
  srand(clock());
  for (int x=0;x<n;x++) {
    for (int y=0;y<n;y++) {
      if (a[x][y]!=a[y][x]) {
        fail(1); // Input not symmetric
      }
    }
  }
  for (int x=0;x<n;x++) {
    for (int y=0;y<n;y++) {
      if (a[x][y]=='A') uf.funion(x,y);
    }
  }
  for (int x=0;x<n;x++) {
    for (int y=0;y<n;y++) {
      if (a[x][y]=='X') {
        if (uf.ffind(x)==uf.ffind(y)) {
          fail(2); // XOR and AND contradicts
        }
      }
    }
  }
  {
    set<int> s; for (int x=0;x<n;x++) {
      int xr=uf.ffind(x);
      if (uf.getDataFast(xr)>1) {
        dbg("x:%d xr:%d\n",x,xr);
        s.insert(xr);
      }
    }
    int idx=1;
    for (auto &w:s) {
      v2i[w]=idx;
      ++idx;
    }
    gn=idx-1;
    for (int x=0;x<n;x++) {
      for (int y=0;y<n;y++) {
        if (a[x][y]=='X') {
          int xx=uf.ffind(x),yy=uf.ffind(y);
          int vx=v2i[xx],vy=v2i[yy];
          if (vx>0&&vy>0) {
            vx--; vy--;
            int msk=((1<<vx)|(1<<vy));

            f[msk]=1;
          }
        }
      }
    }
  }
  int ans=go()+n-1;
  printf("%d\n",ans);
}