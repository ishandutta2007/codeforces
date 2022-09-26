#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, s;
vector<int> g[N];

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 2; i <= n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	int cnt = 0;
	for (int u = 1; u <= n; ++u) {
		cnt += int(g[u].size()) == 1;
	}
	printf("%.9lf", (double) (2.0 * s) / (double)(cnt));
}