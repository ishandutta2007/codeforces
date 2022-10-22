#include <bits/stdc++.h>
using namespace std;

const int Maxm = 21;

int T;
int n, W;
int cnt[Maxm];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &W);
		fill(cnt, cnt + Maxm, 0);
		int lft = n;
		for (int i = 0; i < n; i++) {
			int w; scanf("%d", &w);
			int j = 0;
			while (1 << j < w) j++;
			cnt[j]++;
		}
		int res = 0;
		while (lft > 0) {
			res++;
			int cur = W;
			for (int i = Maxm - 1; i >= 0; i--)
				while (cnt[i] > 0 && (1 << i) <= cur) {
					cnt[i]--; cur -= 1 << i;
					lft--;
				}
		}
		printf("%d\n", res);
	}
    return 0;
}