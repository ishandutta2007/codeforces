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

LL p , k , a[maxn] , b[maxn];

int main()
{
	LL i , j , x , y;
	cin >> p >> k;
	for (i = 0 ; i <= mod ; i++)
	{
		if (i%2 == 0)
		{
			x = p/k;
			y = p%k;
			a[i] = y;
			b[i] = x;
			p = x;
		}
		else
		{
			x = p/k;
			if (k*x < p) x++;
			y = k*x-p;
			a[i] = y;
			b[i] = k-x;
			p = x;
		}
		if (p == 0) break;
	}
	cout << i+1 << "\n";
	for (j = 0 ; j <= i ; j++) cout << a[j] << " ";
	cout << "\n";
	return 0;
}