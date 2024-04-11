#include <bits/stdc++.h>
#define mod 10007
using namespace std;
int n,a[10000010];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) 
		scanf("%d",a+i);
	sort(a + 1, a + 1 + n);
	int ans = 0; 
	for(int i = 1; i <= n; i ++)
	{
		ans += (a[i] % mod) * (a[n + 1 - i] % mod) % mod;
		ans %= mod;
	}
	cout << (ans % mod + mod) % mod << "\n";
	return 0;
}