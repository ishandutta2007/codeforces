#include <bits/stdc++.h>
using namespace std;

const int N = 2205;
typedef pair<long long,int> Pair;

int n, k;
int a[N], b[N];
Pair f[N][N];

Pair operator + (Pair a,Pair b) {
	return Pair(a.first + b.first, a.second + b.second);
}

bool check(int mid) {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			f[i][j] = Pair((long long)1e18, 0);
		}
	}
	f[0][0] = Pair(0, 0);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i) f[i][j] = min(f[i][j], f[i - 1][j]);
			if (j) f[i][j] = min(f[i][j], f[i][j - 1]);
			if (i && j && i <= j) f[i][j] = min(f[i][j], f[i - 1][j - 1] + Pair(a[i] + b[j] - 2 * mid, 1));
		}
	}
	return f[n][n].second >= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	int low = (int)-1e9, high = (int)1e9;
	while (low < high) {
		int mid = low + high >> 1;
		if (check(mid)) high = mid;
		else low = mid + 1;
	}
	check(low);
	cout << f[n][n].first + 2LL * k * low << '\n';
}