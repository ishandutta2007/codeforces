#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int maxn = (int) 1e6 + 100;
int a[maxn];
int len[maxn];
long long all = 0;


int getLen(int n, long long x)
{
	long long sum = 0;
	int pos = 0;
	len[0] = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
		{
			sum -= a[i - 1];
			len[i] = len[i - 1] - 1;
		}

		while (sum + a[pos] <= x)
		{
			sum += a[pos];
			len[i]++;
			pos++;
			if (pos == n)
				pos = 0;
		}
//		eprintf("%d ", len[i] );
	}
}

int solveFS(int n, long long x, int s)
{
	if (s >= n)
		s -= n;

	int ans = 0;
	int pos = s;
	int sumLen = 0;

	while (sumLen < n)
	{
		sumLen += len[pos];
		pos += len[pos];
		ans++;
		if (pos >= n)
			pos -= n;
	}
	return ans;
}

void solve(int n, long long x)
{
	getLen(n, x);

	int minLen = len[0];
	int minS = 0;
	
	for (int i = 0; i < n; i++)
		if (len[i] < minLen)
		{
			minLen = len[i];
			minS = i;
		}
	
	int ans = n;

	for (int i = 0; i <= len[minS]; i++)
		ans = min(ans, solveFS(n, x, minS + i) );
	
	printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		all += a[i];
	}
	
	for (int i = 0; i < q; i++)
	{
		long long x;
		scanf("%lld", &x);
		if (x >= all)
			printf("1\n");
		else
			solve(n, x);
	}

	return 0;
}