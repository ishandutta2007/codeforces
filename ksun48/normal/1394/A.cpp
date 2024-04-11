#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	ll n, d, m;
	cin >> n >> d >> m;
	vector<ll> big;
	vector<ll> small;
	for(int i = 0; i < n; i++){
		ll r;
		cin >> r;
		if(r > m){
			big.push_back(r);
		} else {
			small.push_back(r);
		}
	}
	sort(big.rbegin(), big.rend());
	sort(small.rbegin(), small.rend());
	ll cur = 0;
	for(ll v : small) cur += v;
	ll best = cur;
	ll idx = n;
	for(int b = 0; (d+1) * b <= n+d; b++){
		ll newidx = n + d - b * (d+1);
		while(idx > newidx){
			idx--;
			if(idx < (int)small.size()) cur -= small[idx];
		}
		best = max(best, cur);
		if(b < (int)big.size()) cur += big[b];
	}
	cout << best << '\n';
}