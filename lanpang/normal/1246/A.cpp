#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

LL n , p;

int chk(LL x)
{
	int ret = 0;
	while (x)
	{
		ret += x%2;
		x /= 2;
	}
	return ret;
}

int main()
{
	int i , j;
	cin >> n >> p;
	for (i = 1 ; i <= 1000000 && n-p*i > 0 ; i++)
		if (chk(n-p*i) <= i && i <= n-p*i)
		{
			cout << i << "\n";
			return 0;
		}
	cout << "-1\n";
	return 0;
}