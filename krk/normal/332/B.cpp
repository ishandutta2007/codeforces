#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, k;
ll x[Maxn];
ll sum[Maxn];
ll mx[Maxn];
int par[Maxn];
ll res;
int a, b;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &x[i]);
	for (int i = 0; i < k; i++)
		sum[k - 1] += x[i];
	mx[k - 1] = sum[k - 1]; par[k - 1] = 0;
	for (int i = k; i < n; i++) {
		sum[i] = sum[i - 1] + x[i] - x[i - k];
		if (mx[i - 1] >= sum[i]) { mx[i] = mx[i - 1]; par[i] = par[i - 1]; }
		else { mx[i] = sum[i]; par[i] = i - k + 1; }
	}
	for (int i = 2 * k - 1; i < n; i++) {
		ll cand = sum[i] + mx[i - k];
		if (cand > res || cand == res && par[i - k] < a) { res = cand; a = par[i - k]; b = i - k + 1; }
	}
	printf("%d %d\n", a + 1, b + 1);
	return 0;
}