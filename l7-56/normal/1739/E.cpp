#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

#define chkmx(x, y) ((x) = max(x, y))
#define in(x, y) (((x) >> (y)) & 1)
const int maxn = 2e5 + 10;
int n, f[maxn][2][4], a[maxn];

int main() {
	scanf("%d", &n);
	for (int j = 0; j < 2; ++j) {
		char s[maxn]; scanf("%s", s + 1);
		for (int i = 1; i <= n; ++i) a[i] |= (s[i] == '1') << j;
	}
	memset(f, 0xaf, sizeof f);
	f[1][0][a[1]] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j : {0, 1}) {
			int nj = !j;
			for (int k = 0; k < 4; ++k) if (f[i][j][k] >= 0) {
				if (in(k, nj))
					chkmx(f[i + 1][j][a[i + 1]], f[i][j][k] + in(a[i + 1], j)),
					chkmx(f[i + 1][nj][a[i + 1] & (3 ^ (1 << j))], f[i][j][k] + 1 + in(a[i + 1], nj));
				else chkmx(f[i + 1][j][a[i + 1]], f[i][j][k] + in(a[i + 1], j));
			}
		}
	int ans = 0;
	for (int j : {0, 1})
		for (int k = 0; k < 4; ++k)
			ans = max(ans, f[n + 1][j][k]);
	printf("%d\n", ans);
	return 0;
}