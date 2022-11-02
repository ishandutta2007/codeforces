#include <bits/stdc++.h>

using namespace std;

int n, p[4000011], a[4000001][2], b[4000001][2], f[2000011], v[2000011];
char s[2000011], t[4000011];
const int P = 51123987;

inline void manacher() {
	n = strlen(s + 1);
	int m = 0;
	t[++m] = '$';
	for (int i = 1; i <= n; i++)
		t[++m] = s[i], t[++m] = '$';
	int M = 0, R = 0;
	for (int i = 1; i <= m; i++) {
		if (i > R)
			p[i] = 1;
		else {
			int k = 2 * M - i;
			p[i] = min(p[k], R - i + 1);
		}
		while (i - p[i] > 0 && i + p[i] <= m && t[i - p[i]] == t[i + p[i]])
			++p[i];
		if (i + p[i] - 1 > R)
			M = i, R = i + p[i] - 1;
	}
	int cnt = 0;
	long long tot = 0;
	for (int i = 2; i < m; i++) {
		a[++cnt][0] = (i - p[i] + 2) / 2;
		a[cnt][1] = i / 2;
		b[cnt][0] = (i + 1) / 2;
		b[cnt][1] = (i + p[i] - 1) / 2;
		tot += a[cnt][1] - a[cnt][0] + 1;
	}
	tot %= P;
	long long ans = tot * (tot - 1) / 2;
	for (int i = 1; i <= cnt; i++)
		++f[b[i][0]], --f[b[i][1] + 1];
	for (int i = 1; i <= n; i++)
		f[i] += f[i - 1], f[i] %= P;
	for (int i = 1; i <= cnt; i++)
		++v[a[i][0]], --v[a[i][1] + 1];
	for (int i = 1; i <= n + 1; i++)
		v[i] += v[i - 1], v[i] %= P;
	for (int i = 1; i <= n + 1; i++)
		v[i] += v[i - 1], v[i] %= P;
	for (int i = 1; i <= n; i++) {
		ans -= 1LL * f[i] * (v[n + 1] - v[i] + P) % P;
		ans += P;
		ans %= P;
	}
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	manacher();
}