#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, k;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		if (k > (n - 1) / 2) { printf("-1\n"); continue; }
		for (int i = 1; i <= k; i++) {
			a[2 * i - 2] = i;
			a[2 * i - 1] = n + 1 - i;
		}
		int pnt = k + 1;
		for (int i = 2 * k; i < n; i++)
			a[i] = pnt++;
		for (int i = 0; i < n; i++)
			printf("%d%c", a[i], i + 1 < n? ' ': '\n');
	}
    return 0;
}