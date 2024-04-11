#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> as(n);
	for (int& a : as) cin >> a;

	sort(as.begin(), as.end());
	reverse(as.begin(), as.end());

	int h = (n+1)/2;
	vector<ll> res(n, -1);
	for (int i = 0; i < n; ++i) {
		if (2*i < n) res[2*i] = as[i];
		else res[2*(i-h)+1] = as[i];
	}
	
	int ans = 0;
	for (int i = 1; i+1 < n; ++i) {
		if (res[i] < res[i-1] && res[i] < res[i+1]) ++ans;
	}

	cout << ans << '\n';
	for (auto v : res) cout << v << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}