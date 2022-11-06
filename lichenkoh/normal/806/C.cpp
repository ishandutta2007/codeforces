#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const ll mn=1e5+4;
const ll mk=42;
ll a[mn];
bitset<mn> used;
ll vk[mk];
ll vc[mk];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  used.reset();
  ll n; scanf("%lld",&n);
  for (ll i=0;i<n;i++) {
    scanf("%lld",&a[i]);
  }
  {
    ll k=0;
    for (ll i=0;i<n;i++) {
      ll x=a[i];
      while ((1LL<<k)<x) k++;
      if ((1LL<<k)==x) {
        if (k==0|| (k>0&&vc[k-1]>0)) {
          //printf("i:%d x:%lld k:%d\n",i,x,k);
          vc[k]++;
          if (k>0) vc[k-1]--;
          used[i]=true;
        }
      }
    }
  }
  ll maxchains=0; for (ll k=0;k<mk;k++) maxchains+=vc[k];
  ll lastk=mk-1;
  for (ll i=n-1;i>=0;i--) {
    if (!used[i]) {
      while(lastk>=0&&vc[lastk]==0) lastk--;
      if (lastk<0 || a[i]>(1LL<<(lastk+1))) {printf("-1\n"); return 0;}
      vc[lastk]--;
    }
  }
  ll save=0;
  ll lft=0; for (ll k=0;k<mk;k++) lft+=vc[k];
  for (ll k=0;k<mk;k++) {
    ll len=k+1;
    for (ll i=0;i<vc[k];i++) {
      if (lft-1>=len) {
        lft-=(1+len);
        save++;
      }
      else break;
    }
  }
  ll lo=maxchains-save;
  for (ll x=lo;x<=maxchains;x++) {
    printf("%lld ",x);
  }
  printf("\n");
}