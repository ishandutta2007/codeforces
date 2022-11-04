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

int a[1010] , x , y , z , i , n;

int main ()
{
	x = 1;
	y = 1;
	a[1] = 1;
	while (x+y <= 1000)
	{
		z = x+y;
		a[z] = 1;
		x = y;
		y = z;
	}
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] == 1) cout << "O";
		else cout << "o";
	}
	cout << "\n";
	//system("PAUSE");
	return 0;
}