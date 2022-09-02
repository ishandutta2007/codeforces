#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_A = 1e5;
const int TRESHOLD = 500;

void solve() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 0 << '\n';
	} else {
		vector<int> as(n);
		for (int& a : as) cin >> a;
	
		// First, loop adds <= TRESHOLD, then, loop all pairs with |i - j| <= 1e5 / TRESHOLD
		int res = n;
		vector<ll> opts;
		for (int add = -TRESHOLD; add <= TRESHOLD; ++add) {
			for (int i = 0; i < n; ++i) opts.push_back(as[i] - add * i);
			sort(opts.begin(), opts.end());
			for (int j = 0, cur = 0; j < opts.size(); ++j) {
				if (j == 0 || opts[j] == opts[j-1]) ++cur;
				else cur = 1;
				res = min(res, n - cur);
			}
			opts.clear();
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n && (j - i) * (TRESHOLD + 1) <= MAX_A - 1; ++j) {
				ll diff = as[j] - as[i];
				ll dist = j - i;
				if (diff % dist == 0) opts.push_back(diff / dist);
			}
			sort(opts.begin(), opts.end());
			for (int j = 0, cur = 1; j < opts.size(); ++j) {
				if (j == 0 || opts[j] == opts[j-1]) ++cur;
				else cur = 2;
				res = min(res, n - cur);
			}
			opts.clear();
		}
		cout << res << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}