#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int c[N], a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	for (int i = 1; i <= m; ++i) cin >> a[i];
	int cur = 1, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (cur == m + 1) break;
		if (c[i] <= a[cur]) cur++, cnt++;
	}
	cout << cnt;
}