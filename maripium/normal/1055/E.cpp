#include <bits/stdc++.h>
using namespace std;

const int N = 1505;

int n, s, m, k;
int a[N], f[N][N];
int nxt[N], pre[N];

int main() {
	scanf("%d %d %d %d", &n, &s, &m, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= s; ++i) {
		int l, r; scanf("%d %d", &l, &r);
		for (int j = l - 1; j <= r - 1; ++j) {
			nxt[j] = max(nxt[j], r);
		}
	}
	int low = 0, high = 1e9 + 123;
	while (low < high) {
		int mid = (low + high) >> 1;
		
		for (int i = 1; i <= n; ++i) {
			pre[i] = pre[i - 1] + (a[i] <= mid);
		}
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				f[i][j] = 0;
			}
		}
		
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				f[i + 1][j] = max(f[i + 1][j],f[i][j]);
				if (nxt[i] > i && j < m) {
					f[nxt[i]][j + 1] = max(f[nxt[i]][j + 1], f[i][j] + pre[nxt[i]] - pre[i]);
				} 	
			}			
		}
		
		if (f[n][m] >= k) high = mid;
		else low = mid + 1;
	}
	printf("%d\n", (low == 1e9 + 123 ? -1 : low));
}