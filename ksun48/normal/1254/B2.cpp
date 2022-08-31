#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll i = 0; i < n; i++) cin >> a[i];
	a.insert(a.begin(), 0);
	a.insert(a.end(), 0);
	ll sum = 0;
	for(ll x : a) sum += x;

	vector<ll> pr;
	for(ll p = 2; p * p <= sum; p++){
		if(sum % p == 0) pr.push_back(p);
		while(sum % p == 0) sum /= p;
	}
	if(sum > 1) pr.push_back(sum);
	ll val = ll(1e18);
	for(ll p : pr){
		ll cost = 0;
		ll psum = 0;
		for(ll r : a){
			psum += r;
			cost += min(psum % p, p - psum % p);
		}
		val = min(val, cost);
	}
	if(val >= ll(1e18)){
		cout << -1 << '\n';
	} else {
		cout << val << '\n';
	}

}