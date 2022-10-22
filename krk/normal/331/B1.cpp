#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn], pos[Maxn];
int q;

int Shave(int l, int r)
{
	int res = 1;
	for (int i = l + 1; i <= r; i++)
		if (pos[i] < pos[i - 1]) res++;
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); pos[a[i]] = i;
	}
	scanf("%d", &q);
	while (q--) {
		int p, x, y; scanf("%d %d %d", &p, &x, &y);
		if (p == 1) printf("%d\n", Shave(x, y));
		else { pos[a[x - 1]] = y - 1; pos[a[y - 1]] = x - 1; swap(a[x - 1], a[y - 1]); }
	}
	return 0;
}