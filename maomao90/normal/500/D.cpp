#include <bits/stdc++.h>
using namespace std; 

#define mp make_pair
#define FI first
#define SE second
typedef pair <int, int> ii;
typedef tuple <int, int, int> iii;
typedef long long ll;

int n;
vector<ii> adjList[100005];
iii edge[100005];
int q;
ll choose[100005][5], times[100005], all, ans;

int subtree[100005];
int getSubtree(int u, int p) {
	subtree[u] = 1;
	for (ii vi : adjList[u]) {
		if (vi.FI == p) continue;
		subtree[u] += getSubtree(vi.FI, u);
	}
	return subtree[u];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, l; scanf("%d%d%d", &a, &b, &l);
		edge[i] = iii(a, b, l);
		adjList[a].emplace_back(b, i);
		adjList[b].emplace_back(a, i);
	}
	for (int i = 0; i <= n; i++) {
		choose[i][0] = 1;
		for (int j = 1; j <= min(4, i); j++) {
			choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
		}
	}
	getSubtree(1, -1);
	for (int i = 0; i < n - 1; i++) {
		int u, v, l; tie(u, v, l) = edge[i];
		if (subtree[u] > subtree[v]) swap(u, v);
		int lft = subtree[u], rht = n - subtree[u];
		times[i] = (ll) lft * rht;
		ans += l * times[i];
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int r, w; scanf("%d%d", &r, &w);
		r--;
		int u, v, l; tie(u, v, l) = edge[r];
		if (subtree[u] > subtree[v]) swap(u, v);
		int lft = subtree[u], rht = n - subtree[u];
		ans -= (ll) (l - w) * lft * rht;
		printf("%f\n", (double) ans * (n - 2) / choose[n][3]);
		edge[r] = iii(u, v, w);
	}
	return 0;
}