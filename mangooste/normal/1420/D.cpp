#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

inline int add(int a, int b) {
	a += b;
	return a - MOD * (a >= MOD);
}

inline int mult(int a, int b) {
	return (long long) a * b % MOD;
}

int power(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return mult(power(a, b - 1), a);
	return power(mult(a, a), b / 2);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> fact(n + 1, 1);
	for (int i = 1; i <= n; i++)
		fact[i] = mult(fact[i - 1], i);
	vector<int> rfact(n + 1);
	rfact.back() = power(fact.back(), MOD - 2);
	for (int i = n - 1; i >= 0; i--)
		rfact[i] = mult(rfact[i + 1], i + 1);
	vector<pair<int, int>> evs;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		evs.emplace_back(l, 0);
		evs.emplace_back(r, 1);
	}

	auto C = [&](int n, int k) {
		if (k > n)
			return 0;
		return mult(fact[n], mult(rfact[k], rfact[n - k]));
	};

	sort(evs.begin(), evs.end());
	int bal = 0;
	long long ans = 0;
	for (auto [x ,type] : evs) {
		if (type == 0) {
			ans += C(bal, k - 1);
			bal++;
		} else
			bal--;
	}
	cout << ans % MOD << '\n';
}