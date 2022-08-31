#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = long long;
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	a.insert(a.begin(), 0);
	if(a.size() % 2 == 0) a.insert(a.end(), 0);
	ll ans = 0;
	for(int j = 0; j < 2; j++){
		ll csum = 0;
		vector<ll> rest;
		for(int i = 0; i < (int)a.size(); i++){
			if(i & 1) csum += a[i];
			if((i % 2 == 0) && i > 0){
				rest.push_back(a[i] - a[i-1]);
			}
		}
		ll best_diff = 0;
		ll best_sum = 0;
		ll cur = 0;
		for(ll g : rest){
			cur += g;
			best_sum = min(best_sum, cur);
			best_diff = max(best_diff, cur - best_sum);
		}
		ans = max(ans, csum + best_diff);
		reverse(a.begin(), a.end());
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}