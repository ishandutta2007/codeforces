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
const int MAXN = 300000; 

int sz[MAXN];

int was[MAXN];

vector<int> eds[MAXN];
int n;

void dfssz(int v) {
	int fl = 0;
	sz[v] = 0;
	was[v] = 1;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		if (!was[u]) {
			dfssz(u);
			fl = 1;
			sz[v] += sz[u];
		}
	}
	if (!fl)
		++sz[v];
}

int dfs1(int v, int h) {
	was[v] = 1;
	if (h == 0) {
		int ans = 0;
		for (int i = 0; i < (int)eds[v].size(); ++i) {
			int u = eds[v][i];
			if (!was[u]) {
				int xxx = dfs1(u, h ^ 1);
				ans = max(ans, xxx + sz[v] - sz[u]);
			}
		}
	//	cout << v << " " << h << " " << ans << "\n";
		return ans;
	}
	else {
		int sum = 0;
		for (int i = 0; i < (int)eds[v].size(); ++i) {
			int u = eds[v][i];
			if (!was[u]) {
				int xxx = dfs1(u, h ^ 1);
				sum += sz[u] - xxx;
			}
		}
		if (sz[v] == 1) {
			sum = sz[v];
		}
	//	cout << v << " " << h << " " << sz[v] - sum << "\n";
		return sz[v] - sum;
	}
}




int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		eds[u].push_back(v);
		eds[v].push_back(u);
	}
	dfssz(0);
	memset(was, 0, sizeof(was));
	cout << dfs1(0, 0) + 1 << " ";
	memset(was, 0, sizeof(was));
	cout << sz[0] - dfs1(0, 1) << " ";
	return 0;

}