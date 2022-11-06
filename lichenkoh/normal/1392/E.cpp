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

int main() 
{
  int n; scanf("%d",&n);
  for (int x=0;x<n;x++) {
    for (int y=0;y<n;y++) {
      ll out=(x&1)?(1LL<<(x+y)):0;
      printf("%lld ", out);
    }
    printf("\n");
  }
  fflush(stdout);
  int q; scanf("%d",&q);
  for (int qi=0;qi<q;qi++) {
    ll k; scanf("%lld",&k);
    int x=0,y=0;
    for (int d=0;d<=2*n-2;d++) {
      printf("%d %d\n",x+1,y+1);
      if ( ((k>>(x+y+1))%2) != (x%2)) {
        x++;
      } else {
        y++;
      }
    }
    //printf("%d %d\n",n,n);
    fflush(stdout);
  }
}