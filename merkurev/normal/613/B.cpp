#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 1e5 + 100;
pair <int, int> a[N];

int n, A, cf, cm;
long long m;

bool cmp(const pair <int, int> &aa, const pair<int, int> &b)
{
	return aa.second < b.second;
}

void printAns()
{
	long long ans = 0;
	int mn = a[0].first;
	for (int i = 0; i < n; i++)
	{
		if (a[i].first == A)
			ans += cf;
		mn = min(mn, a[i].first);
	}
	ans += cm * 1LL * mn; 
	sort(a, a + n, cmp);
	printf("%lld\n", ans);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i].first);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d%d%d%lld", &n, &A, &cf, &cm, &m);


	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = make_pair(x, i);
	}
	sort(a, a + n);

	int cnt = 0;
	long long cost = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		cnt++;
		cost += A - a[i].first;
	}

	if (cost <= m)
	{
		for (int i = 0; i < n; i++)
			a[i].first = A;
		printAns();
		return 0;
	}

	long long bst = 0;
	int _cnt = 0;
	int _mn = 0;

	int mn = 0;
	int x = 0;

	for (int i = 0; i < n; i++)
	{
		cnt--;
		cost -= A - a[i].first;

		while (x + cnt != n && (a[x].first - mn) * 1LL * x + cost <= m)
		{
			cost += (a[x].first - mn) * 1LL * x;
			mn = a[x].first;
			x++;
		}

		if (cost > m)
			continue;
		long long add = (m - cost) / x;
		mn += add;
		cost += add * x;

		long long curAns = cf * 1LL * cnt + cm * 1LL * mn;

		if (curAns > bst)
		{
			bst = curAns;
			_mn = mn;
			_cnt = cnt;
		}
	}

	for (int i = 0; i < n; i++)
	{
		a[i].first = max(a[i].first, _mn);
	}
	for (int i = 0; i < _cnt; i++)
		a[n - i - 1].first = A;

	printAns();


	return 0;
}