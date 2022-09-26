#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, m;
vector<int> from[N], to[N];
bool visit[N], choose[N];
int cnt = 0;

void brute(int u) {
	if (u == n + 1) return;
	if (visit[u]) {
		brute(u + 1); return;
	}
	visit[u] = true;
	for (int v : from[u]) {
		visit[v] = true;
	}
	brute(u + 1);
	bool add = true;
	for (int v : to[u]) if (choose[v]) {
		add = false;
	}
	if (add) choose[u] = 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		from[u].push_back(v), to[v].push_back(u);
	}
	brute(1);
	printf("%d\n", accumulate(choose + 1, choose + 1 + n, 0));
	for (int i = 1; i <= n; ++i) if (choose[i]) printf("%d ", i); printf("\n");
}