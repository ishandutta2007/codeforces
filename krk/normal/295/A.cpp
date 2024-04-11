#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m, k;
int a[Maxn];
int l[Maxn], r[Maxn], d[Maxn];
ll BIT1[Maxn], BIT2[Maxn];

void Insert(ll BIT[], int x, ll val)
{
	for (int i = x; i < Maxn; i += i & -i)
		BIT[i] += val;
}

ll Get(ll BIT[], int x)
{
	ll res = 0ll;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &l[i], &r[i], &d[i]);
	while (k--) {
		int x, y; scanf("%d %d", &x, &y);
		Insert(BIT1, x, 1); Insert(BIT1, y + 1, -1);
	}
	for (int i = 1; i <= m; i++) {
		int tims = Get(BIT1, i);
		Insert(BIT2, l[i], ll(tims) * ll(d[i])); Insert(BIT2, r[i] + 1, -ll(tims) * ll(d[i]));
	}
	for (int i = 1; i <= n; i++)
		printf("%I64d%c", ll(a[i]) + Get(BIT2, i), i + 1 <= n? ' ': '\n');
	return 0;
}