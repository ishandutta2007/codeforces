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
const ll MOD = 1000000007;

int p[MAXN];
int rnk[MAXN];
int cl[MAXN];
int was[MAXN];
vector<int> eds[MAXN];
int n, m;
vector<pair<int, int> > ed;
ll ans = 1;

int get(int a) {
	if (p[a] == a)
		return a;
	return p[a] = get(p[a]);
}

void un(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b)
		return;
	if (rnk[a] > rnk[b]) {
		p[b] = a;
	}
	else {
		p[a] = b;
		if (rnk[a] == rnk[b])
			++rnk[b];
	}
}

void dfs(int v, int c) {
	was[v] = 1;
	cl[v] = c;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		if (!was[u]) {
			dfs(u, 1 - c);
		}
		else {
			if (cl[u] == cl[v])
				ans = 0;
		}
	}
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		rnk[i] = 0, p[i] = i;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		if (c == 1)
			un(a, b);
		else
			ed.push_back(make_pair(a, b));
	}
	for (int i = 0; i < n; ++i)
		p[i] = get(i);
	ans = 1;
	for (int i = 0; i < (int)ed.size(); ++i) {
		int a, b;
		tie(a, b) = ed[i];
		a = p[a];
		b = p[b];
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	int cc = 0;
	for (int i = 0; i < n; ++i) {
		if (p[i] == i) {
			if (!was[i]) {
				dfs(i, 0);
				++cc;
			}
		}
	}
	--cc;
	for (int i = 0; i < cc; ++i)
		ans = (ans * 2) % MOD;
	cout << ans << "\n";
	return 0;
}