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

const int N = 105;
char str[N];
int len;
long long n;

void read()
{
	scanf("%s", str);
	len = strlen(str);
	for (int i = 0; i < len - 4; i++)
		str[i] = str[i + 4];
	len -= 4;
	str[len] = 0;
	n = 0;
	for (int i = 0; i < len; i++)
		n = 10 * n + str[i] - '0';
}

void solve()
{
	vector <pair <long long, long long> > v;
	long long x = 1;
	for (int i = 0; i < len; i++)
	{
		x *= 10;
		v.push_back(make_pair(n % x, x) );
	}
	long long cur = 1989;
	for (auto p : v)
	{
		if (cur % p.second <= p.first)
			cur += p.first - (cur % p.second);
		else
			cur += p.second + p.first - (cur % p.second);
		if (p != v.back() )
			cur++;
	}
	printf("%lld\n", cur);
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		read();
		solve();
	}


	return 0;
}