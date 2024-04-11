#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 3e5 + 10;
int n,p[maxn],f[maxn],pre[maxn],st[maxn][20],lg2[maxn];
char ans[maxn];
int query(int l, int r) {
	if (l > r) return 0;
	int i = lg2[r - l + 1];
	return max(st[l][i], st[r - (1 << i) + 1][i]);
}

void work() {
	scanf("%d", &n);
	lg2[0] = -1;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &p[i]), st[i][0] = i + p[i], lg2[i] = lg2[i >> 1] + 1;
	for (int j = 1; j < 20; ++j)
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	for (int i = 1; i <= n; ++i) {
		if (f[i - 1] >= i) f[i] = max(f[i - 1], i + p[i]), pre[i] = -1;
		else f[i] = f[i - 1], pre[i] = -1;
		int l = 0, r = i - 1, mid, res = -1;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (f[mid] >= i - p[i] - 1) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		if (res != -1) {
			int val = max(i - 1, query(res + 1, i - 1));
			if (f[i] < val) f[i] = val, pre[i] = res;
		}
	}
	if (f[n] < n) return printf("NO\n"), void();
	ans[n + 1] = 0;
	for (int i = n; i; ) {
		if (pre[i] == -1) ans[i] = 'R', --i;
		else {
			ans[i] = 'L';
			for (int j = pre[i] + 1; j < i; ++j) ans[j] = 'R';
			i = pre[i];
		}
	}
	printf("YES\n%s\n", ans + 1);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}