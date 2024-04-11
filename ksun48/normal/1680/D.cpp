#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	ll k;
	cin >> n >> k;
	k *= 2;
	vector<ll> a(n);
	for(ll& x : a){
		cin >> x;
		x *= 2;
	}
	ll zeros = 0;
	ll sum = 0;
	for(ll x : a){
		if(x == 0) zeros++;
		sum += x;
	}
	if(abs(sum) > k * zeros){
		cout << -1 << '\n';
		exit(0);
	}
	ll plus = (-sum + k * zeros) / 2;
	ll minus = (+sum + k * zeros) / 2;
	assert(plus >= 0 && minus >= 0);
	ll best = 0;
	for(int i = 0; i < n; i++){
		vector<ll> b = a;
		rotate(b.begin(), b.begin() + i, b.end());
		ll plus_used = plus;
		ll cur = 0;
		for(int j = 0; j < n; j++){
			if(b[j] != 0){
				cur += b[j];
				best = max(best, abs(cur));
			} else {
				ll f = min(k, plus_used);
				plus_used -= f;
				cur += f - (k - f);
				best = max(best, abs(cur));
				best = max(best, abs(cur));
			}
		}
	}
	cout << (best / 2 + 1) << '\n';
}