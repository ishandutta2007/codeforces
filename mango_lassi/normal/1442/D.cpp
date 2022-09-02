#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3000;
const int K = 3000;
const int D = 20;
ll cur[D][K+1];
vector<ll> as[N+1];
ll full[N+1];

void clear(int d, int k) {
	for (int j = 0; j <= k; ++j) cur[d][j] = cur[d-1][j];
}

void add(int d, int k, int w, ll v) {
	for (int i = k; i >= w; --i) cur[d][i] = max(cur[d][i], cur[d][i - w] + v);
}

ll recSolve(int a, int b, int d, int k) {
	if (a == b) {
		ll res = 0;
		ll sum = 0;
		for (int i = 0; i <= as[a].size(); ++i) {
			res = max(res, sum + cur[d][k-i]);
			if (i < as[a].size()) sum += as[a][i];
		}
		return res;
	} else {
		ll res = 0;
		int m = (a + b) >> 1;

		clear(d+1, k);
		for (int i = a; i <= m; ++i) add(d+1, k, as[i].size(), full[i]);
		res = max(res, recSolve(m+1, b, d+1, k));

		clear(d+1, k);
		for (int i = m+1; i <= b; ++i) add(d+1, k, as[i].size(), full[i]);
		res = max(res, recSolve(a, m, d+1, k));
	
		return res;
	}
}

void solve() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		as[i].resize(min(k, t));
		for (auto& v : as[i]) cin >> v;
		for (int j = min(k, t); j < t; ++j) {
			ll tmp;
			cin >> tmp;
		}
		for (auto v : as[i]) full[i] += v;
	}
	ll res = recSolve(0, n-1, 0, k);
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}