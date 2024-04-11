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

int a , b , c , d;

int main ()
{
	cin >> a >> b >> c >> d;
	if (d*2 >= c && c*2 >= d && d < b)
	{
		cout << a*2 << "\n" << b*2 << "\n" << max(c,d) << "\n";
	}
	else
	{
		cout << "-1\n";
	}
	//system("PAUSE");
	return 0;
}