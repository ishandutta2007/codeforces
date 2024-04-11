#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];
int l[N], r[N];
int fw[N];

void upd(int p,int v) {
	for (; p <= n; p += p & -p) fw[p] += v;
}

int get(int p) {
	int ret = 0;
	for (; p > 0; p -= p & -p) ret += fw[p];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> l[i];
	for (int i = 1; i <= n; ++i) cin >> r[i];
	for (int i = 1; i <= n; ++i) {
		if (l[i] + r[i] >= n) return cout << "NO" << '\n',0;
		a[i] = n - l[i] - r[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (l[i] != get(n) - get(a[i])) return cout << "NO" << '\n',0;
		upd(a[i], 1);
	}
	for (int i = 1; i <= n; ++i) upd(a[i], -1);
	for (int i = n; i >= 1; --i) {
		if (r[i] != get(n) - get(a[i])) return cout << "NO" << '\n',0;
		upd(a[i], 1); 
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << '\n';
}