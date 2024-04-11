#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = int64_t;
	int n;
	cin >> n;
	int cmin = 2e9;
	ll min_cost = 0;
	int cmax = -2e9;
	ll max_cost = 0;
	ll both_cost = 0;
	for(int i = 0; i < n; i++){
		int l, r;
		ll c;
		cin >> l >> r >> c;
		if(l < cmin){
			cmin = l;
			min_cost = c;
			both_cost = 3e9;
		}
		if(r > cmax){
			cmax = r;
			max_cost = c;
			both_cost = 3e9;
		}
		if(l == cmin){
			min_cost = min(min_cost, c);
		}
		if(r == cmax){
			max_cost = min(max_cost, c);
		}
		if(l == cmin && r == cmax){
			both_cost = min(both_cost, c);
		}
		cout << min(min_cost + max_cost, both_cost) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}