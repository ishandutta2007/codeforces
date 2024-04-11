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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 210000;

int was[MAXN];
int n, k;
vector<int> eds[MAXN];
int cl[MAXN];

void dfs1(int v, int pc) {
	was[v] = 1;
	int now = 1;
	for (int u: eds[v]) {
		if (was[u])
			continue;
		while (now == cl[v] || now == pc)
			++now;
		cl[u] = now;
		++now;
		dfs1(u, cl[v]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	int k = 0;
	for (int i = 0; i < n; ++i)
		k = max(k, 1 + (int)eds[i].size());
	cl[0] = 1;
	dfs1(0, -1);
	printf("%d\n", k);
	for (int i = 0; i < n; ++i)
		printf("%d ", cl[i]);
	printf("\n");
	return 0;
}