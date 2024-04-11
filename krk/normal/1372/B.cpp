#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int g = 1;
		for (int i = 2; i * i <= n; i++) if (n % i == 0) {
			g = n / i;
			break;
		}
		printf("%d %d\n", g, n - g);
	}
    return 0;
}