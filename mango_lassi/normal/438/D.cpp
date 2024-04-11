#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1<<17;
int min_val[2 * N];
int max_val[2 * N];
ll sum[2 * N];
int set_val[2 * N];
int h = 1;

void upd(int i, int ia, int ib) {
	int v = set_val[i];
	if (v != -1) {
		min_val[i] = v;
		max_val[i] = v;
		sum[i] = (ll)v * (ib - ia + 1);
	} else {
		min_val[i] = min(min_val[2*i], min_val[2*i+1]);
		max_val[i] = max(max_val[2*i], max_val[2*i+1]);
		sum[i] = sum[2*i] + sum[2*i+1];
	}
}

void push(int i, int ia, int ib) {
	int v = set_val[i];
	if (v != -1 && i < h) {
		set_val[2*i] = v;
		set_val[2*i+1] = v;
		int mid = (ia + ib) >> 1;
		upd(2*i, ia, mid);
		upd(2*i+1, mid+1, ib);
		set_val[i] = -1;
	}
}
void build(int i = 1, int ia = 0, int ib = h-1) {
	if (i < h) {
		int mid = (ia + ib) >> 1;
		build(2*i, ia, mid);
		build(2*i+1, mid+1, ib);
	}
	upd(i, ia, ib);
}
void upd_mod(int a, int b, int x, int ia = 0, int ib = h-1, int i = 1) {
	if (b < ia || ib < a || max_val[i] < x) return;
	if (a <= ia && ib <= b && min_val[i] == max_val[i]) {
		set_val[i] = min_val[i] % x;
	} else {
		push(i, ia, ib);
		int mid = (ia + ib) >> 1;
		upd_mod(a, b, x, ia, mid, 2*i);
		upd_mod(a, b, x, mid+1, ib, 2*i+1);
	}
	upd(i, ia, ib);
}
void upd_set(int a, int b, int x, int ia = 0, int ib = h-1, int i = 1) {
	if (b < ia || ib < a) return;
	if (a <= ia && ib <= b) {
		set_val[i] = x;
	} else {
		push(i, ia, ib);
		int mid = (ia + ib) >> 1;
		upd_set(a, b, x, ia, mid, 2*i);
		upd_set(a, b, x, mid+1, ib, 2*i+1);
	}
	upd(i, ia, ib);
}

ll calc(int a, int b, int ia = 0, int ib = h-1, int i = 1) {
	if (b < ia || ib < a) return 0;
	if (a <= ia && ib <= b) return sum[i];
	push(i, ia, ib);
	int mid = (ia + ib) >> 1;
	ll res = 0;
	res += calc(a, b, ia, mid, 2*i);
	res += calc(a, b, mid+1, ib, 2*i+1);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	while(h < n) h <<= 1;
	for (int i = 0; i < n; ++i) {
		cin >> set_val[i + h];
	}
	for (int i = h-1; i > 0; --i) set_val[i] = -1;
	build();

	while(q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			cout << calc(a, b) << '\n';
		} else if (t == 2) {
			int a, b, x;
			cin >> a >> b >> x;
			--a; --b;
			upd_mod(a, b, x);
		} else {
			int a, x;
			cin >> a >> x;
			--a;
			upd_set(a, a, x);
		}
	}
}