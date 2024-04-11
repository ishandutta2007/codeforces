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

const int MAXN = 220000;

vector<int> eds[MAXN];
vector<pair<int, int> > ed;

vector<int> vv;
int n, m;
vector<pair<int, int> > ans;
int was[MAXN * 4];

int p[MAXN];


void add_edge(int a, int b) {
	ed.push_back({a, b});
	eds[a].push_back(ed.size() - 1);
	eds[b].push_back(ed.size() - 1);
}

void dfs(int v) {
	while (p[v] != (int)eds[v].size()) {
		int xx = eds[v][p[v]];
		if (was[xx]) {
			++p[v];
			continue;
		}
		was[xx] = 1;
		++p[v];
		dfs(ed[xx].first ^ ed[xx].second ^ v);
		ans.push_back({v, ed[xx].first ^ ed[xx].second ^ v});
	}
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		add_edge(a, b);
	}
	for (int i = 0; i < n; ++i) {
		if (eds[i].size() % 2 == 1) 
			vv.push_back(i);
	}
	for (int i = 0; i < (int)vv.size(); i += 2)
		add_edge(vv[i], vv[i + 1]);
	if (ed.size() % 2 == 1)
		add_edge(0, 0);
	dfs(0);
	cout << ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); ++i) {
		if (i % 2 == 0) {
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		}
		else {
			printf("%d %d\n", ans[i].second + 1, ans[i].first + 1);
		}
	}
	return 0;
}