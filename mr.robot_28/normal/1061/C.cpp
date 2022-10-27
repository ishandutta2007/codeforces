#include<bits/stdc++.h>
using namespace std;
const int CONST = 1e9 + 7;
int main(){
	#define int long long
	int n;
	cin >> n;
	vector <int> dp(n + 1, 0);
	int sum = 0;
	for(int k = 0; k < n; k++)
	{
		int a;
		cin >> a;
		if(a <= n)
		{
			dp[a] = (dp[a] + dp[a - 1]) % CONST;
		}
		for(int i = 2; i <= sqrt(a); i++)
		{
			if(a % i == 0 && a / i <= n)
			{
				dp[a / i] = (dp[a / i] + dp[a / i - 1]) % CONST;
			}
		}
		for(int i = sqrt(a); i >= 2; i--)
		{
			if(a % i == 0 && i <= n && i * i != a)
			{
				dp[i] = (dp[i] + dp[i - 1]) % CONST;
			}
		}
		dp[1] = (dp[1] + 1) % CONST;
	}
	for(int i = 1; i <= n; i++)
	{
		sum = (sum + dp[i]) % CONST;
	}
	cout << sum;
	return 0;
}