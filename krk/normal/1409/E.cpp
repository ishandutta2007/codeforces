#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
int X[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &X[i]);
		for (int i = 0; i < n; i++) {
			int y; scanf("%d", &y);
		}
		sort(X, X + n);
		int best = 0;
		int res = 0;
		for (int i = 0; i < n; i++) {
			int ind = upper_bound(X, X + n, X[i] + k) - X;
			res = max(res, best + ind - i);
			ind = lower_bound(X, X + n, X[i] - k) - X;
			best = max(best, i - ind + 1);
		}
		printf("%d\n", res);
	}
    return 0;
}