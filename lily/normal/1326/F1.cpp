#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

#define N 16

int n, L;
char s[N + 123];
LL a[1 << N];
int g[N][N];
int c[1 << N];
vector <LL> f[(1 << N) + 5][N];

int main() {
	read(n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < n; j++) {
			g[i][j] = s[j] == '1';
		}
	}

	for (int i = 0; i < (1 << n); i++) {
		c[i] = c[i / 2] + i % 2;
		
	}
	for (int i = 0; i < (1 << n); i++) {
		c[i]--;
		for (int j = 0 ; j < n; j++) if (i & (1 << j)) {
			f[i][j].resize(1 << c[i]);
		}
	}
	for (int i = 1; i < (1 << n); i++) {
		if (!c[i]) {
	for (int j = 0; j < n; j++) if (i & (1 << j)) f[i][j][0] = 1;
		}
		for (int j = 0; j < n; j++) if (i & (1 << j)) {
			for (int l = 0; l < n; l++) if (! (i & (1 << l))) {
				for (int k = 0; k < (1 << c[i]); k++) {
					f[i | (1 << l)][l][k | (g[j][l] << c[i])]
						+= f[i][j][k];
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (1 << (n - 1)); j++)
			a[j] += f[(1 << n) - 1][i][j];
	for (int i = 0; i < (1 << (n - 1)); i++) {
		printf("%lld ", a[i]);
	}
}