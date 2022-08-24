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
int n, m, k;

vector<int> vv;
vector<int> eds[MAXN];
int was[MAXN];

void dfs1(int v) {
	was[v] = 1;
	vv.push_back(v);
	for (int u: eds[v]) {
		if (was[u])
			continue;
		dfs1(u);
		vv.push_back(v);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0);
	int len = (vv.size() + k - 1) / k;
	int now = 0;
	for (int i = 0; i < k; ++i) {
		int l = now;
		int r = min((int)vv.size(), now + len);
		now = r;
		if (l == vv.size())
			l = 0, r = 1;
		printf("%d ", r - l);
		for (int j = l; j < r; ++j)
			printf("%d ", vv[j] + 1);
		printf("\n");
	}
	return 0;
}