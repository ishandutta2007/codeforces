#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
ll a[Maxn];
ll res[Maxn][2];

ll getRes(int x, int st)
{
	if (x <= 0 || x > n) return 0ll;
	if (res[x][st] > 0ll || res[x][st] == -1) return res[x][st];
	if (res[x][st] == -2) { res[x][st] = -1ll; return -1ll; }
	res[x][st] = -2ll;
	ll add = st == 0? getRes(x + a[x], 1): getRes(x - a[x], 0);
	if (add == -1ll) res[x][st] = -1ll;
	else res[x][st] = a[x] + add;
	return res[x][st];
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 1; i <= n - 1; i++) {
		a[1] = i;
		res[1][0] = res[1][1] = 0ll;
		printf("%I64d\n", getRes(1, 0));
	}
	return 0;
}