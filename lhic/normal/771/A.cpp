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

int was[160000];
vector<int> vv;
set<pair<int, int> > ss;
vector<int> eds[160000];
int n, m;


void dfs1(int v) {
	was[v] = 1;
	vv.push_back(v);
	for (int u: eds[v])
		if (!was[u])
			dfs1(u);
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
		ss.insert(make_pair(a, b));
		ss.insert(make_pair(b, a));
	}
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		vv.clear();
		dfs1(i);
		for (int j = 0; j < vv.size(); ++j)
			for (int k = j + 1; k < vv.size(); ++k) {
				if (ss.find(make_pair(vv[j], vv[k])) == ss.end()) {
					cout << "NO\n";
					return 0;
				}
			}
	}
	cout << "YES\n";
	return 0;
}