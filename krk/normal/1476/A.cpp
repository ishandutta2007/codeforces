#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		int res = n / k * k;
		if (res < n) res += k;
		printf("%d\n", (res - 1) / n + 1);
	}
    return 0;
}