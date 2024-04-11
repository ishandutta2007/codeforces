#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

#define N 100010
bool f[N];
int a[N], pa[N], p[N], siz[N];
ll ans[N], sum[N];
int find(int x) {
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}
void merge(int x, int y, int i) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (siz[x] > siz[y])
		swap(x, y);
	siz[y] += siz[x];
	sum[y] += sum[x];
	pa[x] = y;
	ans[i] = max(ans[i], sum[y]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("tt.in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);
	ans[n] = 0;
	for (int i = n; i >= 1; --i) {
		ans[i - 1] = ans[i];
		//add p[i]
		f[p[i]] = 1;
		siz[p[i]] = 1;
		sum[p[i]] = a[p[i]];
		pa[p[i]] = p[i];
		ans[i - 1] = max(ans[i - 1], sum[p[i]]);
		if (p[i] > 1 && f[p[i] - 1])
			merge(p[i] - 1, p[i], i - 1);
		if (p[i] < n && f[p[i] + 1])
			merge(p[i], p[i] + 1, i - 1);
	}
	for (int i = 1; i <= n; ++i)
		printf("%I64d\n", ans[i]);
	return 0;
}