#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD=1000000007;
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=(LLONG_MAX/2)-1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;

const ll mn=(2e5)+4;
ll a[mn],bl[mn],bh[mn];
ll c[mn],inc[mn];
bool ok[mn];
ll rlong() {ll x; scanf("%lld",&x); return x;}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rlong(),t=rlong();
  for (ll i=1;i<=n;i++) a[i]=rlong();
  for (ll i=1;i<=n;i++) c[i]=rlong();
  for (ll i=1;i<=n;i++) bh[i]=INF;
  for (ll i=1;i<=n;i++) {
  	if (c[i]+1<=n) chkmin(bh[c[i]], t+a[c[i]+1]-1);
  }
  for (ll i=1;i<=n;i++) bl[i]=a[i]+t;
  for (ll i=1;i<=n;i++) {
  	if (c[i]<i) {printf("No\n"); exit(0);}
  	inc[i+1]++;
  	inc[c[i]+1]--;
  }
  for (ll i=2;i<=n;i++) inc[i]+=inc[i-1];
  for (ll i=2;i<=n;i++) {
  	if (inc[i]>0) {
  		chkmax(bl[i-1],a[i]+t);
  	}
  }
  for (ll i=2;i<=n;i++) chkmax(bl[i],bl[i-1]+1);
  for (ll i=1;i<=n;i++) if (bl[i]>bh[i]) {printf("No\n"); exit(0);}
  printf("Yes\n");
	for (ll i=1;i<=n;i++) printf("%lld ",bl[i]);
}