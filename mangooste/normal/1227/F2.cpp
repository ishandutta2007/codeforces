#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;

inline int add(int a, int b) {
	a += b;
	return a - MOD * (a >= MOD);
}

inline int mult(int a, int b) {
	return (ll) a * b % MOD;
}

inline int sub(int a, int b) {
	a -= b;
	return a + MOD * (a < 0);
}

int power(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b % 2) {
		return mult(a, power(a, b - 1));
	}
	return power(mult(a, a), b / 2);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &el : a) {
		cin >> el;
	}

	if (k == 1) {
		cout << "0\n";
		return 0;
	}

	int good = 0, bad = 0;
	for (int i = 0; i < n; i++) {
		(a[i] == a[(i + 1) % n] ? good : bad)++;
	}

	vector<int> fact(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		fact[i] = mult(fact[i - 1], i);
	}

	vector<int> rfact(n + 1, power(fact[n], MOD - 2));
	for (int i = n; i; i--) {
		rfact[i - 1] = mult(rfact[i], i);
	}

	auto C = [&](int n, int k) -> int {
		return mult(fact[n], mult(rfact[k], rfact[n - k]));
	};

	int ans = 0;
	for (int cnt = 0; cnt < bad; cnt++) {
		int now = bad - cnt;
		if (now % 2) {
			ans = add(ans, mult(C(bad, cnt), mult(power(k - 2, cnt), power(2, now - 1))));
		} else {
			ans = add(ans, mult(C(bad, cnt), mult(power(k - 2, cnt), mult(sub(power(2, now), C(now, now / 2)), power(2, MOD - 2)))));
		}
	}

	ans = mult(ans, power(k, good));

	cout << ans << '\n';
}