#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T, T mod, class BIG = long long>
struct modular {
	T val;

	modular() : T(0) {}

	template<class C>
	modular(C a) : val((a % mod + mod) % mod) {}

	template<class C>
	modular& operator = (C a) {
		val = (a % mod + mod) % mod;
		return *this;
	}

	modular& operator += (modular a) {
		val += a.val;
		if (val >= mod)
			val -= mod;
		return *this;
	}

	modular& operator -= (modular a) {
		val -= a.val;
		if (val < 0)
			val += mod;
		return *this;
	}

	modular& operator *= (modular a) {
		val = BIG(val) * a.val % mod;
		return *this;
	}


	modular operator + (modular a) {
		T sum = val + a.val;
		return sum - mod * (sum >= mod);
	}

	modular operator - (modular a) {
		T res = val - a.val;
		return res + mod * (res < 0);
	}

	modular operator * (modular a) {
		return BIG(val) * a.val % mod;
	}

	friend istream& operator >> (istream &in, modular &a) {
		BIG now;
		in >> now;
		a = now;
		return in;
	}

	friend ostream& operator << (ostream &out, modular a) {
		return out << a.val;
	}
};

const int MOD = 998244353;

using mint = modular<int, MOD>;

pair<mint, mint> operator + (pair<mint, mint> &a, pair<mint, mint> &b) {
	return {a.first * b.second + b.first * a.second, a.second * b.second};
}

mint power(mint a, int b) {
	if (!b)
		return 1;
	if (b % 2)
		return power(a, b - 1) * a;
	return power(a * a, b / 2);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> cnt(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	vector<vector<mint>> dp(n + 1, vector<mint>(n + 1, 0));
	dp[0][0] = 1;
	auto pref = dp;

	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1];
		for (int len = 1; len <= i; len++) {
			dp[i][len] = mint(cnt[i]) * pref[i - 1][len - 1];
			pref[i][len] += dp[i][len];
		}
	}

	// cout << "dp:\n";
	// for (auto xs : dp) {
	// 	for (auto x : xs)
	// 		cout << x << ' ';
	// 	cout << '\n';
	// }
	// cout << "---------------\n";

	// cout << "pref:\n";
	// for (auto xs : pref) {
	// 	for (auto x : xs)
	// 		cout << x << ' ';
	// 	cout << '\n';
	// }
	// cout << "---------------\n";

	vector<mint> prec(n, n);
	for (int i = 1; i < n; i++)
		prec[i] = prec[i - 1] * (n - i);

	pair<mint, mint> ans{0, 1};
	for (int last = 1; last <= n; last++)
		if (cnt[last] > 1)
			for (int len = 0; len <= n - 2; len++) {
				mint num = pref[last - 1][len] * cnt[last] * (cnt[last] - 1);
				pair<mint, mint> p{num, prec[len + 1]};
				ans = ans + p;
				// cout << last << ' ' << len << " (" << p.first << ' ' << p.second << ") (" 
				//      << ans.first << ' ' << ans.second << ")\n";
			}

	// cout << '(' << ans.first << ' ' << ans.second << ")\n";
	cout << ans.first * power(ans.second, MOD - 2) << '\n';
}