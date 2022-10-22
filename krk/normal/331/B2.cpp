#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 300005;
const int Maxm = 2097152;

int n;
int a[Maxn], pos[Maxn];
int res[Maxm];
int q;

void Create(int v, int l, int r)
{
	if (l == r) res[v] = 1;
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		res[v] = res[2 * v] - (pos[m] < pos[m + 1]) + res[2 * v + 1];
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return res[v];
	else {
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return Get(2 * v, l, m, a, m) - (pos[m] < pos[m + 1]) + Get(2 * v + 1, m + 1, r, m + 1, b);
	}
}

void Update(int v, int l, int r, int x)
{
	if (l == r) res[v] = 1;
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x);
		else Update(2 * v + 1, m + 1, r, x);
		res[v] = res[2 * v] - (pos[m] < pos[m + 1]) + res[2 * v + 1];
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); pos[a[i]] = i;
	}
	Create(1, 1, n);
	scanf("%d", &q);
	while (q--) {
		int p, x, y; scanf("%d %d %d", &p, &x, &y);
		if (p == 1) printf("%d\n", Get(1, 1, n, x, y));
		else { 
			pos[a[x - 1]] = y - 1; pos[a[y - 1]] = x - 1; swap(a[x - 1], a[y - 1]);
			Update(1, 1, n, a[x - 1]); Update(1, 1, n, a[y - 1]);
		}
	}
	return 0;
}