#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, a[Maxn];
int L[Maxn], R[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		L[i] = L[i - 1] + 1 <= a[i]? L[i - 1] + 1: a[i];
	}
	for (int i = n; i >= 1; i--)
		R[i] = R[i + 1] + 1 <= a[i]? R[i + 1] + 1: a[i];
	for (int i = 1; i <= n; i++)
		res = max(res, min(L[i], R[i + 1] + 1));
	printf("%d\n", res);
	return 0;
}