#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 110;
int n,m;
char mp[maxn][maxn];
void work() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
	if (mp[1][1] == '1') return printf("-1\n"), void();
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			ans += (mp[i][j] == '1');
	printf("%d\n", ans);
	for (int i = n; i >= 1; --i)
		for (int j = m; j >= 1; --j)
			if (mp[i][j] == '1') {
				if (i > 1) printf("%d %d %d %d\n", i - 1, j, i, j);
				else if (j > 1) printf("%d %d %d %d\n", i, j - 1, i, j);
			}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}