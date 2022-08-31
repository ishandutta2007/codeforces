#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	ll csum = n;
	ll cans = 0;
	for(ll x : a) cans += x * x;

	vector<ll> cval(n, 1);
	auto cost = [&](ll i, ll v){
		ll r = a[i] / v;
		return v * r * r + (a[i] % v) * (2 * r + 1);
	};
	set<pair<ll, ll> > best_cost;
	for(ll i = 0; i < n; i++){
		if(cval[i] < a[i]){
			best_cost.insert({cost(i, cval[i]+1) - cost(i, cval[i]), i});
		}
	}
	while(csum < k){
		pair<ll, ll> v = *best_cost.begin();
		best_cost.erase(best_cost.begin());
		ll i = v.second;
		cans -= cost(i, cval[i]);
		cval[i] += 1;
		cans += cost(i, cval[i]);
		csum++;
		if(cval[i] < a[i]){
			best_cost.insert({cost(i, cval[i]+1) - cost(i, cval[i]), i});
		}
	}
	cout << cans << '\n';
}