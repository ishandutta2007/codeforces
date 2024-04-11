#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
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
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int q , x , t , c , r;

int main()
{
	int i , j;
	cin >> q;
	for (i = 1 ; i <= q ; i++)
	{
		cin >> x;
		c = 0;
		t = 0;
		while (x)
		{
			c++;
			if ((x%2) == 0) t = 1;
			x /= 2;
		}
		x = (1<<c)-1;
		if (t == 1) cout << x << "\n";
		else
		{
			r = sqrt(x);
			for (j = 2 ; j <= r ; j++)
				if ((x%j) == 0) break;
			if (j <= r) cout << x/j << "\n";
			else cout << "1\n";
		}
	}
	return 0;
}