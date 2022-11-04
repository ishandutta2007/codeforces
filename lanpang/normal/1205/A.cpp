#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[maxn];

int main()
{
	int i , j;
	cin >> n;
	if (n%2 == 0)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (i = 1 ; i < n*2 ; i += 2)
		a[i] = i;
	i = n+1;
	for (j = 1 ; j <= n ; j++)
	{
		a[i] = j*2;
		i = i+2;
		if (i > n*2) i -= n*2;
	}
	for (i = 1 ; i <= n*2 ; i++)
		printf("%d ",a[i]);
	return 0;
}