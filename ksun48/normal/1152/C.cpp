#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	ll a, b;
	cin >> a >> b;
	if(a == b){
		cout << 0 << '\n';
		return 0;
	}
	ll r = abs(a-b);
	ll best = a * b / __gcd(a, b);
	ll bestk = 0;
	vector<ll> divs;
	for(ll d = 1; d * d <= r; d++){
		if(r % d == 0) divs.push_back(d);
		if(r % d == 0) divs.push_back(r/d);
	}
	for(ll d : divs){
		ll k = (d - (a % d)) % d;
		ll l = (a + k) * (b + k) / __gcd(a + k, b + k);
		if(l < best){
			best = l;
			bestk = k;
		}
		if(l == best){
			bestk = min(bestk, k);
		}
	}
	cout << bestk << '\n';
}