#include <bits/stdc++.h>
#define i64 long long
#define db double
#define x first
#define y second
using namespace std;
const int N = 300 + 10;
int T, n, m;
int a[N * N], id[N * N];
vector<int> g[N];
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i <= n * m; i++) cin >> a[i], id[i] = i;
	sort(id + 1, id + n * m + 1, [&](int x, int y) {
		if(a[x] != a[y]) return a[x] < a[y];
		return x < y;
	});
	for(int i = 1; i <= n * m; i++) {
		g[(i - 1) / m + 1].push_back(id[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end(), [&](int x, int y) {
			if(a[x] != a[y]) return a[x] < a[y];
			return x > y;
		});
		
		for(int j = 0; j < m; j++) {
			//~ cout << g[i][j] <<" ";
			for(int k = j + 1; k < m; k++) {
				if(g[i][j] < g[i][k]) {
					ans++;
				}
			}
		}
		//~ cout << endl;
	}
	cout << ans << endl;
	return;
}
int main() {
	cin >> T;
	for(; T--; ) {
		solve();
	}
	return 0;
}