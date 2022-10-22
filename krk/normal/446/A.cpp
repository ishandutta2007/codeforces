#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Inf = 2000000000;

int n;
int a[Maxn];
int L[Maxn], R[Maxn];
int mx;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	a[0] = -Inf; a[n + 1] = Inf;
	for (int i = 1; i <= n; i++) {
		L[i] = a[i - 1] < a[i]? L[i - 1] + 1: 1;
		mx = max(mx, L[i]);
	}
	for (int i = n; i > 0; i--)
		R[i] = a[i] < a[i + 1]? R[i + 1] + 1: 1;
	for (int i = 1; i <= n; i++)
		if (a[i - 1] + 1 < a[i + 1])
			mx = max(mx, L[i - 1] + 1 + R[i + 1]);
		else mx = max(mx, max(L[i - 1] + 1, R[i + 1] + 1));
	printf("%d\n", mx);
	return 0;
}