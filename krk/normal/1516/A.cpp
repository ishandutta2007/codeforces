#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, k;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i + 1 < n; i++)
			while (a[i] > 0 && k > 0) {
				a[i]--;
				a[n - 1]++;
				k--;
			}
		for (int i = 0; i < n; i++)
			printf("%d%c", a[i], i + 1 < n? ' ': '\n');
	}
    return 0;
}