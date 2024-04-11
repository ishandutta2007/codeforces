#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int T;
int n;
int a[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int res = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (gcd(a[i], 2 * a[j]) > 1 || gcd(2 * a[i], a[j]) > 1)
					res++;
		printf("%d\n", res);
	}
    return 0;
}