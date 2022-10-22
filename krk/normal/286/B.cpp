#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 2000015;

int n;
int diag[Maxn];
int res[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		if (i % n == 0) diag[n + i] = min(n - 1, i + n - 1);
		else diag[n + i] = i - 1;
	for (int i = n - 1; i >= 2; i--)
		for (int j = 0; j < n; j += i)
			diag[i + j] = diag[i + 1 + min(n - 1, j + i - 1)];
	for (int i = 1; i <= n; i++)
		res[diag[2 + i - 1]] = i;
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}