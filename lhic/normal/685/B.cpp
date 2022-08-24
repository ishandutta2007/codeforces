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

int n, q;

vector<int> eds[310000];
int sz[310000];
int ans[310000];

set<pair<int, int> > *dfs(int v) {
	sz[v] = 1;
	set<pair<int, int> > *ss = new set<pair<int, int>>();
	for (int u: eds[v]) {
		auto tmp = dfs(u);
		sz[v] += sz[u];
		if (tmp->size() > ss->size())
			swap(tmp, ss);
		for (auto i: *tmp)
			ss->insert(i);
	}
	ss->insert(make_pair(sz[v], v));
	while (!ss->empty() && ss->begin()->first * 2 < sz[v])
		ss->erase(ss->begin());
	ans[v] = ss->begin()->second;
	return ss;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i) {
		int a;
		scanf("%d", &a);
		--a;
		eds[a].push_back(i);
	}

	dfs(0);
	for (int i = 0; i < q; ++i) {
		int v;
		scanf("%d", &v);
		--v;
		printf("%d\n", ans[v] + 1);
	}

	return 0;
}