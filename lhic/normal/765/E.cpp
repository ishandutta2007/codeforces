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
const int MAXN = 210000;

int was[MAXN];
vector<int> vv;
int us;
int n;
vector<int> eds[MAXN];

int dfs1(int v) {
	was[v] = 1;
	set<int> ss;
	int fl = 0;
	int xx = 0;
	for (int u: eds[v]) {
		if (was[u])
			continue;
		int x = dfs1(u);
		if (x > 0)
			ss.insert(x);
		else
			fl = 1, xx = x;
	}
	if (ss.size() + fl >= 3) {
		cout << -1 << "\n";
		exit(0);
	}
	if (fl == 0) {
		if (ss.size() == 0)
			return 1;
		if (ss.size() == 1)
			return *ss.begin() + 1;
		if (us != -1) {
			cout << -1 << "\n";
			exit(0);
		}
		us = 1;
		vv.push_back(*ss.begin());
		vv.push_back(*ss.rbegin());
		return -1;
	}
	if (ss.empty()) {
		return xx - 1;
	}
	int x = *ss.begin();
	vv.push_back(-xx);
	vv.push_back(x);
	return -1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	us = -1;
	int x = dfs1(0);
	if (x > 0) {
		--x;
		while (x % 2 == 0)
			x /= 2;
		cout << x << "\n";
		return 0;
	}
	int now = 0;
	if (x != -1)
		now = -x - 1;
	while (vv.size() > 3) {
		if (now == 0) {
			now = vv.back();
			vv.pop_back();
			now += vv.back();
			vv.pop_back();
			continue;
		}
		if (now != vv.back()) {
			cout << -1 << "\n";
			return 0;
		}
		vv.pop_back();
		now += vv.back();
		vv.pop_back();
	}
	if (now == 0) {
		now = vv[0] + vv[1];
		while (now % 2 == 0)
			now /= 2;
		cout << now << "\n";
		return 0;
	}
	if (now != vv[0] && now != vv[1]) {
		cout << -1 << "\n";
		return 0;
	}
	now = vv[0] + vv[1];
	while (now % 2 == 0)
		now /= 2;
	cout << now << "\n";
	return 0;
}