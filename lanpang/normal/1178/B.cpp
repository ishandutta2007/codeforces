#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

LL s[maxn] , b[maxn] , ans;
int n;
char a[maxn]; 

int main()
{
	int i , j;
	cin >> a+1;
	n = strlen(a+1);
	for (i = 2 ; i <= n ; i++)
	{
		s[i] = s[i-1];
		if (a[i] == 'v' && a[i-1] == 'v') s[i]++;
	}
	for (i = n-1 ; i >= 1 ; i--)
	{
		b[i] = b[i+1];
		if (a[i] == 'v' && a[i+1] == 'v') b[i]++;
	}
	for (i = 2 ; i < n ; i++)
		if (a[i] == 'o') ans += s[i-1]*b[i+1];
	cout << ans << "\n";
	return 0;
}