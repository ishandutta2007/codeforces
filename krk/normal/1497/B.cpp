#include <bits/stdc++.h>
using namespace std;

const int Maxm = 100005;

int T;
int n, m;
int cnt[Maxm];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		fill(cnt, cnt + m, 0);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			cnt[a % m]++;
		}
		int res = 0;
		for (int i = 0; 2 * i <= m; i++) {
			int j = (m - i) % m;
			if (cnt[i] > 0 || cnt[j] > 0)
				if (i == j) res++;
				else if (cnt[i] > cnt[j]) res += cnt[i] - cnt[j];
				else if (cnt[i] < cnt[j]) res += cnt[j] - cnt[i];
				else res++;
		}
		printf("%d\n", res);
	}
    return 0;
}