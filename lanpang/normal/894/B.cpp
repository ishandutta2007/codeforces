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

LL n , m , k , c , d;

LL qp(LL x)
{
	if (x == 0) return 1;
	if (x == 1) return 2;
	LL c = qp(x/2);
	if (x%2) return (2*c*c)%mod;
	else return (c*c)%mod;
}

int main ()
{
	cin >> n >> m >> k;
	if (k == -1 && (n+m)%2 == 1) cout << 0 << "\n";
	else 
	{
		c = (n-1)%(mod-1);
		d = (m-1)%(mod-1);
		cout << qp(c*d) << "\n";
	} 
	//system("PAUSE");
	return 0;
}