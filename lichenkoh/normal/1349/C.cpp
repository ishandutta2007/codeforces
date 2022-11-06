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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const bool DBG=0;
const int mn=1008;
bitset<mn> a[mn];
ll spread[mn][mn];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int rn,cn;
bool alldiff(int r, int c) {
  bool now=a[r][c];
  for (int dir=0;dir<4;dir++) {
    int zr=r+dx[dir];
    int zc=c+dy[dir];
    if (0<=zr&&zr<rn && 0<=zc&&zc<cn && now==a[zr][zc]) return false;
  }
  return true;
}
const int mq=(1e5)+4;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int qn;
  cin>>rn>>cn>>qn;
  for (int r=0;r<rn;r++) {
    string s; cin>>s;
    for (int c=0;c<cn;c++) a[r][c]=(s[c]=='1');
  }
  for (int r=0;r<rn;r++) {
    for (int c=0;c<cn;c++) {
      if(!alldiff(r,c)) spread[r][c]=0;
      else spread[r][c]=LLONG_MAX/2;
    }
  }
  for (int r=0;r<rn;r++) {
    for (int c=1;c<cn;c++) {
      chkmin(spread[r][c],spread[r][c-1]+1);
    }
  }
  for (int r=0;r<rn;r++) {
    for (int c=cn-2;c>=0;c--) {
      chkmin(spread[r][c],spread[r][c+1]+1);
    }
  }
  for (int c=0;c<cn;c++) {
    for (int r=1;r<rn;r++) {
      chkmin(spread[r][c],spread[r-1][c]+1);
    }
  }
  for (int c=0;c<cn;c++) {
    for (int r=rn-2;r>=0;r--) {
      chkmin(spread[r][c],spread[r+1][c]+1);
    }
  }

  for (int qi=0;qi<qn;qi++) {
    int r,c; ll p;cin>>r>>c>>p;
    --r;
    --c;
    ll sp=spread[r][c];
    int ans;
    if (p<=sp) {
      ans=a[r][c];
    } else {
      ans=int(a[r][c])^((p-sp)%2);
    }
    printf("%d\n",ans);
  }
}