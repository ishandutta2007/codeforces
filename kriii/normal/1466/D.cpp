#include <stdio.h>
#include <algorithm>
using namespace std;

int n, k, w[100100], d[100100], c[100100];
long long out[100100];

int main()
{
	int t; scanf ("%d", &t); while (t--){
		long long base = 0;

		scanf ("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &w[i]), d[i] = -1;
		for (int i = 1; i < n; i++){
			int x, y; scanf ("%d %d", &x, &y);
			d[x]++; d[y]++;
			base += w[x] + w[y];
		}

		k = 0;
		for (int i = 1; i <= n; i++) for (int j = 0; j < d[i]; j++) c[k++] = w[i];
		sort(c, c + k);

		out[n - 1] = base;
		for (int i = n - 1, j = 0; i >= 1; i--, j++) out[i - 1] = out[i] - c[j];

		for (int i = 1; i < n; i++){
			printf ("%lld%c", out[i], " \n"[i == n - 1]);
		}
	}

	return 0;
}