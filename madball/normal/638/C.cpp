#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
const int lim = 200001;
vector<pair<int, int> > graph[lim];
int color[lim];
bool been[lim];
int maxcol = 0;
vector<int> colored[lim];

void dfs(int v, int col) {
	int curcol = 0;
	been[v] = true;
	for (int i = 0; i < graph[v].size(); ++i)
		if (!been[graph[v][i].first]) {
			if (curcol == col)
				++curcol;
			color[graph[v][i].second] = curcol;
			colored[curcol].push_back(graph[v][i].second);
			++curcol;
			if (curcol > maxcol)
				maxcol = curcol;
			dfs(graph[v][i].first, color[graph[v][i].second]);
		}
}

int main() {
	int n, i, j, a, b;
	scanf("%d", &n);
	for (i = 0; i < n - 1; ++i) {
		scanf("%d %d", &a, &b);
		--a;
		--b;
		graph[a].push_back(make_pair(b, i));
		graph[b].push_back(make_pair(a, i));
	}
	dfs(0, -1);
	printf("%d\n", maxcol);
	for (i = 0; i < maxcol; ++i)  {
		if (colored[i].size()) {
			printf("%d", colored[i].size());
			for (j = 0; j < colored[i].size(); ++j)
				printf(" %d", colored[i][j] + 1);
			printf("\n");
		}
	}
	return 0;
}