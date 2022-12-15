#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100000;
const int M = 10;

int pos[M][N], p[M][N] , n, m;
ll ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &p[i][j]);
			--p[i][j];
			pos[i][p[i][j]] = j;
		}
	}
	int r = 0;
	for (int l = 0; l < n; l++) {
		r = max(r, l);
		while (r + 1 < n) {
			bool extend = 1;
			int num1 = p[0][r + 1];
			int num2 = p[0][l];
			for (int j = 0; j < m; j++) {
				if (pos[j][num1] - pos[j][num2] != r - l + 1) {
					extend = 0;
					break;
				}
			}
			if (extend) r++;
			else break;
		}
		ans += r - l + 1;
	}
	printf("%lld\n", ans);
}