#include <bits/stdc++.h>
using namespace std;

const int N = 705;

int n;
int a[N], g[N][N];
int f[N][N][2];

int calc(int l,int r,int side) {
	if (l > r) return 1;
	int& ret = f[l][r][side];
	if (~ret) return ret;
	ret = 0;
	int root = (side ? l - 1 : r + 1);
	for (int mid = l; mid <= r; ++mid) if (g[mid][root] > 1) {
		if (calc(l, mid - 1, 0) && calc(mid + 1, r, 1)) {
			ret = 1; break;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= n + 1; ++j) {
			g[i][j] = __gcd(a[i], a[j]);
			f[i][j][0] = f[i][j][1] = -1;
		}
	}
	cout << (calc(1, n, 0) ? "Yes" : "No") << '\n';
}