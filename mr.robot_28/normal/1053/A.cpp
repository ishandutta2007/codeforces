#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	if((2 * n * m) % k != 0)
	{
		cout << "NO\n";
		return 0;
	}
	bool fl1 = false;
	if(k % 2 == 0)
	{
		fl1 = true;
		k = k / 2;
	}
	int g = __gcd(k, n);
	int k1 = k / g;
	int a = n / g;
	int b = m / k1;
	if(!fl1)
	{
		if(a * 2 <= n)
		{
			a *= 2;
		}
		else
		{
			b *= 2;
		}
	}
	cout << "YES\n";
	cout << "0 0\n";
	cout << a << " 0\n";
	cout << "0 " << b;
	return 0;
}