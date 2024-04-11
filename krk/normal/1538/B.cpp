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
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (sum % n) printf("-1\n");
		else {
			sum /= n;
			int res = 0;
			for (int i = 0; i < n; i++)
				res += a[i] > sum;
			printf("%d\n", res);
		}
	}
    return 0;
}