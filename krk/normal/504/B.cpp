#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;

int n;
int a[Maxn], b[Maxn];
int st[Maxm];
int gotA[Maxn], gotB[Maxn];

void Create(int v, int l, int r)
{
	st[v] = r - l + 1;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
	}
}

void Erase(int v, int l, int r, int x)
{
	st[v]--;
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) Erase(2 * v, l, m, x);
		else Erase(2 * v + 1, m + 1, r, x);
	}
}

int getSum(int v, int l, int r, int a, int b)
{
	if (a > b) return 0;
	if (l == a && r == b) return st[v];
	else {
		int res = 0;
		int m = l + r >> 1;
		if (l <= m) res += getSum(2 * v, l, m, a, min(m, b));
		if (m + 1 <= r) res += getSum(2 * v + 1, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

int getVal(int v, int l, int r, int nd)
{
	if (l == r) return l;
	else {
		int m = l + r >> 1;
		if (nd < st[2 * v]) return getVal(2 * v, l, m, nd);
		else return getVal(2 * v + 1, m + 1, r, nd - st[2 * v]);
	}
}

void Solve1(int a[], int gotA[])
{
	Create(1, 0, n - 1);
	for (int i = n - 1; i >= 0; i--) {
		gotA[i] = getSum(1, 0, n - 1, 0, a[i] - 1);
		Erase(1, 0, n - 1, a[i]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = n - 1; i >= 0; i--)
		scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; i--)
		scanf("%d", &b[i]);
	Solve1(a, gotA); Solve1(b, gotB);
	for (int i = 0; i < n; i++) {
		gotA[i] += gotB[i];
		gotA[i + 1] += gotA[i] / (i + 1);
		gotA[i] %= i + 1;
	}
	Create(1, 0, n - 1);
	for (int i = n - 1; i >= 0; i--) {
		int val = getVal(1, 0, n - 1, gotA[i]);
		printf("%d%c", val, i - 1 >= 0? ' ': '\n');
		Erase(1, 0, n - 1, val);
	}
	return 0;
}