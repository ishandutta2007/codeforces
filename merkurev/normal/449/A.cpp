#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;


vector <int> getDivs(int x)
{
	vector <int> ans;
	for (int i = 1; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			ans.push_back(i);
			ans.push_back(x / i);
		}
	}
	return ans;
}

long long solve(long long n, long long m, long long k)
{
	long long ans = 0;
	vector <int> v = getDivs(n);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] - 1 > k)
			continue;
		long long cur = (n / v[i] ) * ( m / (k - v[i] + 2) );
		ans = max(ans, cur);
	}
	return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long n, m, k;
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	if (k > (n - 1) + (m - 1) )
	{
		printf("-1\n");
		return 0;
	}
	long long ans = max(solve(n, m, k), solve(m, n, k) );
	printf("%I64d\n", ans);


	return 0;
}