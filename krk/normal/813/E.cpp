#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxm = 524288;

int n, k;
int a[Maxn];
vector <int> I[Maxn];
vector <int> st[Maxm];
int q;
int res;

void Insert(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) st[v].push_back(val);
	else {
		int m = l + r >> 1;
		if (a <= m) Insert(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Insert(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

int Get(int v, int l, int r, int x, int R)
{
	int res = upper_bound(st[v].begin(), st[v].end(), R) - st[v].begin();
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res += Get(2 * v, l, m, x, R);
		else res += Get(2 * v + 1, m + 1, r, x, R);
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		I[a[i]].push_back(i);
		if (I[a[i]].size() > k) Insert(1, 1, n, 1, I[a[i]][I[a[i]].size() - k - 1], i);
	}
	scanf("%d", &q);
	while (q--) {
		int x, y; scanf("%d %d", &x, &y);
		x = (x + res) % n + 1;
		y = (y + res) % n + 1;
		if (x > y) swap(x, y);
		res = (y - x + 1) - Get(1, 1, n, x, y);
		printf("%d\n", res);
	}
	return 0;
}