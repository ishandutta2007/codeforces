#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


#define N 201111

int n, m, K;
int d1[N], dn[N];
int a[N];
vector <int> E[N];
void bfs(int x, int dis[]) {
	for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f;
	dis[x] = 0;
	queue <int> q;
	q.push(x);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : E[u]) {
			if (dis[v] > n) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

bool cmp(int x, int y) {
	return d1[x] < d1[y];
}
set < pair<int, int>> s;
int main() {
	read(n); read(m); read(K);
	for (int i = 1; i <= K; i++) {
		read(a[i]);
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u); read(v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	bfs(1, d1);
	bfs(n, dn);
	sort(a + 1, a + K + 1, cmp);
	for (int i = 1; i <= K; i++) {
		s.insert({-dn[a[i]], a[i]});	
	}
	int ans = 0;
	for (int i = 1; i < K; i++) {
		s.erase({-dn[a[i]], a[i]});
		ans = max(ans, d1[a[i]] - s.begin()->first + 1);
	}
	ans = min(ans, d1[n]);
	cout << ans << endl;
}