#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int res = 0;
		for (int i = 0; i + 1 < n; i++) {
			int u = a[i], v = a[i + 1];
			if (u > v) swap(u, v);
			while (2 * u < v) {
				res++;
				u = 2 * u;
			}
		}
		printf("%d\n", res);
	}
    return 0;
}