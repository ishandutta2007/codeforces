#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod = 998244353;
int test, n, sum, cur, num[1111111];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			num[j]++;
		}
	}
	sum = 1;
	for (int i = 1; i <= n; i++)
	{
		cur = (sum + num[i] - 1) % mod;
		sum = (sum + cur) % mod;
	}
	printf("%d\n", (cur + mod) % mod);
	return Accepted;
}