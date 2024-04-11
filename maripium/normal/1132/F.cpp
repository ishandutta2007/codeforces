#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char s[N];
int f[N][N];

int main() {
	int n;
	scanf("%d %s", &n, s + 1);
	for (int l = n; l > 0; --l) {
		f[l][l] = 1;
		for (int r = l + 1; r <= n; ++r) {
			f[l][r] = f[l + 1][r] + 1;
			for (int md = l + 1; md <= r; ++md) {
				if (s[l] == s[md]) {
					f[l][r] = min(f[l][r], f[l + 1][md] + f[md + 1][r]);
				}
			}
		}
	}
	printf("%d\n", f[1][n]);
}