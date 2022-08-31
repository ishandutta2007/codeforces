#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int n;
	cin >> n;
	map<ll, ll> freq;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	ll off = 0;
	ll coeff = 1;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		freq[(0 - off) * coeff] += 1;
		ll c = a[i];
		off = c - off;
		coeff = -coeff;
		while(!freq.empty() && (coeff * (*freq.begin()).first + off) < 0){
			freq.erase(freq.begin());
		}
		while(!freq.empty() && (coeff * (*freq.rbegin()).first + off) < 0){
			freq.erase(prev(freq.end()));
		}
		ans += freq[(0 - off) * coeff];
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}