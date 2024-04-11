#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll f[3002][3002];
ll a[3002];
int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%I64d",&n);
	for (ll i=0;i<n;i++) scanf("%I64d",&a[i]);
	for (ll i=0;i<n;i++) a[i]-=i;
	set<ll> s;
	for (ll i=0;i<n;i++) s.insert(a[i]);
	vector<ll> b;
	for (auto &w:s) {
		b.PB(w);
	}
	ll bsz=b.size();
	for (ll i=0;i<n;i++) {
		ll imin=0,imax=bsz;
		ll key=a[i];
		while(imin<imax) {
			ll imid=imin+(imax-imin)/2;
			if (b[imid]<key) imin=imid+1;
			else imax=imid;
		}
		a[i]=imin;
	}
	{
		ll x=0;
		for (ll y=0;y<bsz;y++) {
			f[x][y]=abs(b[y]-b[a[x]]);
		}
		for (ll y=1;y<bsz;y++) {
			chkmin(f[x][y],f[x][y-1]);
		}
	}
	for (ll x=1;x<n;x++) {
		for (ll y=0;y<bsz;y++) {
			f[x][y]=f[x-1][y]+abs(b[y]-b[a[x]]);
		}
		for (ll y=1;y<bsz;y++) {
			chkmin(f[x][y],f[x][y-1]);
		}
	}
	ll ans=INF;
	for (ll y=0;y<bsz;y++) {
		chkmin(ans,f[n-1][y]);
	}
	printf("%I64d\n",ans);
}