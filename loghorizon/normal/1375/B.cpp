#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 305;

int n, m, a[N][N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &a[i][j]);
				if ((i == 1 || i == n) && (j == 1 || j == m) && a[i][j] > 2) {
					ok = false;
				}
				if (((i == 1 || i == n) || (j == 1 || j == m)) && a[i][j] > 3) {
					ok = false;
				} 
				if (a[i][j] > 4) ok = false;
			}
		}
		if (!ok) puts("NO");
		else {
			puts("YES");
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if ((i == 1 || i == n) && (j == 1 || j == m)) printf("%d ", 2);
					else if ((i == 1 || i == n) || (j == 1 || j == m)) printf("%d ", 3);
					else printf("%d ", 4);
				}
				puts("");
			}
		}
	}	
	return 0;
}