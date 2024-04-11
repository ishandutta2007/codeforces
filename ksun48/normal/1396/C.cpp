#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	using i128 = __int128_t;
	ll n;
	cin >> n;
	ll r1, r2, r3;
	cin >> r1 >> r2 >> r3;
	assert(r1 <= r2 && r2 <= r3);
	ll _d;
	cin >> _d;
	i128 d = _d;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	i128 base_cost = (n-1) * d;
	vector<i128> save(n);
	for(ll i = 0; i < n; i++){
		i128 c1 = r1 * a[i] + r3;
		i128 c2 = r1 + min(r2, r1 * (a[i] + 1));
		c2 = min(c1, c2);
		base_cost += c1;
		save[i] = c1 - c2;
	}
	vector<i128> dp(n+1, 0);
	for(i128 i = 1; i <= n; i++){
		dp[i] = max(dp[i], dp[i-1]);
		dp[i] = max(dp[i], dp[i-1] + save[i-1] - 2*d);
		if(i >= 2){
			dp[i] = max(dp[i], dp[i-2] + save[i-1] + save[i-2] - 2*d);
		}
	}
	dp[n] = max(dp[n], dp[n-2] + save[n-2] - d);
	base_cost -= dp[n];
	cout << (ll)base_cost << '\n';
}