#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		while (k > 3) {
			printf("1 ");
			n--; k--;
		}
		if (n % 2) printf("%d %d %d\n", n / 2, n / 2, 1);
		else if (n / 2 % 2) printf("%d %d %d\n", n / 2 - 1, n / 2 - 1, 2);
		else printf("%d %d %d\n", n / 2, n / 4, n / 4);
	}
    return 0;
}