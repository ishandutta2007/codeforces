#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 1e5 + 10, P = 1e5 + 5, T = 320;
int n,a[maxn];

int f[T + 10][maxn << 1];
int calc() {
	int res = 1;
	for (int d = -T; d <= T; ++d) {
		vector <ll> b;
		for (int i = 1; i <= n; ++i)
			b.push_back(a[i] - 1ll * i * d);
		sort(b.begin(), b.end());
		int len = 1;
		for (int i = 1; i < n; ++i) {
			if (b[i] == b[i - 1]) ++len;
			else len = 1;
			res = max(res, len);
		}
	}
	for (int i = 1; i <= n; ++i) {
		int pos = i % (T + 1);
		for (int j = i + 1; j <= i + T && j <= n; ++j) {
			if ((a[j] - a[i]) % (j - i)) continue;
			int d = (a[j] - a[i]) / (j - i), nxt = j % (T + 1);
			f[nxt][d + P] = max(f[nxt][d + P], f[pos][d + P] + 1);
			res = max(res, f[nxt][d + P] + 1);
		}
		for (int j = max(1, i - T); j < i; ++j)
			if ((a[i] - a[j]) % (i - j) == 0) f[pos][(a[i] - a[j]) / (i - j) + P] = 0;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	printf("%d\n", n - calc());
	return 0;
}