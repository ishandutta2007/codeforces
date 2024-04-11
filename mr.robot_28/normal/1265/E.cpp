#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
int inv(int a)
{
	int r = 1, k = MOD - 2, t = a;
	while(k)
	{
		if(k & 1)
		{
			r = (t * r) % MOD;
		}
		t = (t * t) % MOD;
		k = k / 2;
	}
	return r;
}
signed main()
{
	int n;
	cin >> n;
	vector <int> p(n);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i] = (p[i] * inv(100)) % MOD;
	}
	int a = 1, b = 0;
	for(int i = 0; i < n; i++)
	{
		a = a * inv(p[i]) % MOD;
		b = b * inv(p[i]) % MOD;
		a = (a + (p[i] - 1) * inv(p[i])) % MOD;
		b = (b - inv(p[i]) + MOD) % MOD;
	}
	cout << (MOD - b)% MOD << "\n";
    return 0;
}