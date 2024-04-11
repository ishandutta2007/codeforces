#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 2e5 + 10, mod = 998244353;
char s[maxn][3];
int n,ans,fact[maxn],inv[maxn];

int qpow(int a, int p) {
	int res = 1;
	while (p) {
		if (p & 1) res = ((ll)res * a) % mod;
		a = ((ll)a * a) % mod, p >>= 1;
	}
	return res;
}

int c(int n, int m) {
	if (n < 0 || m < 0 || m > n) return 0;
	return (ll)fact[n] * inv[m] % mod * inv[n - m] % mod;
}

bool can(char ch, char c) { return ch == '?' || ch == c; }
bool can(int i, char c1, char c2) { return can(s[i][0], c1) && can(s[i][1], c2); }

int main() {
	scanf("%d", &n);
	fact[0] = 1, inv[0] = 1;
	for (int i = 1; i <= n * 2; ++i)
		fact[i] = ((ll)fact[i - 1] * i) % mod, inv[i] = ((ll)inv[i - 1] * qpow(i, mod - 2)) % mod;
	for (int i = 1; i <= n; ++i) scanf("%s", s[i]);
	int cntb = 0, cntw = 0;
	for (int i = 1; i <= n; ++i) cntb += (s[i][0] == 'B') + (s[i][1] == 'B'), cntw += (s[i][0] == 'W') + (s[i][1] == 'W');
	ans = c(2 * n - cntb - cntw, n - cntb);
	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
	bool flag = 1;
	for (int i = 1; i <= n && flag; ++i) {
		if (!can(i, 'W', 'B') && !can(i, 'B', 'W')) flag = 0;
		else if (can(i, 'W', 'B') && !can(i, 'B', 'W')) cnt0++;
		else if (!can(i, 'W', 'B') && can(i, 'B', 'W')) cnt1++;
		else cnt2++;
	}
	if (flag) {
		for (int i = 1; i < n; ++i)
			ans = ((ans - c(cnt2, i - cnt0)) % mod + mod) % mod;
	}
	printf("%d\n", ans);
	return 0;
}