#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N int(1e5 + 33)
int n, m;
int f[N];
set <pair<int, int>> s;
int getf(int x) {
	return f[x] == x ? x : f[x] = getf(f[x]);
}
int d[N];
pair <int, int> b[N];
int main() {
	read(n); read(m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u); read(v);
		if (u > v) swap(u, v);
		s.insert({u, v});
		d[u]++; d[v]++;
	}
	for (int i = 1; i <= n; i++) f[i] = i;
	if (n < 2500) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (!s.count({i, j})) f[getf(i)] = getf(j);
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) b[i] = {d[i], i};
		sort(b + 1, b + n + 1);
		reverse(b + 1, b + n + 1);
		for (int i = 1; i <= 75; i++) {
			int x = b[i].second;
			for (int y = 1; y < x; y++) 
				if (!s.count({y, x})) f[getf(y)] = getf(x);
			for (int y = x + 1; y <= n; y++) 
				if (!s.count({x, y})) f[getf(y)] = getf(x);
		}
		for (int i = 76; i <= n; i++) {
			f[getf(b[i].second)] = getf(b[i - 1].second);
		}}
	int ans = -1;
	for (int i = 1; i <= n; i++) if (getf(i) == i) ans++;
	cout << ans << endl;
	return 0;
}