#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 500005, INF = 2e9;

int n, m, K, a[N], f[N], tot, c[N]; 

vector<int> A[N], B[N];

typedef long long LL;

LL ans;

struct E{
	int l, r;
} e[N];

void inline add(int x, int k) {
	for (; x <= m; x += x & -x) c[x] = max(c[x], k);
}

int inline ask(int x) {
	int res = 0;
	for (; x; x -= x & -x) res = max(res, c[x]);
	return res;
}


void inline add2(int x, int k) {
	for (; x <= m; x += x & -x) c[x] = min(c[x], k);
}

int inline ask2(int x) {
	int res = INF;
	for (; x; x -= x & -x) res = min(res, c[x]);
	return res;
}

int main() {
	scanf("%d", &n); m = n + 2;
	for (int i = 1; i <= n; i++) scanf("%1d", a + i);
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			f[i] = f[i - 1] + 1;
			if (a[i + 1] == 0) e[++tot] = (E) { i - f[i] + 1, i };
		} else f[i] = 0;
	}
	for (int i = 1; i <= tot; i++) {
		int l = e[i].l, r = e[i].r, len = r - l + 1;
		A[i].push_back(0);
		for (int j = 1; j <= len; j++) {
			int id = ask(m - j);
			if (!id) A[i].push_back(l - 1);
			else A[i].push_back((l - 1) - (e[id].r - j + 2) + 1);
		}
		add(m - len, i);
	}
	for (int i = 0; i <= m; i++) c[i] = INF;
	for (int i = tot; i; i--) {
		int l = e[i].l, r = e[i].r, len = r - l + 1;
		B[i].push_back(0);
		for (int j = 1; j <= len; j++) {
			int id = ask2(m - j - 1);
			if (id == INF) B[i].push_back(n - r);
			else B[i].push_back((e[id].l + j - 1) - (r + 1) + 1);
		}
		add2(m - len, i);
	}
	// for (int i = 1; i <= tot; i++) {
	// 	int l = e[i].l, r = e[i].r, len = r - l + 1;
	// 	//cout << e[i].l << " seg " << e[i].r << endl;
	// 	for (int j = 1; j <= len; j++)
	// 		cout << A[i][j] << " " << B[i][j] << endl;
	// }
	for (int i = 1; i <= tot; i++) {
		int l = e[i].l, r = e[i].r, len = r - l + 1;
		for (int j = 1; j <= len; j++) {
			ans += (LL)j * (len - j + 1);
			ans += (LL)j * (A[i][j] + B[i][j]);
		}
		ans += (LL)len * ((LL)A[i][len] * B[i][len]);
	}
	printf("%lld\n", ans);
	return 0;
}