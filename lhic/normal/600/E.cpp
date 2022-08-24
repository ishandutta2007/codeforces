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
typedef double ld;

using namespace std;

struct st {
	map<int, int> *mm;
	ll sum;
	ll mx;
	st() {
		mm = new map<int, int>();
		sum = 0;
		mx = 0;
	}
	void add(int x, int y) {
		if (y == 0)
			return;
		(*mm)[x] += y;
		int a = (*mm)[x];
		if (a > mx) {
			mx = a;
			sum = x;
		}
		else if (a == mx) {
			sum += x;
		}
	}
};

const int MAXN = 200000;


int was[MAXN];
ll ans[MAXN];
vector<int> eds[MAXN];

int n;
int c[MAXN];

st dfs(int v) {
	was[v] = 1;
	st now;
	now.add(c[v], 1);
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		if (was[u])
			continue;
		st xx = dfs(u);
		if (xx.mm->size() > now.mm->size())
			swap(xx, now);
		for (auto it: (*xx.mm)) {
			now.add(it.first, it.second);
		}
	}
	ans[v] = now.sum;
	return now;
}





int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", c + i);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs(0);
	for (int i = 0; i < n; ++i)
		printf("%lld ", ans[i]);
	return 0;
}