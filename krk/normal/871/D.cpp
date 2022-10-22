#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 10000005;

int mn[Maxn];
int n;
int cnt[Maxn];
ll tot;
ll prs[Maxn];

int main()
{
	for (int i = 2; i < Maxn; i++) if (mn[i] == 0)
		for (int j = i; j < Maxn; j += i)
			if (mn[j] == 0) mn[j] = i;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		cnt[mn[i]]++;
	int oth = n / 2;
	int cur = 0;
	for (int i = 0; i <= n; i++) {
		tot += ll(cnt[i]) * (cnt[i] - 1);
		if (i <= oth) cur += cnt[i];
	}
	int lftout = 0;
	int i;
	for (i = 2; i * i <= n; i++) {
		cur -= cnt[i];
		while (ll(i) * oth > n) { cur -= cnt[oth]; lftout += cnt[oth]; oth--; }
		tot += ll(cnt[i]) * (ll(cur) * 2ll + ll(lftout) * 3ll);
	}
	while (2 * i <= n) {
		while (oth <= i) { oth++; lftout -= cnt[oth]; }
		tot += ll(cnt[i]) * lftout * 3;
		i++;
	}
	for (int i = n; i >= 2; i--) {
		int my = n / i;
		prs[i] = ll(my) * (my - 1) / 2;
		for (int j = i + i; j <= n; j += i)
			prs[i] -= prs[j];
		tot -= prs[i];
	}
	printf("%I64d\n", tot);
	return 0;
}