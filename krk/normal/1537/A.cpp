#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		int sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (sum == n) printf("0\n");
		else if (sum < n) printf("1\n");
		else printf("%d\n", sum - n);
	}
    return 0;
}