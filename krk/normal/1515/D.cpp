#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, l, r;
int has[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &l, &r);
		fill(has, has + n + 1, 0);
		int all = l - r;
		for (int i = 0; i < l; i++) {
			int c; scanf("%d", &c);
			has[c]++;
		}
		for (int i = 0; i < r; i++) {
			int c; scanf("%d", &c);
			has[c]--;
		}
		int res = 0;
		for (int i = 1; i <= n; i++) {
			while (all >= 2 && has[i] >= 2) {
				all -= 2;
				has[i] -= 2;
				res++;
			}
			while (all <= -2 && has[i] <= -2) {
				all += 2;
				has[i] += 2;
				res++;
			}
		}
		res += abs(all) / 2;
		int rem = 0;
		for (int i = 1; i <= n; i++)
			rem += abs(has[i]);
		res += rem / 2;
		printf("%d\n", res);
	}
    return 0;
}