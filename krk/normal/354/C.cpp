#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxm = 1000005;

int n, k;
int sum[Maxm];
int mn = Maxm;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		sum[a]++; mn = min(mn, a);
	}
	if (k >= mn) k = mn - 1;
	for (int i = 1; i < Maxm; i++)
		sum[i] += sum[i - 1];
	for (int i = mn; i > k + 1; i--) {
		int tot = 0;
		for (int j = 0; j < Maxm; j += i)
			tot += (j + k < Maxm? sum[j + k]: sum[Maxm - 1]) - (j? sum[j - 1]: 0);
		if (tot == n) { printf("%d\n", i); return 0; }
	}
	printf("%d\n", k + 1);
	return 0;
}