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

int n, m;
vector<tuple<int, int, int> > eds[MAXN];

int was[MAXN];
int ans[MAXN];
int sm[MAXN];
set<pair<int, int> > ss;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		sm[a] += c;
		sm[b] += c;
		eds[a].push_back(make_tuple(b, c, i + 1));
		eds[b].push_back(make_tuple(a, c, -i - 1));
	}
	for (int i = 0; i < n; ++i)
		sm[i] /= 2;
	for (int i = 0; i < (int)eds[0].size(); ++i) {
		int a, c, g;
		tie(a, c, g) = eds[0][i];
		sm[a] -= c;
		if (g < 0)
			ans[abs(g) - 1] = 1;
		else
			ans[abs(g) - 1] = 0;
	}
	was[0] = 1;
	for (int i = 1; i < n - 1; ++i)
		ss.insert(make_pair(sm[i], i));
	while (!ss.empty()) {
		int x = ss.begin()->second;
		was[x] = 1;
		ss.erase(ss.begin());
		for (int i = 0; i < (int)eds[x].size(); ++i) {
			int a, c, g;
			tie(a, c, g) = eds[x][i];
			if (was[a])
				continue;
			if (g < 0)
				ans[abs(g) - 1] = 1;
			else
				ans[abs(g) - 1] = 0;
			if (a != n - 1) {
				ss.erase(make_pair(sm[a], a));
				sm[a] -= c;
				ss.insert(make_pair(sm[a], a));
			}
		}
	}
	for (int i = 0; i < m; ++i)
		cout << ans[i] << "\n";
	return 0;
}