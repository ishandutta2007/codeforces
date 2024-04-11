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
int c[MAXN];
int fl[MAXN];
vector<int> eds[MAXN];

void dfs1(int v) {
	was[v] = 1;
	for (int u: eds[v]) {
		if (was[u])
			continue;
		dfs1(u);
		if (c[u] != c[v] || fl[u])
			fl[v] = 1;
	}
}

void dfs2(int v, int up = -1) {
	int fll = 0;
	if (up == -2)
		return;
	was[v] = 1;
	for (int u: eds[v]) {
		if (!was[u] && fl[u])
			fll = 1;
	}
	if (!fll) {
		cout << "YES\n" << v + 1 << "\n";
		exit(0);
	}
	if (up == -2)
		return;
	int cnt = 0;
	for (int u: eds[v]) {
		if (!was[u] && fl[u])
			++cnt;
	}
	if (cnt >= 2)
		return;
	for (int u: eds[v]) {
		if (was[u])
			continue;
		if (!fl[u]) {
			if (up == -1) {
				up = c[u];
			}
			else if (up != c[u]) {
				up = -2;
			}
		}
	}
	if (up == -1)
		up = c[v];
	else if (up != c[v])
		up = -2;
	for (int u: eds[v]) {
		if (!was[u] && fl[u])
			dfs2(u, up);
	}
}


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", c + i);
	dfs1(0);
	memset(was, 0, sizeof(was));
	dfs2(0);
	cout << "NO\n";
	return 0;
}