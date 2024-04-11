#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int T;
int n;
vector <int> neigh[Maxn];
int a[Maxn];
int mylvl[Maxn];
vector <ii> L[Maxn];
int mxlvl;
ll best[Maxn];
ll dp[Maxn];

void Traverse(int v, int p, int lvl)
{
	mylvl[v] = lvl;
	L[lvl].push_back(ii(a[v], v));
	mxlvl = max(mxlvl, lvl);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v, lvl + 1);
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			neigh[i].clear();
		for (int i = 2; i <= n; i++) {
			int a; scanf("%d", &a);
			neigh[i].push_back(a);
			neigh[a].push_back(i);
		}
		for (int i = 2; i <= n; i++)
			scanf("%d", &a[i]);
		mxlvl = 0;
		Traverse(1, 0, 0);
		for (int i = mxlvl; i >= 0; i--) {
			sort(L[i].begin(), L[i].end());
			ll all = -Inf, notall = -Inf;
			for (int j = 0; j < L[i].size(); j++) {
				int v = L[i][j].second;
				best[v] = 0;
				for (int z = 0; z < neigh[v].size(); z++) {
					int u = neigh[v][z];
					if (mylvl[u] <= mylvl[v]) continue;
					best[v] = max(best[v], dp[u]);
				}
				all = max(all, best[v] - L[i][j].first);
				notall = max(notall, -ll(L[i][j].first));
				dp[v] = max(all + L[i][j].first, notall + L[i][j].first + best[v]);
			}
			all = -Inf, notall = -Inf;
			for (int j = int(L[i].size()) - 1; j >= 0; j--) {
				int v = L[i][j].second;
				dp[v] = max(dp[v], max(all - L[i][j].first, notall - L[i][j].first + best[v]));
				all = max(all, best[v] + L[i][j].first);
				notall = max(notall, ll(L[i][j].first));
			}
			L[i].clear();
		}
		printf("%I64d\n", dp[1]);
	}
    return 0;
}