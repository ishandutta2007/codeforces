#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); a[i] *= 2;
		sum += a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		if (sum >= 9 * n) { printf("%d\n", i); return 0; }
		else {
			sum -= a[i];
			sum += 10;
		}
	printf("%d\n", n);
	return 0;
}