#include<bits/stdc++.h>
using namespace std;

const int N = 500 + 10;

int f[N][N], a[N][N], g[N][N];
int len[N], yi[N][N];
int n, m, K;

int main() {
	scanf("%d %d %d", &n, &m, &K);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char c = getchar();
			while(c != '0' && c != '1') c = getchar();
			a[i][j] = c - 48;
			if(a[i][j] == 1) yi[i][++len[i]] = j;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < len[i]; j++) {
			g[i][j] = yi[i][len[i] - j] - yi[i][1];
			for(int k = 1; k <= j; k++) {
				g[i][j] = min(g[i][j], yi[i][len[i] - j + k] - yi[i][k + 1]);
			}
			g[i][j]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= K; j++) {
			f[i][j] = 0x3f3f3f3f;
			for(int k = 0; k <= j; k++) {
				f[i][j] = min(f[i][j], f[i - 1][k] + g[i][j - k]);
			}
		}
	}
	printf("%d", f[n][K]);
	return 0;
}