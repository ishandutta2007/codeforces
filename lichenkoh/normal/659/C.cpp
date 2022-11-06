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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=100000+5;
ll a[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; scanf("%I64d %I64d",&n,&m);
	for (ll i=0;i<n;i++) {
		scanf("%I64d",&a[i]);
	}
	sort(a,a+n);
	map<ll,ll,greater<ll> > h;
	ll cum=0;
	for (ll i=0;i<n;i++) {
		cum+=a[i];
		h[a[i]]=cum;
	}
	ll imin=0; ll imax=1e9+5;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		ll all=(imid*(imid+1))/2;
		auto it=h.lower_bound(imid);
		if (it!=h.end()) {
			all-=(it->second);
		}
		bool ok=(all<=m);
		if (ok) {
			imin=imid+1;
		}
		else {
			imax=imid;
		}
	}
	imin--;
	vector<ll> ans;
	for (ll x=1;x<=imin;x++) {
		if (h.find(x)==h.end()) ans.PB(x);
	}
	printf("%I64d\n",(ll)ans.size());
	for (auto &w:ans) {
		printf("%I64d ",w);
	}
	printf("\n");
}