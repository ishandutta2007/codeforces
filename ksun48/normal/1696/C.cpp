#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll> >> res;
	for(int it = 0; it < 2; it++){
		ll k;
		if(it == 0){
			k = n;
		} else {
			cin >> k;
		}
		vector<ll> a(k);
		for(ll& r : a) cin >> r;
		vector<pair<ll, ll> > freq;
		for(ll x : a){
			ll cnt = 1;
			while(x % m == 0){
				x /= m;
				cnt *= m;
			}
			if(freq.empty() || freq.back().first != x){
				freq.push_back({x, cnt});
			} else {
				freq.back().second += cnt;
			}
		}
		res.push_back(freq);
	}
	cout << (res[0] == res[1] ? "Yes" : "No") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}