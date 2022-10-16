/*input
4
6
1 2 1
3 4 1
2 3 2
1 3 2
2 4 1
1 4 2
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 1800000
#pragma GCC optimize("O3")
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x

struct data {
	int l, r, val;
	data(int _l, int _r, int _val): l(_l), r(_r), val(_val) {};
};

int n, q;
vector<data > query;
vector<int> allVal;
int a[N];
int f[4 * N]; int lazy[4 * N];
int sum[N];

#define getRange(l, r) (sum[r] - sum[l - 1])

void init(int k, int l, int r) {
	if (l == r) {
		f[k] = getRange(l, r);
		return;
	}
	int mid = (l + r) / 2;
	init(k * 2, l, mid); init(k * 2 + 1, mid + 1, r);
	f[k] = f[k * 2] + f[k * 2 + 1];
}

void dolazy(int k, int l, int r) {
	if (lazy[k] == 0) return;
	if (lazy[k] == -1) {
		f[k] = 0;
		if (l != r)
			lazy[k * 2] = lazy[k * 2 + 1] = -1;
	}
	else {
		f[k] = getRange(l, r);
		if (l != r)
			lazy[k * 2] = lazy[k * 2 + 1] = 1;
	}
	lazy[k] = 0;
}

void update(int k, int l, int r, int L, int R, int val) {
	dolazy(k, l, r);
	if (r < L || R < l) return;
	if (L <= l && r <= R) {
		if (val == -1) {//
			f[k] = 0;
			if (l != r)
				lazy[k * 2] = lazy[k * 2 + 1] = -1;
		}
		else {
			f[k] = getRange(l, r);
			if (l != r)
				lazy[k * 2] = lazy[k * 2 + 1] = 1;
		}
		return;
	}
	int mid = (l + r) / 2;
	update(k * 2, l, mid, L, R, val); update(k * 2 + 1, mid + 1, r, L, R, val);
	f[k] = f[k * 2] + f[k * 2 + 1];
}

int get(int k, int l, int r, int L, int R) {
	dolazy(k, l, r);
	if (r < L || R < l) return 0;
	if (L <= l && r <= R)
		return f[k];
	int mid = (l + r) / 2;
	return get(k * 2, l, mid, L, R) + get(k * 2 + 1, mid + 1, r, L, R);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	allVal.reserve(N); query.reserve(300005);
	for (int i = 0; i < q; i++) {
		int u, v, val; cin >> u >> v >> val;
		if (val == 1) val = -1;
		else val = 1;
		query.push_back(data(u, v, val));
		allVal.push_back(u); allVal.push_back(v);
		allVal.push_back(max(1, u - 1)); allVal.push_back(max(1, v - 1));
		allVal.push_back(min(n, u + 1)); allVal.push_back(min(n, v + 1));
	}
	allVal.push_back(1); allVal.push_back(n);
	allVal.push_back(-1e9);
	sort(allVal.begin(), allVal.end());  allVal.resize(distance(allVal.begin(), unique(allVal.begin(), allVal.end())));
	for (int i = 0; i < q; i++) {
		query[i].l = lower_bound(allVal.begin(), allVal.end(), query[i].l) - allVal.begin();
		query[i].r = lower_bound(allVal.begin(), allVal.end(), query[i].r) - allVal.begin();
	}
	n = allVal.size() - 1;
	for (int i = 1; i <= n - 1; i++) {
		sum[i] = sum[i - 1] + allVal[i + 1] - allVal[i];
	}
	sum[n] = sum[n - 1] + 1;
	init(1, 1, n);
	for (int i = 0; i < q; i++) {
		update(1, 1, n, query[i].l, query[i].r, query[i].val);
		cout << get(1, 1, n, 1, n) << endl;///
	}
}