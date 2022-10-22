#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 12;

int n;
ll a[Maxn][Maxn];
ll res = 1;

int main()
{
	scanf("%d", &n);
	for (int j = 1; j <= n; j++) a[1][j] = 1;
	for (int i = 2; i <= n; i++) {
		a[i][1] = 1;
		for (int j = 2; j <= n; j++) {
			a[i][j] = a[i][j - 1] + a[i - 1][j];
			res = max(res, a[i][j]);
		}
	}
	printf("%I64d\n", res);
	return 0;
}