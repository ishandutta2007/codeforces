#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
set <int> neigh[Maxn];
vector <int> isin[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			neigh[i].clear();
			isin[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b; scanf("%d %d", &a, &b);
			neigh[a].insert(b);
			neigh[b].insert(a);
		}
		vector <int> Q;
		for (int i = 1; i <= n; i++) if (neigh[i].size() == 1)
			Q.push_back(i);
		int res = 0;
		for (int i = 0; i < Q.size(); i++) {
			int v = Q[i];
			if (!neigh[v].empty()) {
				int u = *neigh[v].begin();
				isin[u].push_back(v);
				if (isin[u].size() == k) {
					res++;
					while (!isin[u].empty()) {
						int a = isin[u].back(); isin[u].pop_back();
						neigh[a].erase(u); neigh[u].erase(a);
						if (neigh[a].size() == 1)
							Q.push_back(a);
						if (neigh[u].size() == 1)
							Q.push_back(u);
					}
				}
			}
		}
		printf("%d\n", res);
	}
    return 0;
}