#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

typedef long long int int64;

const int N = (int)3e5;

int n;
int64 w[N], h[N];

bool cmp_by_h(int a, int b)
{
	if (h[a] != h[b])
		return h[a] < h[b];
	return a < b;
}

set<int, decltype(&cmp_by_h)> s(&cmp_by_h);

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &w[i], &h[i]);

	int64 sum_w = 0;
	for (int i = 0; i < n; i++)
		sum_w += w[i];

	for (int i = 0; i < n; i++)
		s.insert(i);

	for (int i = 0; i < n; i++)
	{
		s.erase(i);
		int64 max_h = h[*s.rbegin()];
		s.insert(i);
		printf("%lld ", max_h * (sum_w - w[i]));
	}

	return 0;
}