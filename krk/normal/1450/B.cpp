#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, k;
int x[Maxn], y[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d %d", &x[i], &y[i]);
		bool ok = false;
		for (int i = 0; i < n && !ok; i++) {
			ok = true;
			for (int j = 0; j < n && ok; j++)
				ok = abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k;
		}
		printf("%d\n", ok? 1: -1);
	}
    return 0;
}