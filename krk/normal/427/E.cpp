#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const ll Inf = 9000000000000000000ll;

int n, m;
int X[Maxn];
ll L[Maxn], R[Maxn];
ll res = Inf;

int Get(int x)
{
	return x / m + (x % m > 0);
}

int main()
{
	scanf("%d %d", &n, &m);
	if (n == 1) { printf("0\n"); return 0; }
	for (int i = 0; i < n; i++)
		scanf("%d", &X[i]);

	L[0] = X[0];
	for (int i = 1; i < n; i++)
		L[i] = L[i - 1] + ll(i % m == 0? X[i]: 0);
	R[n - 1] = X[n - 1];
	for (int i = n - 2; i >= 0; i--)
		R[i] = R[i + 1] + ll((n - 1 - i) % m == 0? X[i]: 0);

	for (int i = 0; i < n; i++) {
		int a = Get(i + 1), b = Get(n - i);
		res = min(res, ll(a) * X[i] - L[i] + R[i] - ll(b) * X[i]);
	}
	printf("%I64d\n", 2 * res);
	return 0;
}