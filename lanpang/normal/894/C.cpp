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
const int maxn = 4e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[4010] , i , gcd;

int main ()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++) 
	{
		cin >> a[i];
	}
	gcd = a[1];
	for (i = 2 ; i <= n ; i++)
	{
		gcd = __gcd(gcd,a[i]);
	}
	if (gcd != a[1]) cout << "-1\n";
	else
	{
		cout << 2*n-1 << "\n";
		for (i = 1 ; i < n ; i++) cout << a[i] << " " << a[1] << " ";
		cout << a[n] << "\n";
	}
	//system("PAUSE");
	return 0;
}