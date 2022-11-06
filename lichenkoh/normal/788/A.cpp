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
ll a[mn];
ll b[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll x=1;x<=n;x++) scanf("%lld",&a[x]);
	for (ll x=1;x<n;x++) b[x]=abs(a[x]-a[x+1]);
	ll final=-INF;
	{
		ll sign=1;
		ll lo=0;
		ll sum=0;
		for (ll x=1;x<n;x++) {
			sum+=sign*b[x];
			chkmax(final,sum-lo);
			if (sign==-1) chkmin(lo,sum);
			sign*=-1;
		}
	}
	{
		ll sign=1;
		ll lo=0;
		ll sum=0;
		for (ll x=2;x<n;x++) {
			sum+=sign*b[x];
			chkmax(final,sum-lo);
			if (sign==-1) chkmin(lo,sum);
			sign*=-1;
		}
	}
	printf("%lld\n",final);
}