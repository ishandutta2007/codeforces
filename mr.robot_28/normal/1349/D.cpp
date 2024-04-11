#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> a, ans;
int n, m;
const int const1 = 998244353;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t = t * t % const1;
		return t * a % const1;
	}
}
signed main()
{
	cin >> n;
	a.resize(n);
	m = 0;
	ans.resize(3e5 + 5);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		m += a[i];
	}
	int invm = power(m, const1 - 2), invn = power(n -1, const1 - 2);
	for(int i = m; i >= 1; i--)
	{
		int k1 = i * invm % const1 * invn % const1;
		int k2 = (m - i) * invm % const1;
		ans[i] = (ans[i + 1] * k2 + 1) % const1 * power(k1, const1 - 2) % const1;
	}
	for(int i = 1; i <= m; i++)
	{
		ans[i] = (ans[i] + ans[i - 1]) % const1;
	}
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		res = (res + ans[m - a[i]]) % const1;
	}
	res = (res - ans[m] * (n - 1) % const1 + const1) % const1;
	res = res * power(n, const1 - 2) % const1;
	cout << res;
    return 0;
}