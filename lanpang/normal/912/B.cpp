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

LL a , b , x;

int main ()
{
	cin >> a >> b;
	if (b == 1) cout << a << "\n";
	else
	{
		x = 1;
		while (x-1 < a)
		{
			x *= 2;
		}
		cout << x-1 << "\n";
	}
	//system("PAUSE");
	return 0;
}