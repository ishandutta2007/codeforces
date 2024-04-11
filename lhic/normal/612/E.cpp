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
typedef double ld;

using namespace std;

const int MAXN = 1200000;

vector<int> lst[MAXN];
int was[MAXN];
int ans[MAXN];
vector<int> vv;
vector<int> vv2;
int p[MAXN];
int n;

void get(int v) {
	was[v] = 1;
	vv.push_back(v);
	if (!was[p[v]])
		get(p[v]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i), --p[i];
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		vv.clear();
		get(i);
		if (lst[vv.size()].empty()) {
			lst[vv.size()] = vv;
		}
		else {
			vv2 = lst[vv.size()];
			lst[vv.size()].clear();
			for (int j = 0; j < (int)vv.size() - 1; ++j)
				ans[vv[j]] = vv2[j], ans[vv2[j]] = vv[j + 1];
			ans[vv.back()] = vv2.back();
			ans[vv2.back()] = vv.front();

		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!lst[i].empty()) {
			if (i % 2 == 0) {
				printf("-1\n");
				return 0;
			}
			int k = i / 2 + 1;
			for (int j = 0; j < (int)lst[i].size(); ++j) {
				ans[lst[i][j]] = lst[i][(j + k) % i];
			}
		}
	}

	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i] + 1);
	printf("\n");

	return 0;
}