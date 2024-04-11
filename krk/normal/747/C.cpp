#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, q;
int fre[Maxn];

bool Check(int t, int k)
{
	for (int i = 1; i <= n; i++)
		if (fre[i] <= t) k--;
	return k <= 0;
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		int t, k, d; scanf("%d %d %d", &t, &k, &d);
		if (Check(t, k)) {
			int res = 0;
			for (int i = 1; i <= n && k > 0; i++)
				if (fre[i] <= t) { fre[i] = t + d; k--; res += i; }
			printf("%d\n", res);
		} else printf("-1\n");
	}
	return 0;
}