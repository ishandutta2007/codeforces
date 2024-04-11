#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int p[Maxn];
int cnt[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || p[i] >= p[i - 1]) cur = 1;
		else cur++;
		cnt[cur]++;
	}
	for (int i = n; i >= 1; i--) {
		if (i == n || p[i] >= p[i + 1]) cur = 1;
		else cur++;
		cnt[cur]++;
	}
	for (int i = 2; i < n; i++)
		if (p[i] > p[i - 1] && p[i] > p[i + 1]) {
			int mx1 = 1;
			int j = i;
			while (j - 1 > 0 && p[j] > p[j - 1]) {
				mx1++; j--;
			}
			int mx2 = 1;
			j = i;
			while (j + 1 <= n && p[j] > p[j + 1]) {
				mx2++; j++;
			}
			int mx = max(mx1, mx2);
			if (mx % 2 == 1 && mx1 == mx2 && cnt[mx] <= 2) res++;
		}
	printf("%d\n", res);
    return 0;
}