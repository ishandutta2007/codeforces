// LUOGU_RID: 93358146
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

const int maxn = 1010;
int n, k, dlt[maxn][maxn];
char s[maxn][maxn], ans[maxn][maxn];
void work() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= n; ++j) ans[i][j] = '1';
		ans[i][n + 1] = 0;
	}
	for (int i = 1; i <= n - k + 1; ++i)
		for (int j = 1; j <= n - k + 1; ++j) {
			dlt[i][j] = max(dlt[i - 1][j], dlt[i][j - 1]);
			while (dlt[i][j] <= min(n - i, n - j) && s[i + dlt[i][j]][j + dlt[i][j]] == '0') ++dlt[i][j];
			if (dlt[i][j] > min(n - i, n - j)) return printf("NO\n"), void();
			ans[i + dlt[i][j]][j + dlt[i][j]] = '0';
		}
	printf("YES\n");
	for (int i = 1; i <= n; ++i) printf("%s\n", ans[i] + 1);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}