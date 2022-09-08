#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll INF = ll(1e18);
	int N;
	ll T;
	cin >> N >> T;
	vector<ll> g(N);
	vector<ll> c(N);
	for(int i = 0; i < N; i++){
		cin >> g[i] >> c[i];
	}
	vector<ll> d(N-1);
	for(int i = 0; i < N-1; i++) cin >> d[i];
	ll csum = 0;
	ll base_cost = 0;
	for(int i = 1; i < N; i++){
		base_cost += d[i-1];
		csum = (csum + d[i-1]) % T;
		c[i] = (c[i] + csum + T) % T;
	}
	set<pair<ll, ll> > free_intervals;
	free_intervals.insert({0, T-1});
	map<ll, ll> dp;
	auto set_min = [&](ll t, ll val){
		if(!dp.count(t)){
			dp[t] = val;
		} else {
			dp[t] = min(dp[t], val);
		}
	};
	for(int i = 0; i < N; i++){
		ll S = (T - c[i]) % T;
		ll L = g[i] - 1; // incl
		ll S_cost = INF;
		if(!free_intervals.empty()){
			auto it = free_intervals.lower_bound({S+1, -1});
			if(it == free_intervals.begin()) it = free_intervals.end();
			it = prev(it);
			auto [l, r] = *it;
			if(l <= S && S <= r){
				S_cost = 0;
			} else {
				S_cost = (S + T - r) % T;
			}
		}
		while(!dp.empty()){
			auto it = dp.lower_bound(S);
			if(it == dp.begin()) it = dp.end();
			it = prev(it);
			auto [loc, val] = *it;
			if((loc >= S && loc <= S + L) || (loc + T >= S && loc + T <= S + L)){
				break;
			} else {
				ll cost = (S - loc + 2 * T) % T;
				S_cost = min(S_cost, val + cost);
				dp.erase(it);
			}
		}
		set_min(S, S_cost);
		ll E = (S + g[i]) % T;
		ll EL = T - g[i] - 1;
		for(ll z : {0, 1}){
			ll i_l = E - z * T;
			ll i_r = E + EL - z * T;
			while(!free_intervals.empty()){
				auto it = free_intervals.lower_bound({i_l, -1});
				if(it != free_intervals.end()){
					auto [c_l, c_r] = *it;
					assert(c_l >= i_l);
					if(c_l <= i_r){
						free_intervals.erase({c_l, c_r});
						if(i_r < c_r){
							free_intervals.insert({i_r + 1, c_r});
						}
						continue;
					}
				}
				if(it != free_intervals.begin()){
					auto [c_l, c_r] = *prev(it);
					assert(c_l < i_l);
					if(i_l <= c_r){
						free_intervals.erase({c_l, c_r});
						free_intervals.insert({c_l, i_l - 1});
						if(i_r < c_r){
							free_intervals.insert({i_r + 1, c_r});
						}
						continue;
					}
				}
				break;
			}
		}
	}
	ll ans = INF;
	if(!free_intervals.empty()){
		ans = 0;
	} else {
		for(auto [t, val] : dp) ans = min(ans, val);
	}
	cout << (base_cost + ans) << '\n';
}