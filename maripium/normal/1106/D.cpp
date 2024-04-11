#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
vector<int> g[N];
set<int> s;
bool visit[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	s.insert(1);
	int cnt = 0;
	while (cnt < n) {
		int u = *s.begin();
		s.erase(u);
		if (visit[u]) {
			continue;
		}
		++cnt;
		visit[u] = true;
		printf("%d ", u);
		for (int v : g[u]) {
			s.insert(v);
		}
	}
}