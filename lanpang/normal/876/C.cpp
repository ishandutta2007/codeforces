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

int n , l , a[100]; 

int check1(int x)
{
	int ret = x;
	while (x > 0)
	{
		ret += x%10;
		x /= 10;
	}
	return n==ret;
} 

int main ()
{
	int i , j;
	cin >> n;
	for (i = max(n-100,0) ; i <= n ; i++)
	{
		if (check1(i))
		{
			l++;
			a[l] = i;
		}
	}
	cout << l << "\n";
	for (i = 1 ; i <= l ; i++)
		cout << a[i] << " ";
	cout << "\n";
	//system("PAUSE");
	return 0;
}