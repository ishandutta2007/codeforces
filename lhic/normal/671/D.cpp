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


struct node {
	int d1;
	ll d2;
	set<pair<int, ll> > *ss;
	node() {
		d1 = d2 = 0;
		ss = new set<pair<int, ll> >();
	}
	void add(pair<int, ll> u) {
		u.first -= d1;
		u.second -= d2;
		auto it = ss->lower_bound(make_pair(u.first, -d2));
		if (it != ss->end() && it->second <= u.second)
			return;
		while (it != ss->end() && it->first == u.first) {
			auto it2 = it;
			it2++;
			ss->erase(it);
			it = it2;
		}
		it = ss->insert(u).first;
		if (it != ss->begin()) {
			--it;
			while (it->second >= u.second) {
				if (it == ss->begin()) {
					ss->erase(it);
					break;
				}
				else {
					auto it2 = it;
					--it2;
					ss->erase(it);
					it = it2;
				}
			}
		}
	}
};


node merge(node a, node b) {
	if (a.ss->size() < b.ss->size())
		swap(a, b);
	if (b.ss->size() == 0)
		return a;
	ll ad2 = b.ss->begin()->second + b.d2;
	ll bd2 = a.ss->begin()->second + a.d2;
	a.d2 += ad2;
	b.d2 += bd2;
	for (pair<int, ll> u: *b.ss)
		a.add(make_pair(u.first + b.d1, u.second + b.d2));
	return a;
}

void fin() {
	cout << -1 << "\n";
	exit(0);
}

const int MAXN = 310000;

int was[MAXN];
vector<int> eds[MAXN];

vector<pair<int, ll> > go[MAXN];
int h[MAXN];
int n, m;


node dfs(int v) {
	was[v] = 1;
	node xx;
	for (int u: eds[v]) {
		if (was[u])
			continue;
		node go = dfs(u);
		--go.d1;
		while (go.ss->size() && go.ss->begin()->first + go.d1 < 0)
			go.ss->erase(go.ss->begin());
		if (go.ss->empty())
			fin();
		xx = merge(xx, go);
	}
	ll mn = 0;
	if (!xx.ss->empty())
		mn = xx.ss->begin()->second + xx.d2;
	for (int i = 0; i < (int)go[v].size(); ++i)
		xx.add(make_pair(go[v][i].first, go[v][i].second + mn));
	return xx;
}


void dfsh(int v) {
	was[v] = 1;
	for (int u: eds[v]) {
		if (!was[u]) {
			h[u] = h[v] + 1;
			dfsh(u);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	if (n == 1) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	h[0] = 0;
	dfsh(0);
	memset(was, 0, sizeof(was));
	for (int i = 0; i < m; ++i) {
		int u, v;
		ll c;
		scanf("%d%d%lld", &u, &v, &c);
		--v;
		--u;
		go[u].push_back(make_pair(h[u] - h[v], c));
	}
	node ans = dfs(0);
	cout << ans.ss->begin()->second + ans.d2 << "\n";
	return 0;
}