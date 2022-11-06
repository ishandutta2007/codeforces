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

void makeunique(vector<int> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
int bins(vector<int> &vx, int x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
const int mn=(1<<14)+8;
const int mg=mn*48;
const int mx=mg+mn;

int ufParent[mx];
void init(int n) {
  for (int x=0;x<n;x++) {
    ufParent[x]=x;
  }
}
int ffind(int x) {
  if (ufParent[x] != x) {
    ufParent[x] = ffind(ufParent[x]);
  }
  return ufParent[x];
}
int funion(int _x, int _y) {
  int xr = ffind(_x);
  int yr = ffind(_y);
  if (xr==yr) return 0;
  //printf("xr:%d yr:%d\n",xr,yr);
  if (rand()&1) swap(xr,yr);
  ufParent[xr] = yr;
  return 1;
}


int f[2][mn];
int gid;
int n,m;
vector<int> vx;
void remap(int prev) {
  if (gid>=mg) {
    for (int x = 0; x < m; x++) {
      if (f[prev][x] == -1) continue;
      f[prev][x] = ffind(f[prev][x]);
    }
    vx.resize(m);
    for (int x = 0; x < m; x++) {
      if (f[prev][x] == -1) continue;
      vx[x] = f[prev][x];
    }
    makeunique(vx);
    for (int x = 0; x < m; x++) {
      if (f[prev][x] == -1) continue;
      f[prev][x] = bins(vx, f[prev][x]);
    }
    int vxsz=vx.size();
    gid =vxsz - 1;
    init(vxsz);
  }
}
char ss[mn+4];
bitset<mn> b;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%d%d\n",&n,&m);
  int cur=0,prev=1;
  memset(f[prev],-1,sizeof f[cur]);
  //init(mx);
  int ans=0;
  for (int nn=0;nn<n;nn++) {
    memset(f[cur],-1,sizeof f[cur]);
    remap(prev);
    scanf("%s\n",ss);
    for (int x=0;x<(m>>2);x++) {
      char c=ss[x];
      int got;
      if ('0'<=c&&c<='9') {
        got=c-'0';
      }
      else {
        got=c-'A'+10;
      }
      int x4=x<<2;
      for (int k=3;k>=0;k--) {
        int y=x4+k;
        b[y]=got&1;
        /*if (got&1) {
          b[y]=true;
        }*/
        got>>=1;
      }
    }
    for (int y=0;y<m;y++) {
      if (b[y]) {
        if (y==0|| !b[y-1]) {
          f[cur][y] = ++gid;
          ufParent[gid] = gid;
          ans++;
        }
        else {
          f[cur][y]=gid;
        }
      }
    }
    for (int t=0;t<2;t++) {
      for (int i = 1; i < m; i++) {
        int x = f[t][i];
        int y = f[t][i - 1];
        if (x!=-1&&y!=-1) ans-=funion(x, y);
      }
    }
    for (int i = 0; i < m; i++) {
      int x = f[0][i];
      int y = f[1][i];
      if (x!=-1&&y!=-1) ans-=funion(x, y);
    }
    swap(cur,prev);
  }
  printf("%d\n",ans);
}