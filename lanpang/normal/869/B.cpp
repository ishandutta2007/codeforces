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
const int maxn = 2e3+10;
const int maxm = 4e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

long long a , b , c , ans;

int main ()
{
	cin >> a >> b;
	c = b-a;
	if (c > 5) ans = 0;
	else
	{
		a %= 10;
		ans = 1;
		while (c > 0)
		{
			a++;
			ans *= a;
			c--;
		}
		ans %= 10;
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}