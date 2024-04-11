#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e5 + 10, T = 1000;
typedef bitset <maxn> BI;
int n,m,d,a[maxn][10],b[maxn][10],p[maxn];
vector <int> A, pos[maxn * 10];
BI t[110];
int cnt, id[maxn * 10];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]), A.push_back(a[i][j]);
		scanf("%d", &a[i][0]), p[i] = i;
	}
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	d = A.size();
	sort(p + 1, p + n + 1, [] (int x, int y) { return a[x][0] < a[y][0]; });
	for (int i = 1; i <= n; ++i) {
		b[i][0] = a[p[i]][0];
		for (int j = 1; j <= m; ++j) {
			b[i][j] = lower_bound(A.begin(), A.end(), a[p[i]][j]) - A.begin() + 1;
			pos[b[i][j]].push_back(i);
		}
	}
	for (int i = 1; i <= d; ++i)
		if ((int) pos[i].size() >= T) {
			id[i] = ++cnt;
			t[cnt].set();
			for (int x : pos[i]) t[cnt].set(x, 0);
		}
	BI now;
	int ans = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		now.set();
		now.set(0, 0);
		now.set(i, 0);
		for (int j = 1; j <= m; ++j) {
			int x = b[i][j];
			if ((int) pos[x].size() >= T) now &= t[id[x]];
			else {
				for (int y : pos[x]) now.set(y, 0);
			}
		}
		int x = now._Find_first();
		if (x > n) continue;
		ans = min(ans, b[i][0] + b[x][0]);
	}
	printf("%d\n", ans == INT_MAX ? -1 : ans);
	return 0;
}