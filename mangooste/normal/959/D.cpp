#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2000001;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	vector<int> prime(MAXN);
	iota(prime.begin(), prime.end(), 0);
	for (int i = 2; i < MAXN; i++) {
		if (prime[i] == i) {
			for (int j = 2 * i; j < MAXN; j += i) {
				prime[j] = min(prime[j], i);
			}
		}
	}

	auto get_primes = [&](int x) -> vector<int> {
		vector<int> primes;
		while (x != 1) {
			int p = prime[x];
			while (x % p == 0) {
				x /= p;
			}
			primes.push_back(p);
		}
		return primes;
	};

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &el : a) {
		cin >> el;
	}

	vector<char> used(MAXN, 0);
	int pref = 0;
	for(; pref < n; pref++) {
		vector<int> primes = get_primes(a[pref]);

		bool ok = true;
		for (auto p : primes) {
			ok &= !used[p];
		}

		if (!ok) {
			break;
		}

		for (auto p : primes) {
			used[p] = 1;
		}
	}

	for (int i = 0; i < pref; i++) {
		cout << a[i] << ' ';
	}

	if (pref == n) {
		return 0;
	}

	for (int i = a[pref];; i++) {
		vector<int> primes = get_primes(i);

		bool ok = true;
		for (auto p : primes) {
			ok &= !used[p];
		}

		if (ok) {
			cout << i << ' ';
			for (auto p : primes) {
				used[p] = 1;
			}
			break;
		}
	}

	int pos = 2;
	for (int i = pref + 1; i < n; i++) {
		while (prime[pos] != pos || used[pos]) {
			pos++;
		}
		used[pos] = 1;
		cout << pos << ' ';
	}
}