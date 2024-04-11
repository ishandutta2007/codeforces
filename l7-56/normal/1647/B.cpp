#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 110;
int n,m;
char mp[maxn][maxn];
void work() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (mp[i][j] == '1') {
				int x = i, y = j;
				while (x + 1 <= n && mp[x + 1][j] == '1') ++x;
				while (y + 1 <= m && mp[i][y + 1] == '1') ++y;
				for (int p = i; p <= x; ++p)
					for (int q = j; q <= y; ++q)
						if (mp[p][q] == '0') return printf("NO\n"), void();
						else mp[p][q] = '0';
				for (int p = i; p <= x; ++p) {
					if (j > 1 && mp[p][j - 1] == '1') return printf("NO\n"), void();
					if (y < m && mp[p][y + 1] == '1') return printf("NO\n"), void();
				}
				for (int q = j; q <= y; ++q) {
					if (i > 1 && mp[i - 1][q] == '1') return printf("NO\n"), void();
					if (x < n && mp[x + 1][q] == '1') return printf("NO\n"), void();
				}
			}
	printf("YES\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}