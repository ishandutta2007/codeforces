#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, k;
int a[Maxn];
int b[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		sort(a, a + n);
		sort(b, b + n);
		for (int i = 0; i < n && k > 0; i++)
			if (a[i] < b[n - 1 - i]) {
				sum += b[n - 1 - i] - a[i];
				k--;
			}
		printf("%d\n", sum);
	}
    return 0;
}