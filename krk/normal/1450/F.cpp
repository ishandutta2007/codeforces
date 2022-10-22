#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];
int cnt[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill(cnt, cnt + n + 1, 0);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		int mx = 0;
		for (int i = 0; i <= n; i++)
			mx = max(mx, cnt[i]);
		if (mx > (n + 1) / 2) { printf("-1\n"); continue; }
		int all = 0;
		fill(cnt, cnt + n + 1, 0);
		for (int i = 0, j; i < n; i = j + 1) {
			all += 2;
			cnt[a[i]]++;
			j = i;
			while (j + 1 < n && a[j] != a[j + 1]) j++;
			cnt[a[j]]++;
		}
		mx = 0;
		for (int i = 0; i <= n; i++)
			mx = max(mx, cnt[i]);
		int res = all / 2 - 1;
		if (mx > all / 2) res += (mx - (all - mx)) / 2 - 1;
		printf("%d\n", res);
	}
    return 0;
}