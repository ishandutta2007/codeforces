#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 60;
int n;
char mp[maxn][maxn];
bool er[maxn][maxn][maxn],ec[maxn][maxn][maxn];

int f[maxn][maxn][maxn][maxn];
int dfs(int sx, int sy, int ex, int ey) {
	// printf("(%d, %d, %d, %d)\n", sx, sy, ex, ey);
	#define val f[sx][sy][ex][ey]
	if (sx > ex || sy > ey) return 0;
	if (val != -1) return val;
	val = max(ex - sx + 1, ey - sy + 1);
	for (int i = sx; i <= ex; ++i)
		if (er[i][sy][ey]) val = min(val, dfs(sx, sy, i - 1, ey) + dfs(i + 1, sy, ex, ey));
	for (int j = sy; j <= ey; ++j)
		if (ec[j][sx][ex]) val = min(val, dfs(sx, sy, ex, j - 1) + dfs(sx, j + 1, ex, ey));
	return val;
	#undef val
}

int main() {
	memset(f, -1, sizeof f);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
	for (int i = 1; i <= n; ++i) {
		for (int l = 1, r; l <= n;) {
			while (l <= n && mp[i][l] == '#') ++l;
			if (l > n) break;
			for (r = l; r <= n && mp[i][r] == '.'; ++r);
			for (int jl = l; jl < r; ++jl)
				for (int jr = jl; jr < r; ++jr)
					er[i][jl][jr] = 1;
			l = r;
		}
	}
	for (int j = 1; j <= n; ++j) {
		for (int l = 1, r; l <= n;) {
			while (l <= n && mp[l][j] == '#') ++l;
			if (l > n) break;
			for (r = l; r <= n && mp[r][j] == '.'; ++r);
			for (int il = l; il < r; ++il)
				for (int ir = il; ir < r; ++ir)
					ec[j][il][ir] = 1;
			l = r;
		}
	}
	printf("%d\n", dfs(1, 1, n, n));
	return 0;
}