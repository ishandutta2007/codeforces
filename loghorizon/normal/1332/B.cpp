#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1005;

int n, a[N], c[N], cnt[N], m, d[12] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

vector<int> g[12];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		m = 0;
		scanf("%d", &n);
		for (int i = 1; i <= 11; i++) g[i].clear();
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 11; j++) {
				if (a[i] % d[j] == 0) {
					g[j].push_back(i);
					break;
				}
			}
		}
		for (int i = 1; i <= 11; i++) {
			if (g[i].size()) {
				m++;
				for (int j = 0; j < g[i].size(); j++)
					c[g[i][j]] = m;
			}
		}
		printf("%d\n", m);
		for (int i = 1; i <= n; i++) printf("%d ", c[i]);
		puts("");
	}
	return 0;
}