#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, M, D;

signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> k >> M >> D;
	int res = 0;
	for (int i = 1;i <= D && (i - 1) * k <= n - 1;++i) {
		int mn = (n + 1) / (i * k + 1), mx = n / ((i - 1) * k + 1);
		int x = min(mx, M);
		if (x >= mn) res = max(res, x * i); 
	}
	cout << res;
}