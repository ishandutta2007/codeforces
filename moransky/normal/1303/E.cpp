#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 405, INF = 0x3f3f3f3f;
int n, m, f[N][N], sum[N][26];
char s[N], t[N];
bool check0() {
	int j = 0;
	for (int i = 1; i <= n; i++) {
		if (j < m && t[j + 1] == s[i]) j++;
	}
	return j == m;
}
bool check(int mid) {
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for (int i = 0; i <= mid; i++) {
		for (int j = 0; j <= m - mid; j++) {
			if (i && f[i - 1][j] < n) {
				int l = f[i - 1][j] + 1, r = n, ch = t[i] - 'a';
				while (l < r) {
					int mid = (l + r) >> 1;
					if (sum[mid][ch] - sum[f[i - 1][j]][ch] >= 1) r = mid;
					else l = mid + 1;
				}
				if (sum[r][ch] - sum[f[i - 1][j]][ch] >= 1) f[i][j] = r;
			} 
			if (j && f[i][j - 1] < n) {
				int l = f[i][j - 1] + 1, r = n, ch = t[j + mid] - 'a';
				while (l < r) {
					int mid = (l + r) >> 1;
					if (sum[mid][ch] - sum[f[i][j - 1]][ch] >= 1) r = mid;
					else l = mid + 1;
				}
				if (sum[r][ch] - sum[f[i][j - 1]][ch] >= 1) f[i][j] = min(f[i][j], r);
			}
		}
	}
	return f[mid][m - mid] <= n;
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {

		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 26; j++) sum[i][j] = sum[i - 1][j];
			sum[i][s[i] - 'a']++;
		}
		if (check0()) {
			puts("YES");
		} else {
			bool ok = false;
			for (int c = 1; c < m; c++) {
                if (check(c)) {
					ok = true;
					puts("YES");
					break;
				}
			}
			if (!ok) puts("NO");
		}
	}
	return 0;
}