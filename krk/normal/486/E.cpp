#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;

int n;
int a[Maxn];
int st[Maxm];
int L[Maxn], R[Maxn];
int len;
int seq[Maxn], slen;
int mx[Maxn], mn[Maxn];
int res[Maxn];

void Create(int v, int l, int r)
{
	st[v] = 0;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
	}
}

void Update(int v, int l, int r, int x, int val)
{
	if (l == r) st[v] = val;
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val);
		else Update(2 * v + 1, m + 1, r, x, val);
		st[v] = max(st[2 * v], st[2 * v + 1]);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res = max(res, Get(2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = max(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		L[i] = Get(1, 0, Maxn, 0, a[i] - 1);
		Update(1, 0, Maxn, a[i], L[i] + 1);
	}
	Create(1, 0, Maxn);
	for (int i = n - 1; i >= 0; i--) {
		R[i] = Get(1, 0, Maxn, a[i] + 1, Maxn);
		Update(1, 0, Maxn, a[i], R[i] + 1);
		len = max(len, L[i] + 1 + R[i]);
	}
	for (int i = 0; i < n; i++)
		if (len == L[i] + 1 + R[i]) seq[slen++] = i;
		else res[i] = 1;
	mx[0] = 0;
	for (int i = 0; i + 1 < slen; i++)
		mx[i + 1] = max(mx[i], a[seq[i]]);
	mn[slen - 1] = Maxn;
	for (int i = slen - 1; i > 0; i--)
		mn[i - 1] = min(mn[i], a[seq[i]]);
	for (int i = 0; i < slen; i++)
		if (mx[i] < a[seq[i]] && a[seq[i]] < mn[i]) res[seq[i]] = 3;
		else res[seq[i]] = 2;
	for (int i = 0; i < n; i++)
		printf("%d", res[i]);
	printf("\n");
	return 0;
}