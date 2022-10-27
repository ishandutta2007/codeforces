#include <bits/stdc++.h>
                  
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
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
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <int> a(n + 1);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	vector <int> b(n + 1);
	b[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = n; j; j--){
			b[j] = (1LL * a[i] * b[j] - b[j - 1]) % const1;
			b[j] = (b[j] + const1) % const1;
		}
		b[0] = 1LL * a[i] * b[0] % const1;
	}
	int dn = power(n, const1 - 2);
	int now = power(n, k);
	int ans = 0;
	for(int i = 0; i <= min(n, k); i++)
	{
		ans = (ans + 1LL * b[i] * now) % const1;
		now = 1LL * now * (k - i) % const1;
		now = 1LL * now * dn % const1;
	}
	ans = ans * power(dn, k) % const1;
	int mul = 1;
	for(int i = 1; i <= n; i++)
	{
		mul = 1LL * mul * a[i] % const1;
	}
	ans = (mul - ans) % const1;
	ans = (ans + const1) % const1;
	cout << ans;
	return 0;
}