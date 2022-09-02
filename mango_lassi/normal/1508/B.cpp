#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 100;

const int N = 1e5;
ll cnt[N+1];

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	
	if (cnt[n] < k) {
		cout << -1 << '\n';
		return;
	}

	vector<int> res(n);
	for (int i = 0; i < n;) {
		int j = 1;
		while(k > cnt[n-i-j]) {
			k -= cnt[n-i-j];
			++j;
		}
		for (int t = i; t < i + j; ++t) res[t] = i + j - (t - i);
		i += j;
	}
	for (auto i : res) cout << i << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cnt[0] = 1;
	cnt[1] = 1;
	for (int n = 2; n <= N; ++n) cnt[n] = min(INF, 2*cnt[n-1]);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}