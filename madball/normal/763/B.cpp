#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve()
{
	int n;
	scanf("%d", &n);
	printf("YES");
	for (int i = 0; i < n; ++i)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("\n%d", (a & 1) + 2 * (b & 1) + 1);
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}