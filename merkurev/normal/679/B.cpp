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



long long cube(long long x)
{
	return x * x * x;
}

long long Ans(long long m)
{
	long long x = 1;
	long long ans = 0;
	while (cube(x + 1) <= m)
		x++;
	while (m > 0)
	{
		if (cube(x) > m)
		{
			x = pow((double) m, 1. / 3.);
			while (cube(x) > m)
				x--;
			while (cube(x + 1) <= m)
				x++;
		}
			
		m -= cube(x);
		ans++;
	}
	return ans;
}

vector <long long> xx;

void init(long long m)
{
	long long sum = 0;
	
	long long cur = 1;
	while (true)
	{
		while (sum + cube(cur) <= m && sum + cube(cur) < cube(cur + 1) )
		{
			xx.push_back(cur);
			sum += cube(cur);
		}
		if (sum + cube(cur) > m) break;
		cur++;
	}
	eprintf("sum = %lld\n", sum);
}

long long getX(long long m)
{
	int ans = 0;
	long long sum = 0;
	for (long long x : xx)
	{
		if (sum + cube(x) <= m)
		{
			sum += cube(x);
			ans++;
		}
		else
			break;
	}
	return ans;
}

long long getAns(long long m, int ans)
{
	if (ans == 0)
		return 0;
//	eprintf("m = %lld, ans = %d\n", m, ans);
	long long x = 1;
	while (cube(x + 1) <= m)
		x++;
	while (getX(m - cube(x) ) != ans - 1)
	{
		m = cube(x) - 1;
		x--;
//		eprintf("m = %lld, x = %lld\n", m, x);
	}
	return cube(x) + getAns(m - cube(x), ans - 1);
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	long long m;
	scanf("%lld", &m);
	init(m);
	int ans = (int) xx.size();
	long long ansm = getAns(m, ans);
	
	printf("%d %lld\n", ans, ansm);

//	if (Ans(ansm) != ans) throw;
	return 0;
}