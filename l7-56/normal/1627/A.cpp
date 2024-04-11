#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 60;
char mp[maxn][maxn];
int n,m,r,c;
void work() {
	scanf("%d%d%d%d", &n, &m, &r, &c);
	for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
	if (mp[r][c] == 'B') { printf("0\n"); return; }
	bool flag = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			flag |= (mp[i][j] == 'B');
		}
	}
	if (!flag) { printf("-1\n"); return; }
	flag = 0;
	for (int i = 1; i <= n; ++i) flag |= mp[i][c] == 'B';
	for (int j = 1; j <= m; ++j) flag |= mp[r][j] == 'B';
	if (flag) printf("1\n");
	else printf("2\n");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();
	return 0;
}