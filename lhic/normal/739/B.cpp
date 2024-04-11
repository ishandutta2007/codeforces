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

struct st {
	multiset<ll> *ss;
	ll d;
};
const int MAXN = 210000;

int ans[MAXN];
int n;
vector<pair<int, ll> > eds[MAXN];
ll a[MAXN];

st dfs1(int v) {
	st now;
	now.ss = new multiset<ll>();
	now.d = 0;
	for (auto e: eds[v]) {
		int u = e.first;
		st tmp = dfs1(u);
		tmp.d -= e.second;
		while (!(tmp.ss->empty()) && *(tmp.ss->begin()) + tmp.d < 0)
			tmp.ss->erase(tmp.ss->begin());
		if (tmp.ss->size() > now.ss->size())
			swap(tmp, now);
		for (ll x: *(tmp.ss))
			now.ss->insert(x + tmp.d - now.d);
	}
	ans[v] = now.ss->size();
	now.ss->insert(a[v] - now.d);
	return now;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	for (int i = 0; i < n - 1; ++i) {
		int p;
		ll w;
		scanf("%d%lld", &p, &w);
		--p;
		eds[p].push_back(make_pair(i + 1, w));
	}
	dfs1(0);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}