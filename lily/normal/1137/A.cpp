#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)

#define N 1005

int n, m;
int a[N][N], r[N][N], c[N][N], R[N], C[N];
pii b[N];


int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			read(a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) b[j] = mp(a[i][j], j); 
		sort(b + 1, b + m + 1);
		int cc = 0, last = -1;
		for (int j = 1; j <= m; j++) {
			if (last != b[j].x) last = b[j].x, cc++;
			r[i][b[j].y] = cc;
		}
		R[i] = cc;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) b[j] = mp(a[j][i], j); 
		sort(b + 1, b + n + 1);
		int cc = 0, last = -1;
		for (int j = 1; j <= n; j++) {
			if (last != b[j].x) last = b[j].x, cc++;
			c[b[j].y][i] = cc;
		}
		C[i] = cc;
	}
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= m; j++) {
			int lr = r[i][j] - 1, rr = R[i] - r[i][j];
			int lc = c[i][j] - 1, rc = C[j] - c[i][j];
			printf("%d ", max(lr, lc) + max(rr, rc) + 1);
		}
		puts("");
	}
	
	

	return 0;
}