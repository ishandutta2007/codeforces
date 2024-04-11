#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = int64_t;
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	int b = 0;
	while(m--){
		int r;
		cin >> r;
		b = gcd(b, r);
	}
	assert(b);
	vector<vector<ll> > groups(b);
	for(int i = 0; i < n; i++){
		groups[i % b].push_back(a[i]);
	}
	vector<ll> cost(2, 0);
	for(int i = 0; i < b; i++){
		ll best_sum = 0;
		ll min_abs = 2e9;
		int parity = 0;
		for(ll x : groups[i]){
			best_sum += abs(x);
			if(x < 0) parity ^= 1;
			min_abs = min(min_abs, abs(x));
		}
		cost[parity] += best_sum;
		cost[1 ^ parity] += best_sum -= 2 * min_abs;
	}
	cout << max(cost[0], cost[1]) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}