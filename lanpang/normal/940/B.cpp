#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL n , k , a , b;

LL jisuan(LL x)
{
	if (x <= 1) return 0;
	if (x < k) return (x-1)*a;
	if (x%k == 0)
	{
		if ((x/k-1)*a+b < (x-1)*a) return b+jisuan(x/k);
		else return (x-1)*a;
	}
	else
	{
		return (x-x/k*k)*a+jisuan(x/k*k);
	}
}

int main()
{
	cin >> n >> k >> a >> b;
	cout << jisuan(n) << "\n";
	return 0;
}