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
const int maxn = 5e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int a , n;

int gcd(int x , int y)
{
	if (y == 0) return x;
	else return gcd(y,x%y);
}

int main ()
{
	cin >> n;
	for (a = n/2 ; a >= 1 ; a--)
	{
		if (gcd(n-a,a) == 1)
		{
			cout << a << " " << n-a << "\n";
			break;
		}
	}
	//system("PAUSE");
	return 0;
}