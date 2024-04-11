#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m , a[maxn] , b[maxn];

bool check(int x)
{
	if (!a[1] || m-a[1] <= x) b[1] = 0;
	else b[1] = a[1];
	for (int i = 2 ; i <= n ; i++)
	{
		if (a[i] < b[i-1]) 
		{
			if (b[i-1]-a[i] <= x) b[i] = b[i-1];
			else return 0;
		}
		else if (a[i] == b[i-1] || m+b[i-1]-a[i] <= x) b[i] = b[i-1];
		else b[i] = a[i];
	}
	return 1;
}

int main()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	int l = 0 , r = m , mid;
	while (l <= r)
	{
		mid = (l+r)/2;
		if (check(mid)) r = mid-1;
		else l = mid+1;
	}
	cout << l << "\n";
	return 0;
}