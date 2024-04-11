#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;

int n, m, q;
int A[Maxn], B[Maxn];
vector <ii> seq[Maxn];
ll H[Maxn];
ll st[Maxm], lft[Maxm];
int mn[Maxm], flag[Maxm];

void Union(int v)
{
	ll use = min(lft[2 * v], st[2 * v + 1]);
	st[v] = st[2 * v] + use;
	lft[v] = min(lft[2 * v] - use, lft[2 * v + 1]);
}

void Create(int v, int l, int r)
{
	if (l == r) { st[v] = H[l]; lft[v] = A[l]; }
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Update(int v, int l, int r, int x, ll val)
{
	if (l == r) { st[v] = H[l]; lft[v] = val; }
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val);
		else Update(2 * v + 1, m + 1, r, x, val);
		Union(v);
	}
}

void downOn(int v, int fl)
{
	mn[v] += fl; flag[v] += fl;
}

void Down(int v)
{
	if (flag[v]) {
		downOn(2 * v, flag[v]);
		downOn(2 * v + 1, flag[v]);
		flag[v] = 0;
	}
}

void createMin(int v, int l, int r)
{
	if (l == r) mn[v] = B[l];
	else {
		int m = l + r >> 1;
		createMin(2 * v, l, m); createMin(2 * v + 1, m + 1, r);
		mn[v] = min(mn[2 * v], mn[2 * v + 1]);
	}
}

int getMin(int v, int l, int r, int x)
{
	if (l == r) return mn[v];
	else {
		Down(v);
		int m = l + r >> 1;
		if (x <= m) return min(getMin(2 * v, l, m, x), mn[2 * v + 1]);
		return getMin(2 * v + 1, m + 1, r, x);
	}
}

void updateMin(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) downOn(v, val);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) updateMin(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) updateMin(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		mn[v] = min(mn[2 * v], mn[2 * v + 1]);
	} 
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i < n; i++)
		scanf("%d %d", &A[i], &B[i]);
	for (int i = n - 2; i >= 1; i--)
		B[i] = min(B[i], B[i + 1]);
	createMin(1, 1, n - 1);
	while (m--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		seq[a].push_back(ii(b, c));
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < seq[i].size(); j++) {
			ii e = seq[i][j];
			if (e.first == n) { H[i] += e.second; continue; }
			ll my = min(getMin(1, 1, n - 1, e.first), e.second);
			updateMin(1, 1, n - 1, e.first, n - 1, -my);
			H[i] += my;
		}
	Create(1, 1, n);
	printf("%d\n", st[1]);
	while (q--) {
		int v, w; scanf("%d %d", &v, &w);
		Update(1, 1, n, v, w);
		printf("%d\n", st[1]);
	}
	return 0;
}