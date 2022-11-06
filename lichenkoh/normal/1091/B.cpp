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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=1004;
int x[mn],y[mn],a[mn],b[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int i=0;i<n;i++) {
    cin>>x[i]>>y[i];
  }
  for (int i=0;i<n;i++) {
    cin>>a[i]>>b[i];
  }
  for (int k=0;k<n;k++) {
    int tx=x[0]+a[k],ty=y[0]+b[k];
    map<pii,int> h;
    for (int t=0;t<n;t++) {
      ++h[MP(a[t],b[t])];
    }
    bool ok=1;
    for (int i=0;i<n;i++) {
      pii got=MP(tx-x[i],ty-y[i]);
      auto it=h.find(got);
      if (it!=h.end()) {
        --(it->snd);
        if ((it->snd) == 0) h.erase(it);
      }
      else {
        ok=0; break;
      }
    }
    if (ok) {
      printf("%d %d\n",tx,ty);
      exit(0);
    }
  }
}