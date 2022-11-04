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

int x , n , a[20] , i , t;

int main ()
{
	cin >> x;
	n = 1;
	a[1] = 1;
	t = 1;
	while (a[n] <= x)
	{
		t *= 2;
		n++;
		a[n] = t*(t*2-1);
	}
	while (1)
	{
		n--;
		if (x%a[n] == 0) break;
	}
	cout << a[n] << "\n";
	//system("PAUSE");
	return 0;
}