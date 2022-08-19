#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	int n;
	cin >> n;
	vector<pair<ll, ll>> z;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ll a, c;
		cin >> a >> c;
		z.push_back({a, a+c});
		ans += c;
	}
	sort(z.begin(), z.end());
	ll maxc = z.front().second;
	for(int i = 1; i < n; i++){
		ans += max(0ll, z[i].first - maxc);
		maxc = max(maxc, z[i].second);
	}
	cout << ans << '\n';
}