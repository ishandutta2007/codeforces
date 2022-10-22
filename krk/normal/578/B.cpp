#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, k, x;
ll a[Maxn];
ll L[Maxn], R[Maxn];
ll mx;

int main()
{
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &a[i]);
		L[i] = L[i - 1] | a[i];
	}
	for (int i = n; i >= 1; i--)
		R[i] = R[i + 1] | a[i];
	ll r = 1;
	while (k--) r *= x;
	for (int i = 1; i <= n; i++)
		mx = max(mx, L[i - 1] | (a[i] * r) | R[i + 1]);
	printf("%I64d\n", mx);
	return 0;
}