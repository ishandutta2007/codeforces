#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxm = 524288;

int n;
int a[Maxn];
vector <int> inds[Maxn];
int st[Maxm];

void Update(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) st[v] = max(st[v], val);
	else {
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

int Get(int v, int l, int r, int x)
{
	int res = st[v];
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res = max(res, Get(2 * v, l, m, x));
		else res = max(res, Get(2 * v + 1, m + 1, r, x));
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		inds[a[i]].push_back(i);
	}
	for (int i = 1; i <= n + 1; i++) {
		bool found = false;
		int lst = 0;
		for (int j = 0; j < inds[i].size() && !found; j++) {
			int cur = inds[i][j];
			if (lst + 1 < cur && Get(1, 1, n, lst + 1) < cur) found = true;
			lst = cur;
		}
		if (!found && lst < n)
			if (Get(1, 1, n, lst + 1) <= n) found = true;
		if (!found) { printf("%d\n", i); return 0; }
		lst = 0;
		for (int j = 0; j < inds[i].size(); j++) {
			int cur = inds[i][j];
			Update(1, 1, n, lst + 1, cur, cur);
			lst = cur;
		}
		if (lst < n)
			Update(1, 1, n, lst + 1, n, n + 1);
	}
	printf("%d\n", n + 2);
    return 0;
}