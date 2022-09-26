#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n, m;
int cnt[N];
int last[N];

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		last[i] = n;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (u > v) {
			v += n;
		}
		++cnt[u];
		last[u] = min(last[u], v - u);
	}
	
	for (int i = 0; i < n; ++i) {
		int ans = 0;
		for (int j = 0; j < n; ++j) {
			int u = (i + j) % n;
			if (cnt[u]) {
				ans = max(ans, j + (cnt[u] - 1) * n + last[u]);
			}
		}
		
		cout << ans << ' ';
	}
}