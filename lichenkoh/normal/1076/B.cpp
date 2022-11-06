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
typedef vector<pii> vpii;
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
ll getdiv(ll n) {
  int slim=min(n-1,(ll)ceil(sqrt((ld)n))+5);
  for (int s=2;s<=slim;s++) {
    if (n%s==0) {
      return s;
    }
  }
  return n;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n; cin>>n;
  ll s=getdiv(n);
  n-=s;
  ll ans=1;
  if (n==0) {
    printf("%lld\n",ans); exit(0);
  }
  s=getdiv(n);
  ans+=n/s;
  printf("%lld\n",ans);
}