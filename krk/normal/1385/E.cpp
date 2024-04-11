#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, m;
int typ[Maxn], x[Maxn], y[Maxn];
vector <int> neigh[Maxn];
int tk[Maxn];
int cur, col[Maxn];

bool Fall(int v)
{
	if (tk[v] == 1) return true;
	if (tk[v] == 2) return false;
	tk[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++)
		if (Fall(neigh[v][i])) return true;
	tk[v] = 2;
	col[v] = ++cur;
	return false;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			neigh[i].clear();
			tk[i] = col[i] = 0;
		}
		cur = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &typ[i], &x[i], &y[i]);
			if (typ[i] == 1)
				neigh[x[i]].push_back(y[i]);
		}
		bool fall = false;
		for (int i = 1; i <= n && !fall; i++) if (!tk[i])
			if (Fall(i)) fall = true;
		if (fall) printf("NO\n");
		else {
			printf("YES\n");
			for (int i = 0; i < m; i++) {
				if (typ[i] == 0 && col[x[i]] < col[y[i]])
					swap(x[i], y[i]);
				printf("%d %d\n", x[i], y[i]);
			}
		}
	}
    return 0;
}