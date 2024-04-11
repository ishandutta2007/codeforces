#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace IO {
	template<class T> istream& operator >> (istream& in, vector<T> &v) { for (T &x : v) in >> x; return in; }
	template<class T> ostream& operator << (ostream& out, vector<T> v) { for (size_t i = 0; i < v.size(); i++) { if (i) out << ' '; out << v[i]; } return out; }
	template<class A, class B> istream& operator >> (istream& in, pair<A, B> &p) { return in >> p.first >> p.second; }
	template<class A, class B> ostream& operator << (ostream& out, pair<A, B> p) { return out << p.first << ' ' << p.second; }
	template<class T, const size_t SZ> istream& operator >> (istream& in, array<T, SZ> &a) { for (T &x : a) in >> x; return in; }
	template<class T, const size_t SZ> ostream& operator << (ostream& out, array<T, SZ> a) { for (size_t i = 0; i < SZ; i++) { if (i) out << ' '; out << a[i]; } return out; }
}

using namespace IO;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	cin >> a;
	if (n > 3) return cout << "-1\n", 0;
	vector<int> tb(m, 0);
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) tb[j] = tb[j] * 2 + a[i][j] - '0';
	}
	vector<int> dp(1 << n);
	for (int mask = 0; mask < (1 << n); mask++) dp[mask] = __builtin_popcount(tb[0] ^ mask);
	for (int j = 1; j < m; j++) {
		vector<int> ndp(1 << n, 1e9);
		for (int mask = 0; mask < (1 << n); mask++) {
			int now = __builtin_popcount(mask ^ tb[j]);
			for (int pmask = 0; pmask < (1 << n); pmask++) {
				bool ok = true;
				for (int i = 0; i < n - 1; i++) {
					int cnt = (mask >> i) % 2 + (mask >> i + 1) % 2 + (pmask >> i) % 2 + (pmask >> i + 1) % 2;
					ok &= cnt % 2;
				}
				if (ok) ndp[mask] = min(ndp[mask], now + dp[pmask]);
			}
		}
		dp = ndp;
	}
	cout << *min_element(dp.begin(), dp.end()) << '\n';
}