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
const int maxn = 1e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n;
double r , a[maxn] , b[maxn] , mx , x;

int main ()
{
	int i , j;
	cin >> n >> r;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		mx = r;
		for (j = 1 ; j < i ; j++)
		{
			if (fabs(a[i]-a[j]) <= 2*r)
			{
				x = 4*r*r-(a[i]-a[j])*(a[i]-a[j]);
				x = sqrt(x);
				mx = max(mx,x+b[j]);
			}
		}
		b[i] = mx;
		printf("%.8lf ",b[i]);
	}
	cout << "\n";
	//system("PAUSE");
	return 0;
}