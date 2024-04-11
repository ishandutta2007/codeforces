#include <bits/stdc++.h>
using namespace std;

char c[2005];
long long sum[2005];
int r[2005];
int T;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--) {
		int n, k; long long x; cin >> n >> k >> x;
		scanf("%s", c + 1);
		sum[n + 1] = 1;
		for (int r = n, l; r >= 1; r = l - 1) {
			l = r;
			if (c[l] == 'a') {
				sum[l] = sum[l + 1];
				continue;
			}
			while (l > 1 && c[l - 1] == '*') --l;
			int coef = k * (r - l + 1) + 1;
			::r[l] = r;
			if (sum[r + 1] > x / coef) sum[l] = x;
			else sum[l] = sum[r + 1] * coef;
		}
		for (int i = 1; i <= n; ) {
			if (c[i] == '*') {
				while (x > sum[r[i] + 1]) {
					putchar('b');
					x -= sum[r[i] + 1];
				}
				i = r[i] + 1;
			} else {
				putchar('a');
				++i;
			}
		}
		putchar('\n');
	}
	return 0;
}