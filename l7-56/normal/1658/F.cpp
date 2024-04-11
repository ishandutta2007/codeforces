#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e6 + 10;
int n,m;
char s[maxn];
void work() {
	scanf("%d%d%s", &n, &m, s + 1);
	int b = 0;
	for (int i = 1; i <= n; ++i) {
		s[i + n] = s[i];
		b += (s[i] == '1');
	}
	if (1ll * b * m % n) return printf("-1\n"), void();
	b = 1ll * b * m / n;
	for (int l = 1, r = 0, cnt = 0; ; ++l) {
		while (r < l + m) cnt += (s[r++] == '1');
		if (cnt == b) {
			if (r <= n + 1) return printf("1\n%d %d\n", l, r - 1), void();
			else return printf("2\n%d %d\n%d %d\n", 1, r - n - 1, l, n), void();
		}
		cnt -= (s[l] == '1');
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}