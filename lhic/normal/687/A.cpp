#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

int n, m;
int was[120000];
int cl[120000];
vector<int> eds[120000];

vector<int> vv[2];

void dfs(int v, int c) {
	was[v] = 1;
	cl[v] = c;
	vv[c].push_back(v);
	for (int u: eds[v]) {
		if (!was[u]) {
			dfs(u, c ^ 1);
		}
		else {
			if (cl[u] == cl[v]) {
				cout << "-1\n";
				exit(0);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	fill(cl, cl + n, -1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		if (!was[i])
			dfs(i, 0);
	printf("%d\n", (int)vv[0].size());
	for (int i = 0; i < (int)vv[0].size(); ++i)
		printf("%d ", vv[0][i] + 1);
	printf("\n");
	printf("%d\n", (int)vv[1].size());
	for (int i = 0; i < (int)vv[1].size(); ++i)
		printf("%d ", vv[1][i] + 1);
	printf("\n");
	return 0;
}