#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];
ll sum[Maxn];
ll res[Maxn];
int q;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	sum[0] = a[0];
	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i < Maxn; i++)
		for (ll j = n - 2, dif = 1ll; j >= 0; dif *= ll(i), j -= dif)
			res[i] += sum[j];
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int k; scanf("%d", &k);
		printf("%I64d%c", res[k], i + 1 < q? ' ': '\n');
	}
	return 0;
}