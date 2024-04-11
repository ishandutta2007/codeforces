#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
vector <int> E[N];
int L[N], R[N];
long long f[N][2];

void dfs(int x, int fa) {
	f[x][0] = f[x][1] = 0;
	for (auto v : E[x]) if (v != fa) {
		dfs(v, x);
		f[x][0] += max(abs(L[x] - L[v]) + f[v][0], abs(L[x] - R[v]) + f[v][1]);
		f[x][1] += max(abs(R[x] - L[v]) + f[v][0], abs(R[x] - R[v]) + f[v][1]);
	}
}

void work() {
	scanf("%d", &n);
	for (int i = 1; i<= n; i++) scanf("%d%d", L + i, R + i); 
	for (int i = 1; i <= n; i++) E[i].clear();
	for (int i = 1; i < n ; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, -1);
	printf("%lld\n", max(f[1][0], f[1][1]));
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();


}