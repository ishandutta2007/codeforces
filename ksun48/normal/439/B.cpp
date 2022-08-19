#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	using ll = long long;
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += a[i] * max(x - i, 1ll);
	}
	cout << ans << '\n';
}