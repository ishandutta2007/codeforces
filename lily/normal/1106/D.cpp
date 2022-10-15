#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second

#define N 100005

int n, m;

vector <int> E[N];

priority_queue <int, vector <int>, greater <int> > q; 

bool vis[N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	q.push(1);
	vis[1] = 1;
	while (!q.empty()) {
		int x = q.top(); q.pop();
		printf("%d ", x);
		for (auto v : E[x]) {
			if (!vis[v]) {
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	
	return 0;
}