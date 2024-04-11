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
const ll mn=2e5+4;
ll a[mn],b[mn]; 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	ll ai,bi;
	for (ll i=0;i<n;i++) {scanf("%lld",a+i);}
	for (ll i=0;i<n;i++) {scanf("%lld",b+i);}
	for (ll i=0;i<n;i++) {
		if (a[i]==1) ai=i;
		if (b[i]==1) bi=i;
	}
	bool ans=true;
	for (ll i=0;i<n;i++) {
		if (a[ai]==0) {ai++;ai%=n;}
		if (b[bi]==0) {bi++;bi%=n;}
		if (a[ai]!=b[bi]) {
			ans=false;
		}
		ai++; bi++;
		ai%=n;
		bi%=n;
	}
	if(ans) printf("YES\n");
	else printf("NO\n");
}