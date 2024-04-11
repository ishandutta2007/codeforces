#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 100100;
const int MAX2N = 2 * MAXN;
const int MOD = 1000000007;

const int MAXK = 2222;

int fact[MAX2N];
int inv_fact[MAX2N];

int power(int a, int p) {
	int result = 1;
	while (p) {
		if (p & 1) {
			result = (result * 1ll * a) % MOD;
		}

		a = (a * 1ll * a) % MOD;
		p /= 2;
	}

	return result;
}

int inv(int a) {
	return power(a, MOD - 2);
}

void preprocess() {
 	fact[0] = inv_fact[0] = 1;
 	for (int i = 1; i < MAX2N; i++) {
 		fact[i] = (fact[i - 1] * 1ll * i) % MOD;
 		inv_fact[i] = inv(fact[i] );
 	}

}

int cnk(int n, int k) {
	int result = fact[n];
	result = (result * 1ll * inv_fact[k] ) % MOD;
	result = (result * 1ll * inv_fact[n - k] ) % MOD;

	return result;
}

int board(int n, int m) {
	return cnk(n + m - 2, n - 1);
}

int h, w;

int k;
pair<int, int> p[MAXK];
int c[MAXK][MAXK];
int f[MAXK];

void solve() {
	cin >> h >> w >> k;
	for (int i = 0; i < k; i++) {
		cin >> p[i].first >> p[i].second;
	}
	p[k] = make_pair(1, 1);
	p[k + 1] = make_pair(h, w);
	k += 2;

	sort(p, p + k);

	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (p[i].second > p[j].second) {
				continue;
			}

			int dx = p[j].first - p[i].first + 1;
			int dy = p[j].second - p[i].second + 1;

			c[i][j] = board(dx, dy);
		}
	}

	f[0] = 0;

	for (int i = 1; i < k; i++) {
		f[i] = board(p[i].first, p[i].second);

		for (int j = 0; j < i; j++) {
			int delta = (f[j] * 1ll * c[j][i] ) % MOD;
			f[i] = (f[i] + MOD - delta) % MOD;
		}
	}

	cout << f[k - 1] << "\n";
}

int main() {
	preprocess();

	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}