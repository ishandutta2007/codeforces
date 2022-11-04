#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL n;

LL jisuan(LL x)
{
	LL s = n , ss = 0;
	while (s > 0)
	{
		ss += min(x,s);
		s -= min(x,s);
		s -= s/10;
	}
	return ss;
}

int main()
{
	LL i , j;
	cin >> n;
	for (i = max((LL)1,(LL)((double)n/(double)25.471590853)) ; ; i++)
	{
		if (jisuan(i) >= (n+1)/2)
		{
			cout << i << "\n";
			break;
		}
	}
	return 0;
}