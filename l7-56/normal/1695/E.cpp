#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
#define fir first
#define sec second

const int maxn = 1e6 + 10;
int n, a[2][maxn], tot, now[maxn];
char sol[2][2][maxn];
vector <pii> to[maxn];
bitset <maxn> vis, used;

vector <int> p;
void dfs(int u) {
	vis[u] = 1, p.push_back(u);
	int &j = now[u], len = to[u].size();
	while (1) {
		while (j < len && used[to[u][j].sec]) ++j;
		if (j >= len) break;
		pii pp = to[u][j];
		used[pp.sec] = 1, dfs(pp.fir), p.push_back(u);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		to[x].push_back({y, i}), to[y].push_back({x, i});
	}
	for (int i = 1; i <= n * 2; ++i) if (!vis[i]) {
		p.clear(), dfs(i), p.pop_back();
		int len = p.size() >> 1;
		if (!len) continue;
		if (len == 1) return printf("-1\n"), 0;
		vector <pii> pos;
		for (int j = 0; j < len; ++j) pos.push_back({0, tot + j});
		for (int j = len - 1; j >= 0; --j) pos.push_back({1, tot + j});
		for (int i = 0; i < len * 2; ++i) a[pos[i].fir][pos[i].sec] = p[i];
		auto paint = [](pii p, pii q, int c) {
			if (p > q) swap(p, q);
			char ch1, ch2;
			if (p.fir == q.fir) ch1 = 'L', ch2 = 'R';
			else ch1 = 'U', ch2 = 'D';
			sol[c][p.fir][p.sec] = ch1;
			sol[c][q.fir][q.sec] = ch2;
		};
		for (int i = 0; i < len * 2; i += 2) paint(pos[i], pos[i + 1], 0);
		for (int i = 1; i < len * 2; i += 2) paint(pos[i], pos[(i + 1) % (len * 2)], 1);
		tot += len;
	}
	printf("2 %d\n\n", tot);
	for (int i = 0; i < tot; ++i) printf("%d%c", a[0][i], " \n"[i == tot - 1]);
	for (int i = 0; i < tot; ++i) printf("%d%c", a[1][i], " \n"[i == tot - 1]);
	printf("\n%s\n%s\n\n%s\n%s\n", sol[0][0], sol[0][1], sol[1][0], sol[1][1]);
	return 0;
}