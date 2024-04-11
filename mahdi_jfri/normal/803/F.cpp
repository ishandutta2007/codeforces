#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const ll mod = 1e9 + 7;
ll dp[maxn] , t[maxn] , a[maxn] , pw[maxn];
int main()
{
	pw[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = (pw[i - 1] * 2) % mod;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] , t[a[i]]++;
	for(int i = maxn - 1; i >= 1; i--)
	{
		ll k = 0;
		for(int j = i; j < maxn; j += i)
			k += t[j];
//		cout << k << " ";
		dp[i] = pw[k] - 1;
		for(int j = 2 * i; j < maxn; j += i)
			dp[i] -= dp[j];
		dp[i] %= mod;
		dp[i] += mod;
		dp[i] %= mod;
//		cout << i << " " << dp[i] << endl;
	}
	cout << dp[1] << endl;
}