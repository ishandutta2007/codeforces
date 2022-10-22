#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

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
		int i = n - 1;
		while (i > 0 && a[i - 1] >= a[i]) i--;
		while (i > 0 && a[i - 1] <= a[i]) i--;
		printf("%d\n", i);
	}
    return 0;
}