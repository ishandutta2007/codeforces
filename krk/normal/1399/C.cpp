#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int w[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		fill(w, w + Maxn, 0);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			w[a]++;
		}
		int res = 0;
		for (int i = 0; i <= 100; i++) {
			int cur = 0;
			for (int j = 0; j <= i - j; j++)
				if (j == i - j) cur += w[j] / 2;
				else cur += min(w[j], w[i - j]);
			res = max(res, cur);
		}
		printf("%d\n", res);
	}
    return 0;
}