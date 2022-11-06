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
ll z[2],a[2],b[2],s[2];
const int mn=1e5;
__int128 p[mn][2];
vector<__int128> d;
int n=1;
ll have;
__int128 abs(__int128 x) {
  if (x<0) return -x;
  return x;
}
bool f(int init, int want) {
  if (want==0) return true;
  if (want > n) return false;
  __int128 base=0;
  for (int t=0;t<2;t++) base+=abs(s[t]-p[init][t]);
  __int128 left=have-base;
  if (left<0) return false;
  if (init-want+1 >= 0) {
    __int128 need = d[init] - d[init-want+1];
    if (need <= left) {
      //if (want==4) printf("Ainit:%d\n",init);
      return true;
    }
  }
  if (init+want-1 < n) {
    __int128 need = d[init+want-1] - d[init];
    if (need <= left) {
      //if (want==4) printf("Binit:%d\n",init);
      return true;
    }
  }
  return false;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int t=0;t<2;t++) cin>>z[t];
  for (int t=0;t<2;t++) cin>>a[t];
  for (int t=0;t<2;t++) cin>>b[t];
  for (int t=0;t<2;t++) cin>>s[t];
  cin>>have;
  for (int t=0;t<2;t++) p[0][t]=z[t];
  d.PB(0);
  for (int i=1;;i++) {
    bool ok=true;
    for (int t=0;t<2;t++) {
      __int128 res=a[t]*p[i-1][t]+b[t];
      if (res-s[t] > have) ok=false;
      p[i][t]=res;
    }
    if (!ok) break;
    __int128 dist=0;
    for (int t=0;t<2;t++) dist+=abs(p[i][t]-p[i-1][t]);
    //printf("%d: %lld %lld dist:%lld\n",i,p[i][0],p[i][1],dist);
    __int128 cumdist=dist + d.back();
    d.PB(cumdist);
    n++;
  }
  int final=0;
  for (int i=0;i<n;i++) {
    int imin=0,imax=n+1;
    while(imin<imax) {
      int imid=(imin+imax)/2;
      if (f(i,imid)) imin=imid+1;
      else imax=imid;
    }
    chkmax(final,imin-1);
  }
  printf("%d\n",final);
}