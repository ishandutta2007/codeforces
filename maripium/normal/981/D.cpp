#include <bits/stdc++.h>
using namespace std;

int n, K;
bool f[55][55];
long long a[55];
bool check(long long x) {
	for (int i = 0;i <= K;++i)
		for (int j = 0;j <= n;++j) f[i][j] = false;
	f[0][0] = true;
	for (int k = 1;k <= K;++k) {
		for (int i = 1;i <= n;++i) {
			for (int j = 1;j <= i;++j) if (f[k - 1][j - 1]) {
				long long s = a[i] - a[j - 1];
				if ((s & x) == x) f[k][i] = true;
			}
		}
	}
	return f[K][n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> K;
	for (int i = 1;i <= n;++i) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	long long res = 0;
	for (int i = 55;i >= 0;--i) {
		if (check(res + (1LL << i))) res += (1LL << i);
	}
	cout << res << endl;
}