#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}

void solve() {
	int n, m, p;
	cin >> n >> m >> p;

	vector<ll> as(n, 0);
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j) {
			if (str[j] == '1') as[i] |= (1ll << j);
		}
	}

	pair<int, ll> res = {0, 0};
	for (int it = 0; it < 30; ++it) {
		ll mask = as[rand(0, n-1)];

		vector<int> bits;
		for (int j = 0; j < m; ++j) {
			if (mask & (1ll << j)) bits.emplace_back(j);
		}
		int k = bits.size();

		vector<int> cou(1 << k, 0);
		for (int i = 0; i < n; ++i) {
			int off = 0;
			for (int x = 0; x < k; ++x) {
				if (as[i] & (1ll << bits[x])) off |= (1 << x);
			}
			++cou[off];
		}
		
		for (int x = 0; x < k; ++x) {
			for (int y = 0; y < (1 << k); ++y) {
				if (y & (1 << x)) cou[y ^ (1 << x)] += cou[y];
			}
		}

		for (int y = 0; y < (1 << k); ++y) {
			if (2*cou[y] >= n) {
				int ans = __builtin_popcount(y);
				if (ans <= res.first) continue;
				
				res = {ans, 0};
				for (int x = 0; x < k; ++x) {
					if (y & (1 << x)) res.second |= (1ll << bits[x]);
				}
			}
		}
	}

	for (int j = 0; j < m; ++j) {
		if (res.second & (1ll << j)) cout << '1';
		else cout << '0';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}