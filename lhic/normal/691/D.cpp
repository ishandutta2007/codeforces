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

vector<int> vv;
vector<int> vv2;

int n, m;
int a[1200000];
int was[1200000];

vector<int> eds[1200000];

void dfs(int v) {
	vv.push_back(v);
	vv2.push_back(a[v]);
	was[v] = 1;
	for (int u: eds[v])
		if (!was[u])
			dfs(u);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		--a[i];
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		eds[x].push_back(y);
		eds[y].push_back(x);
	}
	for (int i = 0; i < n; ++i) {
		if (!was[i]) {
			vv.clear();
			vv2.clear();
			dfs(i);
			sort(vv.begin(), vv.end());
			sort(vv2.rbegin(), vv2.rend());
			for (int i = 0; i < (int)vv.size(); ++i)
				a[vv[i]] = vv2[i];
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i] + 1);
	printf("\n");
	return 0;
}