#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int LIM = 1005;
const int INF = 1e+9 + 7;
const ld EPS = 1e-7;

#ifdef LOCAL
#define STRESS
#endif

int w[LIM];
int h[LIM];

void solve()
{
	int n;
#ifdef STRESS
	n = 1000;
#else
	scanf("%d", &n);
#endif
	for (int i = 0; i < n; ++i)
	{
#ifdef STRESS
		w[i] = 1;
		h[i] = 1000;
#else
		scanf("%d %d", &w[i], &h[i]);
#endif
	}
	int res = INF;
	for (int resh = 1; resh <= 1000; ++resh)
	{
		int resw = 0;
		int i;
		for (i = 0; i < n; ++i)
		{
			if (w[i] > resh && h[i] > resh)
				break;
			else if (w[i] > resh)
				resw += w[i];
			else if (h[i] > resh)
				resw += h[i];
			else
				resw += min(w[i], h[i]);
		}
		if (i < n)
			continue;
		res = min(res, resw * resh);
	}
	printf("%d", res);
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