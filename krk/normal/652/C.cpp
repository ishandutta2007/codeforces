#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n, m;
int p[Maxn], inpos[Maxn];
int mn[Maxn];
ll res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		inpos[p[i]] = i;
	}
	fill(mn, mn + n + 2, n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		int l = inpos[a], r = inpos[b];
		if (l > r) swap(l, r);
		mn[l] = min(mn[l], r);
	}
	for (int i = n; i >= 1; i--) {
		mn[i] = min(mn[i], mn[i + 1]);
		res += mn[i] - i;
	}
	printf("%I64d\n", res);
	return 0;
}