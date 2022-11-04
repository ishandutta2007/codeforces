#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[maxn] , b[maxn] , ma , gg;

int main()
{
	int i , j , k;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&b[i]);
	j = n;
	while (j >= 2 && b[j] == b[j-1]+1 && b[j-1]) j--;
	if (b[j] == 1)
	{
		for (i = 1 ; i < j ; i++)
			if (b[i] && i >= b[i]-b[n])
			{
				gg = 1;
				break;
			}
		if (!gg)
		{
			cout << n-b[n] << "\n";
			return 0;
		}
	}
	for (i = 1 ; i <= n ; i++)
		if (b[i]) ma = max(ma,i-b[i]+1);
	cout << ma+n << "\n";
	return 0;
}