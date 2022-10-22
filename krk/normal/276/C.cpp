#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int BIT[Maxn];
int n, q;
int a[Maxn], f[Maxn];
ll res;

void Insert(int x, int val)
{
	for (int i = x; i < Maxn; i += i & -i)
		BIT[i] += val;
}

int Get(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while (q--) {
		int l, r; scanf("%d %d", &l, &r);
		Insert(l, 1); Insert(r + 1, -1);
	}
	for (int i = 0; i < n; i++)
		f[i] = Get(i + 1);
	sort(a, a + n); sort(f, f + n);
	for (int i = 0; i < n; i++)
		res += ll(a[i]) * ll(f[i]);
	printf("%I64d\n", res);
	return 0;
}