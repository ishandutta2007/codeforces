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

const int MAXN = 200000; 

int n, m;

vector<pair<int, int> > eds[MAXN];
vector<tuple<int, int, int> > ed;

vector<int> v[2];
int was[MAXN];
int fl;

void dfs(int v, int cl) {
	was[v] = cl;
	::v[cl - 1].push_back(v);
	for (pair<int, int> x: eds[v]) {
		int u = x.first;
		int k = x.second;
		if (was[u]) {
			if ((k == 0 && was[v] != was[u]) || (k == 1 && was[v] == was[u])) {
				fl = 1;
				return;
			}
		}
		else {
			if (k == 0) {
				dfs(u, cl);
			}
			else {
				dfs(u, 3 - cl);
			}
		}
	}
}

vector<int> check(int k) {
	for (int i = 0; i < n; ++i)
		eds[i].clear();
	for (int i = 0; i < (int)ed.size(); ++i) {
		int a, b, c;
		tie(a, b, c) = ed[i];
		if (c == k)
			eds[a].push_back(make_pair(b, 0)), eds[b].push_back(make_pair(a, 0));
		else
			eds[a].push_back(make_pair(b, 1)), eds[b].push_back(make_pair(a, 1));
	}
	fl = 0;
	memset(was, 0, sizeof(was));
	vector<int> vv;
	for (int i = 0; i < n; ++i) {
		if (!was[i]) {
			v[0].clear();
			v[1].clear();
			dfs(i, 1);
			if (fl) {
				while ((int)vv.size() < n + 1)
					vv.push_back(0);
				return vv;
			}
			if (v[0].size() > v[1].size())
				swap(v[0], v[1]);
			for (int j = 0; j < (int)v[0].size(); ++j)
				vv.push_back(v[0][j]);
		}
	}
	return vv;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		char c;
		scanf("%d%d %c", &a, &b, &c);
		--a;
		--b;
		if (c == 'R') {
			ed.push_back(make_tuple(a, b, 0));
		}
		else {
			ed.push_back(make_tuple(a, b, 1));
		}
	}
	vector<int> vv = check(0);
	vector<int> vv2 = check(1);
	if (vv2.size() < vv.size())
		vv = vv2;
	if ((int)vv.size() > n)
		printf("-1\n");
	else {
		printf("%d\n", (int)vv.size());
		for (int i: vv)
			printf("%d ", i + 1);
		printf("\n");
	}
	return 0;
}