#include <bits/stdc++.h>

using ll = long long;
int n;
ll x,y;
std::map<ll,std::vector<ll> > S;

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lld%lld",&x,&y);
		ll ind = x + y;
		S[ind].push_back(y);
		S[ind].push_back(y);
	}
	std::multiset<ll>L,R;
	ll delta = 0;
	ll gap = 0;
	ll last = 0;
	for (auto x:S) {
		ll cur = x.first;
		//printf("cur : %lld\n",cur);
		std::multiset<ll>Z;
		for (ll z:x.second) Z.insert(z);
		delta += (ll) R.size() * (cur - last);
		gap += cur - last;
		int tot = L.size() + R.size() + Z.size();
		int need = (tot / 2) - L.size();
		int need_to_reach = tot / 2;
		int zs = Z.size();
		for (int i = 1; i <= zs; ++ i) {
			if (!L.size()) break;
			Z.insert(*L.rbegin());
			L.erase(L.find(*L.rbegin()));
		}
	//	printf(">%d\n",need_to_reach);
		while (L.size() < need_to_reach) {
			if (R.empty()) {
				ll a = *Z.begin();
				Z.erase(Z.find(a));
				L.insert(a);
				continue;
			}
			if (Z.empty()) {
				ll b = (*R.begin()) + gap;
				L.insert(b);
				R.erase(R.find(b - gap));
				continue;
			}
			ll a = *Z.begin();
			ll b = (*R.begin()) + gap;
			if (a < b) {
				Z.erase(Z.find(a));
				L.insert(a);
			} else {
				L.insert(b);
				R.erase(R.find(b - gap));
			}
		} //puts("!");
		for (ll z:Z) 
			R.insert(z - gap);
		last = cur;
		//for (ll x:L) printf("%lld ",x); puts("L");
	//	for (ll x:R) printf("%lld ",x + gap); puts("R");
	} std::vector<ll>v; 
	for (ll x:L) v.push_back(x);
	for (ll x:R) v.push_back(x + gap);
	assert(std::is_sorted(v.begin(),v.end()));
	assert(v.size() == 2 * n);
	ll x = v[n], ans = 0;
	for (ll y:v) ans += std::abs(y - x);
	ans -= delta;
	assert(ans % 2 == 0);
	printf("%lld",ans / 2);
	return 0;
}