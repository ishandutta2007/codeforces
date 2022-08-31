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
const int MAXN = 120000;
int was[MAXN];
int cl[MAXN];
int r[MAXN];
int n, m;
vector<pair<int, int> > eds[MAXN];
vector<int> gg[MAXN];

int dfs1(int v, int c) {
	was[v] = 1;
	cl[v] = c;
	for (auto e: eds[v]) {
		int u = e.first;
		if (!was[u]) {
			if (!dfs1(u, c ^ e.second))
				return 0;
		}
		else {
			if (cl[u] != (cl[v] ^ e.second)) {
				return 0;
			}
		}
	}
	return 1;
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", r + i);
	for (int i = 0; i < m; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int a;
			scanf("%d", &a);
			--a;
			gg[a].push_back(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		eds[gg[i][0]].push_back(make_pair(gg[i][1], 1 - r[i]));
		eds[gg[i][1]].push_back(make_pair(gg[i][0], 1 - r[i]));
	}
	for (int i = 0; i < m; ++i) {
		if (!was[i] && !dfs1(i, 0)) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}