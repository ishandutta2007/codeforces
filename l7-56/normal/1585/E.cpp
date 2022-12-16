#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 1e6 + 10;
int T,n,m,Q,fa[maxn],a[maxn];
vector <int> son[maxn],A;

int ans[maxn];
struct Query {
	int l,k,id;
};
vector <Query> q[maxn];

int cnt[maxn];
int p[maxn],pos[maxn],st[maxn];

void dfs(int u) {
	int pos1 = pos[a[u]], pos2 = --st[++cnt[a[u]]];
	pos[p[pos2]] = pos1, pos[p[pos1]] = pos2;
	swap(p[pos1], p[pos2]);
	for (Query x : q[u]) {
		int l = x.l, k = x.k;
		if (st[l] + k - 1 <= m) ans[x.id] = A[p[st[l] + k - 1] - 1];
		else ans[x.id] = -1;
	}
	q[u].clear();
	for (int v : son[u]) dfs(v);
	swap(p[pos1], p[pos2]);
	pos[p[pos1]] = pos1, pos[p[pos2]] = pos2;
	++st[cnt[a[u]]--];
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &Q);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), A.push_back(a[i]), son[i].clear();
		for (int i = 2; i <= n; ++i) scanf("%d", &fa[i]), son[fa[i]].push_back(i);
		sort(A.begin(), A.end());
		A.erase(unique(A.begin(), A.end()), A.end());
		m = A.size();
		for (int i = 1; i <= m; ++i) p[i] = i, pos[i] = i, cnt[i] = 0;
		st[0] = 1;
		for (int i = 1; i <= n; ++i) st[i] = m + 1;
		for (int i = 1; i <= n; ++i) a[i] = lower_bound(A.begin(), A.end(), a[i]) - A.begin() + 1;
		for (int i = 1; i <= Q; ++i) {
			int v,l,k;
			scanf("%d%d%d", &v, &l, &k);
			q[v].push_back({l, k, i});
		}
		dfs(1);
		for (int i = 1; i <= Q; ++i)
			printf("%d%c", ans[i], " \n"[i == Q]);
		A.clear();
	}
	return 0;
}