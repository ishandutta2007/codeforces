#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mp(a, b) make_pair
#define x first
#define y second
#define read(x) scanf("%d", &x)
#define readl(x) scanf("%lld", &x)
#define readd(x) scanf("%lf", &x)

#define N 300301
#define L 19
int n, Q;
int a[N];
int last[N][L], dis[N][L];

int main() {
	read(n); read(Q);

	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 0; i < L; i++) last[n + 1][i] = n + 1;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < L; j++) {
			if (1 & (a[i] >> j)) {
				last[i][j] = i;
			}
			else last[i][j] = last[i + 1][j];
		}
		for (int j = 0; j < L; j++)
		if (1 & (a[i] >> j)) {
			dis[i][j] = i;
		}
		else {
			dis[i][j] = n + 1;
			for (int k = 0; k < L; k++) if (1 & (a[i] >> k)){
				dis[i][j] = min(dis[i][j], dis[last[i + 1][k]][j]);
			}
		}
	}
	for (int i = 1; i <= Q; i++) {
		int x, y;
		read(x); read(y);
		bool ans = 0;
		for (int k = 0; k < L; k++) if (1 & (a[y] >> k)){
			if (dis[x][k] <= y) {
				ans = 1;
				break;
			}
		}
		puts(ans ? "Shi" : "Fou");
	}
}