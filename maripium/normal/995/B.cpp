#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int n;
int a[N], bit[N];
int p[N], nxt[N];

void upd(int p,int v) {
	for (; p <= n; p += p & -p) bit[p] += v;
}

int get(int p) {
	int ret = 0;
	for (; p > 0; p -= p & -p) ret += bit[p];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n; n = n + n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[a[i]] = i;
		upd(i, 1);
	}
	int res = 0;
	for (int i = 1;i <= n;++i) if (!nxt[a[i]]) {
		res += get(p[a[i]]) - get(i) - 1;
		nxt[a[i]] = 1;
		upd(p[a[i]], -1);
	}
	cout << res;
}