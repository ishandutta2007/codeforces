#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n, t, k;
int a[Maxn], my[Maxn];
int P[Maxn];
int mn, mx;

int main()
{
	scanf("%d %d %d", &n, &t, &k);
	my[0] = 1; a[0] = 1;
	for (int i = 1; i <= t; i++) {
		scanf("%d", &a[i]); my[i] = my[i - 1] + a[i - 1];
		mx += a[i] - 1;
	}
	mx++;
	my[t + 1] = my[t] + a[t];
	for (int i = 1; i <= t; i++)
		mn += max(0, a[i] - a[i + 1]);
	if (mn <= k && k <= mx) {
		for (int i = 1; i <= t; i++)
			for (int j = my[i]; j < my[i + 1]; j++)
				P[j] = my[i - 1];
		int cur = mx;
		for (int i = 1; i <= t; i++) {
			int nxt = my[i - 1] + 1;
			for (int j = my[i] + 1; j < my[i + 1] && nxt < my[i] && cur > k; j++) {
				P[j] = nxt++; cur--;
			}
		}
		printf("%d\n", n);
		for (int i = 2; i <= n; i++)
			printf("%d %d\n", P[i], i);
	} else printf("-1\n");
	return 0;
}