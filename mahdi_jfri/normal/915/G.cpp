#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = 2e6 + 20;
const int mod = 1e9 + 7;

int sum[maxn] , dp[maxn];

void ok(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int pw(int a , int b)
{
	if(!b)
		return 1;
	int x = pw(a , b / 2);
	x = 1LL * x * x % mod;
	if(b & 1)
		x = 1LL * x * a % mod;
	return x;
}

int main()
{
	int n , k;
	cin >> n >> k;
	
	int res = 0;
	for(int i = 1; i <= k; i++)
	{
		ok(sum[i] += sum[i - 1]);
		ok(dp[i] = pw(i , n) - sum[i]);
		for(int j = 2; i * j <= k; j++)
		{
			ok(sum[i * j] += dp[i]);
			if(i * j + j <= k)
				ok(sum[(i + 1) * j] -= dp[i]);
		}
		ok(res += (dp[i] ^ i) % mod);
	}
	
	cout << res << endl;
}