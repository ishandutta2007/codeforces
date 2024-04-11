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

const int MAXN = 210000;

int n;
int a[MAXN];
vector<int> go[MAXN];
vector<pair<int, int> > gg[MAXN];
ll sm[MAXN * 4], mn[MAXN * 4], mx[MAXN * 4];
ll pp[MAXN * 4];

void push(int v, int tl, int tr) {
	if (pp[v]) {
		int m = (tl + tr) >> 1;
		pp[v * 2 + 1] = pp[v * 2 + 2] = pp[v];
		mn[v * 2 + 1] = mn[v * 2 + 2] = mn[v];
		mx[v * 2 + 1] = mx[v * 2 + 2] = mx[v];
		sm[v * 2 + 1] = pp[v] * (ll)(m - tl);
		sm[v * 2 + 2] = pp[v] * (ll)(tr - m);
		pp[v] = 0;
	}
};

void upd(int v, int tl, int tr, int l, int r, int d) {
	if (mn[v] >= d || r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		if (mx[v] <= d) {
			pp[v] = d;
			mx[v] = d;
			mn[v] = d;
			sm[v] = (tr - tl) * (ll)d;
			return;
		}
	}
	int m = (tl + tr) >> 1;
	push(v, tl, tr);
	upd(v * 2 + 1, tl, m, l, r, d);
	upd(v * 2 + 2, m, tr, l, r, d);
	mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
	mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
	sm[v] = sm[v * 2 + 1] + sm[v * 2 + 2];
}

ll get(int v, int tl, int tr, int l, int r) {
	if (tr <= l || r <= tl)
		return 0;
	if (l <= tl && tr <= r)
		return sm[v];
	push(v, tl, tr);
	int m = (tl + tr) >> 1;
	return get(v * 2 + 1, tl, m, l, r) + get(v * 2 + 2, m, tr, l, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j * j <= a[i]; ++j) {
			if (a[i] % j == 0) {
				go[j].push_back(i);
				if (j * j != a[i])
					go[a[i] / j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= 200000; ++i) {
		if (go[i].size() >= 2) {
			int l, r;
			l = go[i][1] + 1;
			r = n;
			gg[l].push_back(make_pair(r, i));
			l = 0;
			r = go[i][go[i].size() - 2];
			gg[l].push_back(make_pair(r, i));
			l = go[i][0] + 1;
			r = go[i].back();
			gg[l].push_back(make_pair(r, i));
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (auto j: gg[i])
			upd(0, 0, n + 1, 0, j.first + 1, j.second);
		ans += get(0, 0, n + 1, i + 1, n + 1);
	}
	cout << ans << "\n";
	return 0;
}