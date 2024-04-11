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

int n, m, q;
vector<pair<int, int> > ed;
vector<tuple<int, int, int, int> > gg[MAXN];
int ans[MAXN];
int go[1200][1200];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			go[i][j] = m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		ed.push_back(make_pair(a, b));
	}
	for (int i = 0; i < q; ++i) {
		int l, r, a, b;
		scanf("%d%d%d%d", &l, &r, &a, &b);
		--l, --r, --a, --b;
		gg[l].push_back(make_tuple(r, a, b, i));
	}
	for (int i = m - 1; i >= 0; --i) {
		int a = ed[i].first;
		int b = ed[i].second;
		go[a][b] = i;
		go[b][a] = i;
		for (int j = 0; j < n; ++j)
			go[a][j] = min(go[a][j], go[b][j]), go[b][j] = min(go[b][j], go[a][j]);
		for (int j = 0; j < (int)gg[i].size(); ++j) {
			int s, t, r, k;
			tie(r, s, t, k) = gg[i][j];
			if (go[s][t] <= r)
				ans[k] = 1;
			else
				ans[k] = 0;
		}
	}
	for (int i = 0; i < q; ++i) {
		if (ans[i])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}