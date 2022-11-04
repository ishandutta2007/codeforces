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

int n , a , b , c , d , e , i;

int main ()
{
	cin >> n >> a >> b;
	if (a == 0 && b == 0) cout << "NO\n";
	else
	{
		if (a == 0 || b == 0)
		{
			if (a == 0) 
			{
				if (n%b == 0) cout << "YES\n0 " << n/b << "\n";
				else cout << "NO\n";
			}
			else
			{
				if (n%a == 0) cout << "YES\n" << n/a << " 0\n";
				else cout << "NO\n";
			}
		}
		else
		{
			e = 0;
			for (i = 0 ; i <= n/a ; i++)
			{
				if ((n-i*a) % b == 0)
				{
					cout << "YES\n" << i << " " << (n-i*a)/b << "\n"; 
					e = 1;
					break;
				}
			}
			if (!e) cout << "NO\n";
		}
	} 
	//system("PAUSE");
	return 0;
}