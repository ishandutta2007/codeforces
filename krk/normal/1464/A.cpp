#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, m;
vector <int> neigh[Maxn];
bool tk[Maxn];

void Fill(int v)
{
	if (tk[v]) return;
	tk[v] = true;
	for (int i = 0; i < neigh[v].size(); i++)
		Fill(neigh[v][i]);
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			neigh[i].clear();
			tk[i] = false;
		}
		int has = 0, comp = 0, sub = 0;
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			if (a != b) {
				has++;
				neigh[a].push_back(b);
				neigh[b].push_back(a);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!neigh[i].empty() && !tk[i]) {
				comp++;
				Fill(i);
			}
			if (neigh[i].size() == 1) sub++;
		}
		printf("%d\n", comp + has - sub / 2);
	}
    return 0;
}