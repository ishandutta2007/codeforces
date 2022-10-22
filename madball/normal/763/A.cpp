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

pair<int, int> edges[100100];
int must1 = -1;
int must2 = -1;
int c[100100];

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a; --b;
		edges[i].first = a;
		edges[i].second = b;
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", &c[i]);
	for (int i = 0; i < n - 1; ++i)
		if (c[edges[i].first] != c[edges[i].second])
			{
				if (must1 == -1)
				{
					must1 = edges[i].first;
					must2 = edges[i].second;
				}
				else
				{
					if (must1 != edges[i].first && must1 != edges[i].second)
						must1 = -2;
					if (must2 != edges[i].first && must2 != edges[i].second)
						must2 = -2;
					if (must1 + must2 == -4)
					{
						printf("NO");
						return;
					}
				}
			}
	if (must1 == -1)
		printf("YES\n1");
	else if (must1 == -2)
		printf("YES\n%d", must2 + 1);
	else
		printf("YES\n%d", must1 + 1);
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