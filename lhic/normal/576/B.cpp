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

const int MAXN = 120000;

int n;
int was[MAXN];
int p[MAXN];
vector<int> vv[MAXN];

void dfs(int v, int c) {
	vv[c].push_back(v);
	was[v] = 1;
	if (!was[p[v]])
		dfs(p[v], c);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &p[i]), --p[i];
	int now = 0;
	for (int i = 0; i < n; ++i)
		if (!was[i]) {
			dfs(i, now);
			++now;
		}
	for (int i = 0; i < now; ++i) {
		if (vv[i].size() == 1) {
			printf("YES\n");
			for (int j = 0; j < n; ++j) {
				if (j != vv[i][0])
					printf("%d %d\n", vv[i][0] + 1, j + 1);
			}
			return 0;
		}
	}

	for (int i = 0; i < now; ++i) {
		if (vv[i].size() % 2 == 1) {
			printf("NO\n");
			return 0;
		}
	}

	for (int i = 0; i < now; ++i) {
		if (vv[i].size() == 2) {
			printf("YES\n");
			printf("%d %d\n", vv[i][0] + 1, vv[i][1] + 1);
			for (int j = 0; j < now; ++j) {
				if (i == j)
					continue;
				for (int j1 = 0; j1 < (int)vv[j].size(); ++j1)
					if (j1 % 2 == 0)
						printf("%d %d\n", vv[i][0] + 1, vv[j][j1] + 1);
					else
						printf("%d %d\n", vv[i][1] + 1, vv[j][j1] + 1);
			}
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}