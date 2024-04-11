#include <cstdio>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn], b[Maxn];

bool Solve(int l, int r)
{
	if (l == r) return true;
	else {
		int m = l + r >> 1;
		if (!Solve(l, m) || !Solve(m + 1, r)) return false;
		int sub = 0;
		int i = l, j = m + 1;
		int pnt = l;
		while (i <= m || j <= r)
			if (i <= m && (j > r || a[j] + m + 1 - i > a[i] - sub)) {
				b[pnt++] = a[i] - sub; i++;
			} else { b[pnt++] = a[j] + m + 1 - i; sub++; j++; }
		for (int i = l; i <= r; i++) {
			a[i] = b[i];
			if (i > l && a[i - 1] > a[i]) return false;
		}
		return true;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (Solve(0, n - 1))
		for (int i = 0; i < n; i++)
			printf("%d%c", a[i], i + 1 < n? ' ': '\n');
	else printf(":(\n");
	return 0;
}