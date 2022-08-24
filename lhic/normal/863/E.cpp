#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int INF = 1e9;
int n;
int tl[220000];
int tr[220000];
vector<int> vv;
int rmq[420000 * 4];
int dd[420000 * 4];

void add(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		++dd[v];
		++rmq[v];
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r);
	add(v * 2 + 2, m, tr, l, r);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]) + dd[v];
}

int get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return INF;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r)) + dd[v];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", tl + i, tr + i);
		++tr[i];
		vv.push_back(tl[i]);
		vv.push_back(tr[i]);
	}
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	for (int i = 0; i < n; ++i) {
		tl[i] = lower_bound(vv.begin(), vv.end(), tl[i]) - vv.begin();
		tr[i] = lower_bound(vv.begin(), vv.end(), tr[i]) - vv.begin();
		add(0, 0, vv.size(), tl[i], tr[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (get(0, 0, vv.size(), tl[i], tr[i]) != 1) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
	return 0;
}