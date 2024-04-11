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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;
	
const int maxn = (int) 1e6 + 100;
vector <long long> db;
long long divs[maxn];
int ds = 0;

vector <pair <long long, long long> >good;

vector <long long> p;
bool isP[maxn];


long long Good(long long x)
{
	if (x <= 2)
		return -1;
	x--;
	for (int i = 0; i < (int) p.size(); i++)
	{
		if (x % p[i] != 0)
			continue;
		while (x % p[i] == 0)
			x /= p[i];
		if (x != 1)
			return -1;
		return p[i];
	}
	return x;
}

bool usedP[maxn];

long long dp[maxn];

long long getId(long long x)
{
	return lower_bound(divs, divs + ds, x) - divs;
}

long long solve(long long a)
{
	ds = 0;
	db.clear();
	good.clear();

	if (a == 1)
	{
		printf("1\n");
		return 0;
	}

	for (long long i = 1; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			divs[ds++] = i;
			if (i * i != a)
				divs[ds++] = a / i;
		}
	}
	sort(divs, divs + ds);

	for (int i = 0; i < ds; i++)
	{
		long long cur = divs[i];
		long long x = Good(cur);
		if (x == -1)
			continue;
		good.push_back(make_pair(x, cur) );
//		eprintf("%lld %lld\n", x, cur);
	}
	sort(good.begin(), good.end() );

	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	int n = ds;

	int r = 0;
//	eprintf("%d %d\n", (int) good.size(), n);
	for (int l = 0; l < (int) good.size(); l = r)
	{
		r = l + 1;
		while (r < (int) good.size() && good[r].first == good[l].first)
			r++;

		for (int i = n - 1; i >= 0; i--)
		{
			long long cur = dp[i];
			if (cur == 0)
				continue;
			for (int j = l; j < r; j++)
			{
				double A = divs[i] * 1. * good[j].second;
				if (A > 1e14)
					continue;
				long long nx = divs[i] * good[j].second;
				int nid = getId(nx);
				if (nid < n && divs[nid] == nx)
					dp[nid] += cur;
			}
		}
	}
	long long ans = dp[n - 1];
	printf("%lld\n", ans);


	return ans;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	memset(isP, true, sizeof isP);
	for (long long i = 2; i < maxn; i++)
	{
		if (!isP[i] )
			continue;
		p.push_back(i);
		for (long long j = i * 1LL * i; j < maxn; j += i)
			isP[j] = false;
	}

	long long a;
	scanf("%lld", &a);

	solve(a);

	return 0;
}