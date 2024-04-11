#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<ll> bs(n);
	for (ll& b : bs) cin >> b;

	ll res = 0, cur = 0, act = 0;
	vector<ll> adds(n, 0);
	for (int i = n-1; i >= 0; --i) {
		bs[i] -= cur;
		if (bs[i] > 0) {
			ll v = min(i + 1, k);
			ll c = (bs[i] + v-1) / v;
			
			bs[i] -= c * v;
			cur += c * v;
			act += c;
			res += c;
			if (i - k >= 0) adds[i - k] += c;
		}
		act -= adds[i];
		cur -= act;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}