#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	vector<ll> c(n);
	for(int i = 0; i < n; i++) cin >> c[i];
	vector<ull> h(n);
	for(int i = 0; i < n; i++) h[i] = rng();
	vector<ull> what(n, 0);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		what[v] ^= h[u];
	}
	map<ull, ll> sums;
	for(int i = 0; i < n; i++){
		if(what[i] != 0){
			sums[what[i]] += c[i];
		}
	}
	for(auto v : sums){
		ans = __gcd(ans, v.second);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 	int T;
	cin >> T;
	while(T--){
		solve();
	}
}