#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair 
#define endl "\n"
typedef pair<ll,ll> pll;
const ll INF=1e18+4;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=1e4+4;
ll a[mn],b[mn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n-1;i++) {
		scanf("%lld %lld",a+i,b+i);
	}
	ll ans=0;
	for (ll i=0;i<n-1;i++) {
		for (ll k=i+1;k<n-1;k++) {
			//printf("Consider %d %d\n",i,k);
			if (a[i]==a[k]||
				a[i]==b[k]||
				b[i]==a[k]||
				b[i]==b[k]) {
				ans++;
				//printf("Add %d %d\n",i,k);
			}
		}
	}
	printf("%lld\n",ans);
}