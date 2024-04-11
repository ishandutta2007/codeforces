#include<bits/stdc++.h>
using namespace std;
#define int long long
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
		return a * t % const1;
	}
}
signed main() {
  	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	cout.tie(NULL);
  	int n;
  	cin >> n;
  	for(int i = 1; i <= n; i++)
  	{
  		int ans = 0;
  		if(i < n - 1)
  		{
  			ans += 810 * power(10, n - i - 2) * (n - i - 1) % const1;
  		}
  		if(i < n)
  		{
  			ans += 90 * power(10, n - i - 1) * 2 % const1;
  		}
  		if(i == n)
  		{
  			ans += 10;
  		}
  		cout << ans  %const1 << " ";
  	}
    return 0;
}