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
const int MAXN = 1000010;
const ll MOD = 1e9 + 7;

set<pair<int, int> > ss;

int ps[MAXN * 4];
ll sp[MAXN * 4];
ll rmq[MAXN * 4];
int n, m;
vector<pair<int, int> > op[MAXN];
vector<pair<int, int> > cl[MAXN];

void push(int v, int tl, int tr) {
	if (!ps[v])
		return;
	ps[v] = 0;
	ps[v * 2 + 1] = 1;
	ps[v * 2 + 2] = 1;
	sp[v * 2 + 1] = sp[v];
	sp[v * 2 + 2] = sp[v];
	int m = (tl + tr) >> 1;
	rmq[v * 2 + 1] = ((m - tl) * sp[v]) % MOD;
	rmq[v * 2 + 2] = ((tr - m) * sp[v]) % MOD;
}

void st(int v, int tl, int tr, int l, int r, ll x) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		ps[v] = 1;
		sp[v] = x;
		rmq[v] = (x * (tr - tl)) % MOD;
		return;
	}
	push(v, tl, tr);
	int m = (tl + tr) >> 1;
	st(v * 2 + 1, tl, m, l, r, x);
	st(v * 2 + 2, m, tr, l, r, x);
	rmq[v] = (rmq[v * 2 + 1] + rmq[v * 2 + 2]) % MOD;
}

ll get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r) {
		return rmq[v];
	}
	push(v, tl, tr);
	int m = (tl + tr) >> 1;
	return (get(v * 2 + 1, tl, m, l, r) + get(v * 2 + 2, m, tr, l, r)) % MOD;
}



int main() {
	int k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		--x1, --y1;
		op[x1].push_back(make_pair(y1, y2));
		cl[x2].push_back(make_pair(y1, y2));
	}
	st(0, 0, m, 0, 1, 1);
	for (auto j: op[0])
		ss.insert(j);
	for (int i = 1; i < n; ++i) {
		sort(op[i].begin(), op[i].end());
		reverse(op[i].begin(), op[i].end());
		for (auto j: op[i]) {
			auto it = ss.lower_bound(make_pair(j.second + 1, 0));
			int lb = 0;
			if (it != ss.begin()) {
				--it;
				lb = it->second;
			}
			ll cc = get(0, 0, m, lb, j.second + 1);
			st(0, 0, m, j.second, j.second + 1, cc);
		}
		for (auto j: cl[i])
			ss.erase(j);
		for (auto j: op[i]) {
			st(0, 0, m, j.first, j.second, 0);
			ss.insert(j);
		}
	}
	for (auto j: ss)
		st(0, 0, m, 0, j.second, 0);
	cout << get(0, 0, m, 0, m) << "\n";
	return 0;
}