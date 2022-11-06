#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=1004;
ll a[MAXN];
unordered_map<ll,ll> h;
int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%d",&n);
	for (ll i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	ll ans=0;
	for (ll x=0;x<n;x++) {
		h[a[x]]++;
		if(a[x]==0)ans++;
	}
	ans=max(ans,2);
	vector<ll> b,c;
	for (auto &w:h) {
		b.PB(w.first);
		c.PB(w.second);
	}
	ll m=b.size();
	for (ll i=0;i<m;i++) {
		for (ll j=0;j<m;j++) {
			if (c[i]==1&&i==j) continue;
			ll x=b[i]; ll y=b[j];
			vector<ll> v;
			v.PB(x); v.PB(y); h[x]--; h[y]--;
			ll cand=2;
			while(1) {
				ll z=x+y;
				auto it=h.find(z);
				if (it==h.end()||it->second<=0) break;
				it->second-=1;
				v.PB(z);
				x=y;
				y=z;
				cand++;
			}
			for (auto &w:v) {
				h[w]++;
			}
			ans=max(ans,cand);
		}
	}
	printf("%d\n",ans);
}