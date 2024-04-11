#include <iostream>
#include <cstdio>

using namespace std;

const int N = 41, S = 20;

int n, a[N][N], f[1 << S], Log[1 << S], c[1 << S], gg[1 << S], g[1 << S], d[1 << S];

double s;

void out(int x, int k) {
	for (int i = 0; i < k; i++)
		printf("%d", x >> i & 1);
}

int main() {
	//freopen("a1.in", "r", stdin);
	scanf("%d%lf", &n, &s);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		} 
	}
//	if (n == 1) {
//		puts("0");
//	} else if (n == 2) {
//		if (a[2][1]) printf("%.9f\n", (s / 2) * (s / 2));
//		else puts("0");
//	} else if (n == 3) {
//		if (cnt == 0) puts("0");
//		else if (cnt == 1 || cnt == 2)  printf("%.9f\n", (s / 2) * (s / 2)); 
//		else printf("%.9f\n", 3 * (s / 3) * (s / 3)); 
//	} else if (cnt == tot) {
//		printf("%.9f\n", tot * (s / n) * (s / n)); 
//	} else if (cnt == tot - 1) {
//		printf("%.9f\n", (cnt - (n - 2)) * (s / (n - 1)) * (s / (n - 1))); 
//	} else 
//	if (n <= 20) {
//		for (int i = 0; i < n; i++) Log[1 << i] = i;
//		f[0] = true;
//		int m = 1;
//		for (int i = 1; i < (1 << n); i++) {
//			int j = Log[i & -i], w = i ^ (i & -i);
//			c[i] = c[w] + 1;
//			if (!f[w]) continue;
//			bool ok = true;
//			for (int k = 0; k < n; k++)
//				if ((w >> k & 1) && !a[j + 1][k + 1]) {
//					ok = false;
//					break;
//				} 
//			if (ok) f[i] = f[w], m = max(m, c[i]);
//		}
//		printf("%.9f\n", (m * (m - 1) / 2) * (s / m) * (s / m)); 
//	} else {
		int A = n / 2, B = n - A;
		int m = 1;
		for (int i = 0; i < B; i++) Log[1 << i] = i;
		for (int i = 1; i < (1 << B); i++) {
			int j = Log[i & -i], w = i ^ (i & -i);
			c[i] = c[w] + 1;
		}
		g[0] = 0, gg[0] = 1;
		for (int i = 1; i < (1 << B); i++) {
			int j = Log[i & -i], w = i ^ (i & -i);
			for (int k = 0; k < B; k++)
				if (i >> k & 1) g[i] = max(g[i], g[i ^ (1 << k)]);
			bool ok = true;
			for (int k = 0; k < B; k++) {
				if ((w >> k & 1) && !a[j + A + 1][k + A + 1]) {
					ok = false;
					break;
				} 
			}
			if (gg[w] && ok) {
				gg[i] = true;
				g[i] = c[i], m = max(m, g[i]);
				//out(i, B); cout << " " << c[i] << endl;
			}
		}
		d[0] = (1 << B) - 1, f[0] = true;
		for (int i = 1; i < (1 << A); i++) {
			int j = Log[i & -i], w = i ^ (i & -i);
			if (!f[w]) continue;
			bool ok = true;
			for (int k = 0; k < A; k++)
				if ((w >> k & 1) && !a[j + 1][k + 1]) {
					ok = false;
					break;
				} 
			if (ok) {
				f[i] = true, d[i] = d[w];
				for (int k = 0; k < B; k++)
					if ((d[i] >> k & 1) && !a[j + 1][k + A + 1]) d[i] ^= 1 << k;
				m = max(m, c[i]);
				//out(i, A); cout << " " << c[i] << endl;
				m = max(m, c[i] + g[d[i]]);
			};
		}
		//cout << m << endl;
		printf("%.9f\n", (m * (m - 1) / 2) * (s / m) * (s / m)); 
//	}
	return 0;
}