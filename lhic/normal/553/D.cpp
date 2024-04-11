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

const int MAXN = 120000;

int en[MAXN];
int go[MAXN];

int k;

vector<int> eds[MAXN];
int n, m;
int cnt[MAXN];

struct rat {
	ll x, y;
	bool operator<(rat a) const {
		return x * a.y > y * a.x;
	}
};

set<pair<rat, int> > ss;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		int a;
		scanf("%d", &a);
		--a;
		en[a] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		cnt[i] = 0;
	for (int i = 0; i < n; ++i) {
		if (en[i]) {
			for (int j = 0; j < (int)eds[i].size(); ++j) {
				int u = eds[i][j];
				++cnt[u];
			}
		}
	}
	ss.clear();
	for (int i = 0; i < n; ++i) {
		if (!en[i]) {
			rat x;
			x.x = cnt[i];
			x.y = eds[i].size();
			ss.insert(make_pair(x, i));
		}
	}

	for (int i = 0; i < n; ++i)
		go[i] = en[i];
	int it = 0;
	rat ans = ss.begin()->first;
	int cc = 0;
	while (!ss.empty()) {
		if (ans < ss.begin()->first) {
			it = cc;
			ans = ss.begin()->first;
		}
		++cc;
		int x = ss.begin()->second;
		go[x] = 1;
		ss.erase(ss.begin());
		for (int i = 0; i < (int)eds[x].size(); ++i) {
			int u = eds[x][i];
			if (go[u])
				continue;
			rat xx;
			xx.x = cnt[u];
			xx.y = eds[u].size();
			ss.erase(make_pair(xx, u));
			++cnt[u];
			++xx.x;
			ss.insert(make_pair(xx, u));
		}
	}


	for (int i = 0; i < n; ++i)
		cnt[i] = 0;
	for (int i = 0; i < n; ++i) {
		if (en[i]) {
			for (int j = 0; j < (int)eds[i].size(); ++j) {
				int u = eds[i][j];
				++cnt[u];
			}
		}
	}
	ss.clear();
	for (int i = 0; i < n; ++i) {
		if (!en[i]) {
			rat x;
			x.x = cnt[i];
			x.y = eds[i].size();
			ss.insert(make_pair(x, i));
		}
	}

	for (int i = 0; i < n; ++i)
		go[i] = en[i];
	cc = 0;
	for (int i = 0; i < it; ++i) {
		int x = ss.begin()->second;
		go[x] = 1;
		ss.erase(ss.begin());
		for (int i = 0; i < (int)eds[x].size(); ++i) {
			int u = eds[x][i];
			if (go[u])
				continue;
			rat xx;
			xx.x = cnt[u];
			xx.y = eds[u].size();
			ss.erase(make_pair(xx, u));
			++cnt[u];
			++xx.x;
			ss.insert(make_pair(xx, u));
		}
	}


	printf("%d\n", (int)ss.size());
	for (auto xx: ss) {
		printf("%d ", xx.second + 1);
	}


	return 0;
}