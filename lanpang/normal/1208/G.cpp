#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , phi[maxn] , k;
LL ans;

int main()
{
	int i , j;
	cin >> n >> k;
	if (k == 1)
	{
		cout << "3\n";
		return 0;
	}
	for (i = 2 ; i <= n ; i++)
		phi[i] = i;
	for (i = 2 ; i <= n ; i++)
		if (phi[i] == i)
		{
			phi[i] = i-1;
			for (j = i*2 ; j <= n ; j += i)
				phi[j] = phi[j]/i*(i-1);			
		}
	sort(phi+3,phi+n+1);
	for (i = 3 ; i <= k+2 ; i++)
		ans += phi[i];
	cout << ans+2 << "\n";
	return 0;
}