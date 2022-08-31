#define _CRT_SECURE_NO_WARNINGS

#ifndef ONLINE_JUDGE
#pragma comment(linker, "/STACK:100500500")
#endif

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;


#ifndef ONLINE_JUDGE
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define epritnf(...) 42;
#endif

map <long long, long long> cost;

void incr()
{
	long long a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	while (a != b)
	{
		if (a > b)
		{
			cost[a] += c;
			a /= 2;
		}
		else
		{
			cost[b] += c;
			b /= 2;
		}
	}
}


void solve()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	long long ans = 0;
	while (a != b)
	{
		if (a > b)
		{
			ans += cost[a];
			a /= 2;
		}
		else
		{
			ans += cost[b];
			b /= 2;
		}
	}
	printf("%lld\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("errput.txt", "w", stderr);
#endif

	int q;
	scanf("%d", &q);
	for (int it = 0; it < q; it++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
			incr();
		else
			solve();
	}



	return 0;
}