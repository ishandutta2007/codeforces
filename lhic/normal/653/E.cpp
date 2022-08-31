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
const int MAXN = 310000;

int p[MAXN];
int sz[MAXN];
vector<int> bl[MAXN];
int was[MAXN];
int n, m, k;
int mx;

int get(int v) {
	if (p[v] == v)
		return v;
	return p[v] = get(p[v]);
}

void un(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b)
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
}

void dfs1(int v) {
	was[v] = 1;
	for (int i = 1; i < n; ++i) {
		if (i == v)
			continue;
		if (binary_search(bl[v].begin(), bl[v].end(), i))
			continue;
		un(v, i);
		if (!was[i])
			dfs1(i);
	}
}



int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		bl[a].push_back(b);
		bl[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		sort(bl[i].begin(), bl[i].end());
	for (int i = 0; i < n; ++i)
		sz[i] = 1, p[i] = i;
	p[n] = n;
	mx = 2 * m / n + 3;
	if ((int)bl[0].size() + k > n - 1) {
		cout << "impossible\n";
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		if (n - 1 - (int)bl[i].size() > mx) {
			was[i] = 1;
			un(i, n);
			continue;
		}
	}
	for (int i = 1; i < n; ++i) {
		if (was[i])
			continue;
		dfs1(i);
	}
	set<int> ss;
	for (int i = 1; i < n; ++i)
		ss.insert(get(i));
	if ((int)ss.size() > k) {
		cout << "impossible\n";
		return 0;
	}
	dfs1(0);
	int v = get(0);
	if (sz[v] < n) {
		cout << "impossible\n";
	}
	else {
		cout << "possible\n";
	}
	return 0;
}