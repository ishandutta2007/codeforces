#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int X = 1e6;

bitset<X> is_prime;
vector<int> pr;

void init(){
	is_prime.flip();
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i < X; i++){
		if(is_prime[i]){
			pr.push_back(i);
		}
		for(int p : pr){
			if(ll(i) * p >= X) break;
			is_prime[i * p] = false;
			if(i % p == 0) break;
		}
	}
}


void solve(){
	int n, e;
	cin >> n >> e;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	ll ans = 0;

	auto cnt = [](vector<int> b) -> ll {
		ll c = 0;
		for(int i = 0; i < b.size(); i++){
			if(b[i] == 1){
				int l = 1, r = 1;
				for(int j = i-1; j >= 0; j--){
					if(b[j] == 0){
						l++;
					} else {
						break;
					}
				}
				for(int j = i+1; j < b.size(); j++){
					if(b[j] == 0){
						r++;
					} else {
						break;
					}
				}
				c += ll(l) * ll(r);
			}
		}
		return c;
	};
	for(int g = 0; g < e; g++){
		vector<int> b;
		for(int l = g; l < n; l += e){
			if(is_prime[a[l]]){
				b.push_back(1);
				ans -= 1;
			} else if(a[l] == 1){
				b.push_back(0);
			} else {
				ans += cnt(b);
				b = {};
			}
		}
		ans += cnt(b);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	init();
	int T;
	cin >> T;
	while(T--) solve();
}