#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < 2 * n; i++)
			scanf("%d", &a[i]);
		sort(a, a + 2 * n);
		for (int i = 0; i < n; i++)
			printf("%d %d%c", a[i], a[n + i], i + 1 < n? ' ': '\n');
	}
    return 0;
}