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

const ll MOD = 1000000007;
const int MAXN = 210000;

int n;
vector<pair<ll, ll> > vv;

int tin[MAXN];
int tout[MAXN];
vector<int> eds[MAXN];
int q;
pair<ll, ll> rmq[MAXN * 2 * 4];
int cnt;
int qq[MAXN];
int cc[MAXN];
int t[MAXN];
int c[MAXN];


ll bck(ll a) {
	ll ans = 1;
	ll b = MOD - 2;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		--b, ans = (ans * a) % MOD;
	}
	return ans;
}


void dfs(int v) {
	tin[v] = vv.size();
	vv.push_back(make_pair(1, 0));
	for (int i = 0; i < (int)eds[v].size(); ++i)
		dfs(eds[v][i]);
	tout[v] = vv.size();
	vv.push_back(make_pair(1, 0));
}

pair<ll, ll> merge(pair<ll, ll> a, pair<ll, ll> b) {
	pair<ll, ll> ans;
	ans.first = (a.first * b.first) % MOD;
	ans.second = (a.second + b.second * a.first) % MOD;
	return ans;
}

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v] = vv[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void upd(int v, int tl, int tr, int x, pair<ll, ll> y) {
	if (tl + 1 == tr) {
		rmq[v] = y;
		rmq[v].second = (rmq[v].second * rmq[v].first) % MOD;
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x, y);
	else
		upd(v * 2 + 2, m, tr, x, y);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

pair<ll, ll> get(int v, int tl, int tr, int l, int r) {
	if (tr <= l || r <= tl)
		return make_pair(1, 0);
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return merge(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
}



int main() {
	scanf("%d%d", c + 0, &q);
	cnt = 1;
	for (int i = 0; i < q; ++i) {
		scanf("%d", t + i);
		if (t[i] == 1) {
			int p;
			scanf("%d%d", &p, c + cnt);
			--p;
			eds[p].push_back(cnt);
			qq[i] = p;
			++cnt;
		}
		else {
			scanf("%d", qq + i);
			--qq[i];
		}
	}
	n = cnt;
	for (int i = 0; i < n; ++i)
		cc[i] = 1;
	cnt = 1;
	dfs(0);
	build(0, 0, vv.size());
	upd(0, 0, vv.size(), tin[0], make_pair(1, c[0]));
	for (int i = 0; i < q; ++i) {
		if (t[i] == 1) {
			++cc[qq[i]];
			upd(0, 0, vv.size(), tin[qq[i]], make_pair(cc[qq[i]], c[qq[i]]));
			upd(0, 0, vv.size(), tout[qq[i]], make_pair(bck(cc[qq[i]]), 0));
			upd(0, 0, vv.size(), tin[cnt], make_pair(1, c[cnt]));
			++cnt;
		}
		else {
			auto ans = get(0, 0, vv.size(), tin[qq[i]], tout[qq[i]] + 1);
			printf("%d\n", (int)ans.second);
		}
	}
	return 0;
}