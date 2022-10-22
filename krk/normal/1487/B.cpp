#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		if (n % 2) {
			int tims = (k - 1) / ((n - 1) / 2);
			k += tims;
		}
		k %= n;
		if (k == 0) k += n;
		printf("%d\n", k);
	}
    return 0;
}