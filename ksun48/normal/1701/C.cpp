#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	ll n, t;
	cin >> n >> t;
	vector<int> id(t);
	vector<ll> freq(n, 0);
	for(int& x : id){
		cin >> x;
		x--;
		freq[x]++;
	}
	ll s = 0;
	ll e = 2 * t;
	while(s + 1 < e){
		ll m = (s + e) / 2;
		ll ndo = 0;
		for(int i = 0; i < n; i++){
			ll eff = min(freq[i], m);
			ndo += eff;
			ndo += (m - eff) / 2;
		}
		if(ndo >= t){
			e = m;
		} else {
			s = m;
		}
	}
	cout << e << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}