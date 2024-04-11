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

const long long INF = (long long) 1e18;
const int N = (int) 1e6 + 100;
int a[N];

int n, d, b;

long long solve(int p)
{
	long long dpOpen = 0, dpClosed = 0, dpNotOpen = 0;

	for (int i = 0; i < n; i++)
	{
		int cur = 2;
		if (a[i] % p == 0)
			cur = 0;
		else if ( (a[i] + 1) % p == 0 || (a[i] - 1) % p == 0)
			cur = 1;

//		eprintf("i = %d, cur = %d\n", i, cur);

		long long ndpOpen = min(dpOpen, dpNotOpen) + d;
		long long ndpClosed = min(dpClosed, dpOpen);
		long long ndpNotOpen = dpNotOpen;

		if (i == 0)
			ndpOpen = INF;

		if (cur == 1)
		{
			ndpNotOpen += b;
			ndpClosed += b;
		}
		else if (cur == 2)
		{
			ndpClosed = INF;
			ndpNotOpen = INF;
		}

		dpOpen = ndpOpen;
		dpClosed = ndpClosed;
		dpNotOpen = ndpNotOpen;
	
//		eprintf("%lld %lld %lld\n", dpOpen, dpClosed, dpNotOpen);
	}

	long long ans = min({dpOpen, dpClosed, dpNotOpen});
//	eprintf("p = %d, ans = %lld\n", p, ans);
//	eprintf("\n");
	return ans;
}

void addP(int x, vector <int> &p)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i != 0)
			continue;
		p.push_back(i);
		while (x % i == 0)
			x /= i;
	}
	if (x != 1)
		p.push_back(x);
}

long long solve()
{
	long long ans = INF;
	vector <int> p;
	long long x = a[0];
	for (int sh = -1; sh <= 1; sh++)
		addP(x + sh, p);
	sort(p.begin(), p.end() );
	p.resize(unique(p.begin(), p.end() ) - p.begin() );
	for (int pp : p)
		ans = min(ans, solve(pp) );
	return ans;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d%d", &n, &d, &b);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );

	long long ans1 = solve();
	reverse(a, a + n);
	long long ans2 = solve();
	printf("%lld\n", min(ans1, ans2) );


	return 0;
}