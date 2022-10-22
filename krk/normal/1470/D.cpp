#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
int n, m;
vector <int> neigh[Maxn];
bool tk[Maxn];
bool has[Maxn];

void Traverse(int v, bool col)
{
	if (col) {
		tk[v] = true;
		has[v] = true;
		vector <int> seq;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (!tk[u]) {
				seq.push_back(u);
				tk[u] = true;
			}
		}
		for (int i = 0; i < seq.size(); i++)
			Traverse(seq[i], false);
	} else {
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (!tk[u]) Traverse(u, true);
		}
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			neigh[i].clear();
			tk[i] = has[i] = false;
		}
		for (int i = 1; i <= m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			neigh[a].push_back(b);
			neigh[b].push_back(a);
		}
		Traverse(1, true);
		bool all = true;
		vector <int> seq;
		for (int i = 1; i <= n; i++) {
			if (!tk[i]) all = false;
			if (has[i]) seq.push_back(i);
		}
		if (all) {
			printf("YES\n");
			printf("%d\n", int(seq.size()));
			for (int i = 0; i < seq.size(); i++)
				printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
		} else printf("NO\n");
	}
    return 0;
}