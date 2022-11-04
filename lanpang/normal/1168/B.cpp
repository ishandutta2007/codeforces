#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , b[maxn] , mi;
LL ans;
char a[maxn];

int main()
{
	int i , j;
	scanf("%s",a+1);
	n = strlen(a+1);
	for (i = 1 ; i <= n ; i++)
		b[i] = n+1;
	for (i = 2 ; i <= n-1 ; i++)
	{
		for (j = 1 ; j <= min(n-i,i-1) ; j++)
			if (a[i] == a[i+j] && a[i] == a[i-j]) break;
		if (1 <= i-j && i+j <= n) b[i-j] = min(b[i-j],i+j);
	}
	mi = n+1;
	for (i = n ; i >= 1 ; i--)
	{
		mi = min(mi,b[i]);
		ans += n-mi+1;
	}
	cout << ans << "\n";
	return 0;
}