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

LL n , i , j , x , t , p , g , h , m , c;

int main()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> x;
		if (x == 0) cout << "1 1\n";
		else
		{
			c = 0;
			t = sqrt(x);
			for (j = 1 ; j <= t ; j++)
			{
				p = x-j*j;
				if (p%2) continue;
				else
				{
					p /= 2;
					if (p%j == 0)
					{
						g = p/j;
						h = g+j;
						if (g == 0) continue;
						m = h/g;
						if (h/m == g)
						{
							cout << h << " " << m << "\n";
							c = 1;
							break;
						}
					}
				}
			}
			if (c == 0) cout << "-1\n";
		}
	}
	return 0;
}