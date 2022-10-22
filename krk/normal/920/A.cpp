#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 205;

int t;
int n, k;
int mn[Maxn];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		fill(mn, mn + Maxn, Maxn * Maxn);
		for (int i = 0; i < k; i++) {
			int x; scanf("%d", &x);
			for (int j = 1; j <= n; j++)
				mn[j] = min(mn[j], abs(j - x) + 1);
		}
		int mx = 0;
		for (int j = 1; j <= n; j++)
			mx = max(mx, mn[j]);
		printf("%d\n", mx);
	}
	return 0;
}