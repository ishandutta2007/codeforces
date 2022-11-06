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
const int mn=3e5+4;
ll inp[2][mn];

ll f[2][2]; // Whats the minimum of obj i in a row?
ll k;
ll aa(ll sa, ll a, ll b) {
  if (sa>k) return INF;
  // sa|ab|aab|aab|aa
  // Too many As?
  if (sa+a>(b+1)*k) return INF;
  // Too many Bs?
  // sa|bba|bba|bba
  if (b>a*k) return INF;
  // Ok there is solution
  // sa|ab|aab|aab|aa
  return max(1LL,sa+a-b*k);
}

ll ab(ll sa, ll a, ll b) {
  if (sa>k) return INF;
  // sa|ab|aab|aab|aab
  // Are there too many As?
  if (sa+a > b*k) return INF;
  // Are there too many Bs?
  // sa|bba|bba|bb
  if (b > (a+1)*k) return INF;
  // Ok there is solution.
  return max(1LL,b-a*k);
}


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n>>k;
  for (int t=0;t<2;t++) for (int i=1;i<=n;i++) cin>>inp[t][i];
  int cur=0,nxt=1;
  for (int i=1;i<=n;i++) {
    f[nxt][0]=f[nxt][1]=INF;
    for (int A=0;A<2;A++) {
      for (int T=0;T<2;T++) {
        ll sa=f[cur][A];
        if (sa>k) continue;
        int B=A^1;
        ll a=inp[A][i],b=inp[B][i];
        if (T==A) {
          chkmin(f[nxt][T],aa(sa,a,b));
        }
        else {
          chkmin(f[nxt][T],ab(sa,a,b));
        }
      }
    }
    swap(cur,nxt);
  }
  for (int A=0;A<2;A++) {
    if (f[cur][A]<=k) {printf("YES\n"); exit(0);}
  }
  printf("NO\n");

}