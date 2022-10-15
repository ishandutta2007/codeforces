#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, p, nn;
char t[234];
bool a[N][65];
int ans = 0;


vector <int> ANS;
int dp[1 << 16];

void check(int x) {
	vector <int> bits;
	for (int i = 0; i < m; i++) {
		if (a[x][i]) bits.push_back(i);
	}
	int k = bits.size();
	if (k <= ans) return;
	for (int i = 0; i < (1 << k); i++) dp[i] = 0;

	for (int i = 0; i < n; i++) {
		int mask = 0;
		for (int j = 0; j < k; j++) {
			if (a[i][bits[j]]) mask |= 1 << j;
		}
		dp[mask] ++;
	}
	for (int i = 0; i < (1 << k); i++) {
		for (int j = (i - 1) & i; j; j = (j - 1) & i) {
			dp[j] += dp[i];
		}
	}
	for (int i = 1; i < (1 << k); i++) {
		if (dp[i] >= nn) {
			int cnt = __builtin_popcount(i);
			if (cnt > ans) {
				ans = cnt;
				vector <int> an;
				for (int j = 0; j < k; j++) {
					if ((i >> j) & 1) an.push_back(bits[j]);
				}
				ANS = an;
			}
		}
	}
}

char s[N];
int main() {
	scanf("%d%d%d", &n, &m, &p);
	nn = (n + 1) / 2;
	for (int i = 0; i < n; i++) {
		scanf("%s", t);
		for (int j = 0; j < m; j++) a[i][j] = t[j] == '1';
	}
	mt19937 rng (12312 + n);
	for (int T = 10; T; T--) {
		int x = rng() % n;
		check(x);
	}

	for (int i = 0; i < m; i++) {
		s[i] = '0';
	}
	for (auto i : ANS) s[i] = '1';
	puts(s);
}