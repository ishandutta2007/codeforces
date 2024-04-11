#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

vector <pair <int, int>> work(int n, int d12, int d23, int d31) {
	for (int i = 0; i <= min(d12, d31); i++) {
		if (d12 - i + d31 - i == d23) {
			int req = 1 + i + d23;
			if (req <= n) {
				int dep = 1, node = n, last = 1;
				vector <pair <int, int>> e;
				if (i == 0) {
					dep = 0;
				}
				else {
					while (dep < i) {
						e.push_back({last, node});
						last = node;
						node --;
						dep ++;
					}
					if (i == d12) {
						e.push_back({last, 2});
						if (i == d31) e.push_back({last, 3});
						else last = 2;
					}
					else if (i == d31) e.push_back({last, 3}), last = 3;
					else if (dep == i) {
						e.push_back({last, node});
						last = node;
						node --;
					}
				}
				if (dep < d12) {
					for (int w = last, j = dep + 1; j <= d12; j++) {
						if (j == d12) e.push_back({w, 2});
						else {
							e.push_back({w, node});
							w = node;
							node--;
						}
					}
				}
				if (dep < d31) {
					for (int w = last, j = dep + 1; j <= d31; j++) {
						if (j == d31) e.push_back({w, 3});
						else {
							e.push_back({w, node});
							w = node;
							node--;
						}
					}
				}
				while (node > 3) e.push_back({1, node--});
				return e;
			}
		}
	}
	return {};
}

int f[21];
int getf(int x) {
	return f[x] ==  x ? x : (f[x] = getf(f[x]));
}

vector <int> E[21];
int dfs(int x, int fa, int y) {
	if (x == y) return 0;
	for (auto v : E[x]) if (v != fa) {
		int ret = dfs(v, x, y);
		if (ret >= 0) return ret + 1;
	}
	return -1;
}
int main() {
/*	int n = 20;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			for (int k = 1; k < n; k++) {
				auto ret = work(n, i, j, k);
				if (ret.empty()) continue;
				for (int i = 1; i <= n; i++) f[i] = i, E[i].clear();
#undef assert
#define assert(x) if (!(x)) { printf("%d %d %d %d %d %d %d\n", n, i, j, k, dfs (1, -1, 2), dfs (2, -1, 3), dfs (3, -1, 1)); for (auto i : ret) printf("%d %d\n", i.first, i.second);return 0;}
				for (auto v : ret) {
					E[v.first].push_back(v.second);
					E[v.second].push_back(v.first);
					assert (getf(v.first) != getf(v.second));
					f[getf(v.first)] = getf(v.second);
				}
				assert ( dfs (1, -1, 2) == i);
				assert ( dfs (2, -1, 3) == j);
				assert ( dfs (3, -1, 1) == k);
			}
		}
	}*/
	int T;
	read(T);
	while (T--) {
		int n, d12, d23, d31;
		read(n); read(d12); read(d23); read(d31);
		auto ret = work(n, d12, d23, d31);
		if (ret.empty()) puts ("NO");
		else {
			puts ("YES");
			for (auto i : ret) {
				printf("%d %d\n", i.first, i.second);
			}
		}
	}

}