#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int n;
int D[Maxn][Maxn];
int root;
vector <int> neigh[Maxn];
bool tk[Maxn];

void Ask(int v)
{
	printf("? %d\n", v); fflush(stdout);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &D[v][i]);
		D[i][v] = D[v][i];
	}
}

int main()
{
	scanf("%d", &n);
	root = 1;
	Ask(root);
	int my = 0, oth = 0;
	int ex;
	for (int i = 1; i <= n; i++)
		if (D[root][i] % 2 == 0) my++;
		else { ex = i; oth++; }
	if (oth < my) { root = ex; Ask(root); }
	tk[root] = true;
	queue <int> Q;
	for (int i = 1; i <= n; i++)
		if (D[root][i] == 1) { neigh[root].push_back(i); tk[i] = true; }
		else if (D[root][i] == 2) { Q.push(i); tk[i] = true; }
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		Ask(v);
		for (int i = 1; i <= n; i++)
			if (D[v][i] == 1) { neigh[v].push_back(i); tk[i] = true; }
			else if (!tk[i] && D[v][i] == 2) { Q.push(i); tk[i] = true; }
	}
	printf("!\n");
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < neigh[i].size(); j++)
			printf("%d %d\n", i, neigh[i][j]);
	fflush(stdout);
    return 0;
}