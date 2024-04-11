#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

const int N = 2e5 + 7;
int f[N];
int belong[N];
vector <int> E[N];

int getf(int x) {
	return f[x] == x ? x : (f[x] = getf(f[x]));
}
set <pair <int, int>> inverted;

int dfs (int x, int fa, int y) {
	if (x == y) {
		inverted.insert({x, fa});
		inverted.insert({fa, x});
		return 1;
	}
	for (auto v : E[x]) if (v != fa) {
		if (dfs (v, x, y)) return 1;
	}
	return 0;
}

int n, m;
int main() {
	int T;
	read(T);
	while (T--) {
		read(n); read(m);
		for (int i = 1; i <= n; i++) f[i] = i, E[i].clear();
		for (int i = 1; i <= m; i++) belong[i] = 0;
		inverted.clear();
		vector < pair <int, int> > e;
		vector < pair <int, int> > other;
			
		for (int i = 1; i <= m; i++) {
			int u, v;
			read(u); read(v);
			e.push_back({u, v});
			if (getf(u) != getf(v)) {
				f[getf(u)] = getf(v);
				E[u].push_back(v);
				E[v].push_back(u);
			}
			else other.push_back({u, v}), belong[i - 1] = 1;
		}
		if (other.size() == 3) {
			bool flag = false;
			for (int i = 1; i <= n; i++) f[i] = i;
			for (auto [u, v] : other) {
				if (getf(u) == getf(v)) flag = true;
				else f[getf(u)] = getf(v);
			}
			if (flag) {
				dfs (other[0].first, -1, other[0].second);
				inverted.insert (other[0]);
			}
		}
		for (int i = 0; i < m; i++) printf("%d", int(belong[i] ^ inverted.count(e[i])));
		printf("\n");
	}


}