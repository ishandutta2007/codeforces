#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		if (a[0] < 0) { printf("NO\n"); continue; }
		printf("YES\n");
		printf("%d\n", a[n - 1] + 1);
		for (int i = 0; i <= a[n - 1]; i++)
			printf("%d%c", i , i + 1 <= a[n - 1]? ' ': '\n');
	}
    return 0;
}