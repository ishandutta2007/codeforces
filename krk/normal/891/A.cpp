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

const int Maxn = 2005;

int n;
int a[Maxn];
int best = Maxn;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt += a[i] > 1;
	}
	for (int i = 0; i < n; i++) {
		int g = 0;
		for (int j = i; j < n; j++) {
			g = gcd(g, a[j]);
			if (g == 1) best = min(best, j - i + 1);
		}
	}
	if (best >= Maxn) printf("-1\n");
	else if (best == 1) printf("%d\n", cnt);
	else printf("%d\n", cnt + best - 2);
	return 0;
}