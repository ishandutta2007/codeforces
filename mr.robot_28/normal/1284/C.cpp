#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n, m;
	cin >> n >> m;
	vector <int> fact(n + 1);
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		fact[i] = fact[i - 1] * i % m;
	}
	int ans = 0;
	for(int len = 1; len <= n; len++)
	{
		int anslen = (((n - len + 1) * fact[len] % m) * fact[n - len] % m) * (n - len + 1); 
		ans = (ans + anslen) % m;
	}
	cout << ans;
	return 0;
}