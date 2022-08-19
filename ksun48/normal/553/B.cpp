#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	ll n, k;
	cin >> n >> k;
	k--;
	vector<ll> g;
	ll a = 0;
	while(a < n){
		ll left = n-a-1;
		vector<ll> f = {1, 1};
		while(left >= f.size()){
			ll x = f[f.size() - 2] + f[f.size() - 1];
			x = min(x, ll(2e18));
			f.push_back(x);
		}
		if(k >= f[left]){
			g.push_back(a+1);
			g.push_back(a);
			a += 2;
			k -= f[left];
		} else {
			g.push_back(a);
			a += 1;
		}
	}
	assert(k == 0);
	for(ll r : g) cout << r + 1 << ' ';
	cout << '\n';
}