#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;

inline int mult(int a, int b) {
	return (ll) a * b % MOD;
}

inline int add(int a, int b) {
	a += b;
	return a - MOD * (a >= MOD);
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

int C(int n, int k, vector<int> &fact, vector<int> &rfact) {
	return mult(fact[n], mult(rfact[k], rfact[n - k]));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll n, k;
	cin >> n >> k;
	if (k > n - 1) {
		cout << "0\n";
		return 0;
	}

	vector<int> fact(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		fact[i] = mult(fact[i - 1], i);
	}
	vector<int> rfact(n + 1, power(fact[n], MOD - 2));
	for (int i = n; i; i--) {
		rfact[i - 1] = mult(rfact[i], i);
	}

	if (!k) {
		cout << fact[n] << '\n';
	} else {
		int ans = 0;
		for (int i = 0; i < n - k; i++) {
			int loc = mult(C(n - k, i, fact, rfact), power(n - k - i, n));
			if (i % 2) {
				ans = sub(ans, loc);
			} else {
				ans = add(ans, loc);
			}
		}
		cout << mult(ans, mult(C(n, n - k, fact, rfact), 2)) << '\n';
	}
}