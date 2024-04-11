#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)
typedef pair<int, int> pii;

#define N 101111

int n;
int p[N], dep[N], son[N], top[N];
vector <int> E[N];

void dfs(int x) {
	dep[x] = 1;
	for (auto v : E[x]) {
		if (v != p[x]) {
			dfs(v);
			dep[x] = max(dep[x], dep[v] + 1);
		}
	}
}

int cur;
int id[N], q[N];

vector <pii> F[N];

void work(int x) {
	q[cur] = x;
	id[x] = cur++;
	for (auto v : E[x]) {
		if (v != p[x]) {
			F[x].push_back({dep[v], v});
		}
	}
	sort(F[x].begin(), F[x].end());

	for (auto v : F[x]) {
		work(v.second);
	}
}

int main() {
	read(n);
	for (int i = 1; i < n; i++) {
		read(p[i]);
		E[p[i]].push_back(i);
	}
	dfs(0);
	work(0);
	for (int i = 0; i < n; i++) printf("%d%c", q[i], i == (n - 1) ? '\n' : ' ');
	vector <int> ans;
	for (int i = 1; i < n; i++) {
		int fa = q[i - 1];
		while (fa != p[q[i]]) {
			ans.push_back(q[i]);
			fa = p[fa];
		}
	}
	printf("%d\n", int(ans.size()));
	for (auto v : ans) printf("%d ", v);
}