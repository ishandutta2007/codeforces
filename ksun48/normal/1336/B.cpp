#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
	vector<int> cnt(3);
	set<ll> a[3];
	for(int i = 0; i < 3; i++) cin >> cnt[i];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < cnt[i]; j++){
			ll r;
			cin >> r;
			a[i].insert(r);
		}
		a[i].insert(-1e18);
		a[i].insert(1e18);
	}
	ll best = 5e18;
	for(int i = 0; i < 3; i++){
		int j = (i+1) % 3;
		int k = (j+1) % 3;
		for(ll r : a[i]){
			if(abs(r) >= ll(1e11)) continue;
			ll c0[2];
			ll c1[2];
			auto f = a[j].lower_bound(r);
			c0[1] = *f;
			c0[0] = *prev(f);
			auto g = a[k].lower_bound(r);
			c1[1] = *g;
			c1[0] = *prev(g);
			for(int y = 0; y < 2; y++){
				for(int z = 0; z < 2; z++){
					ll s = c0[y];
					ll t = c1[z];
					if(abs(s) >= ll(1e11) || abs(t) >= ll(1e11)) continue;
					best = min(best, (r-s)*(r-s) + (r-t)*(r-t) + (s-t)*(s-t));
				}
			}
		}
	}
	cout << best << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}