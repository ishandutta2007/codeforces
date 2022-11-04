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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

map <int,LL> f;

LL qp(int n)
{
	if (n == 1) return 2;
	else
	{
		LL p = qp(n/2);
		if (n%2) return p*p%mod*2%mod;
		else return p*p%mod;
	}
}

LL mmp(int x)
{
	if (f[x] > 0) return f[x];
	int i;
	LL ret = qp(x-1)-1;
	for (i = 2 ; i <= sqrt(x) ; i++)
	{
		if (x%i == 0)
		{
			ret -= mmp(i);
			if (i*i != x) ret -= mmp(x/i);
			while (ret < 0) ret += mod;
		}
	} 
	f[x] = ret;
	return ret;
}

int main ()
{
	int x , y;
	cin >> x >> y;
	if (y%x != 0) cout << "0\n";
	else
	{
		if (y/x == 1) cout << "1\n";
		else cout << mmp(y/x) << "\n";
	}
	//system("PAUSE");
	return 0;
}