#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int n;
int a[Maxn], sum[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = (a[i] == 2) + sum[i - 1];
	}
	int gones = 0;
	for (int i = 1; i <= n; i++) {
		int twos = 0, best = 0;
		for (int j = i; j <= n; j++) {
			if (a[j] == 2) { twos++; best = max(best, twos); }
			else best++;
			res = max(res, gones + best + sum[n] - sum[j]);
		}
		gones += (a[i] == 1);
	}
	printf("%d\n", res);
	return 0;
}