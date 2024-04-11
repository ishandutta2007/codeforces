#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 5e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , b[maxn] , dp[2][maxn] , mi[2][maxn] , top , i , j , k , ans;
map <int,int> mp;

int main()
{
	cin >> n;
	for (int i = 1 ; i <= n ; i++) 
	{
		cin >> a[i];
		mp[a[i]] = 1;
	}
	for (auto i : mp)
	{
		mp[i.first] = ++top;
		b[top] = i.first;
	}
	for (int i = 1 ; i <= n ; i++)
	{
		a[i] = mp[a[i]];
	}
	for (i = 0 ; i <= top ; i++)
	{
		dp[0][i] = mod;
		dp[1][i] = mod;
		mi[0][i] = mod;
		mi[1][i] = mod;
	}
	dp[0][0] = 0;
	ans = mod;
	for (i = 1 ; i <= n ; i++)
	{
		for (j = a[i-1] ; j >= 0 ; j--)
		{
			if (j == a[i-1]) mi[1-i%2][j] = dp[1-i%2][j];
			else mi[1-i%2][j] = min(mi[1-i%2][j+1],dp[1-i%2][j]);
		}
		for (j = 0 ; j <= a[i] ; j++)
		{
			if (j == 0) k = dp[1-i%2][0];
			else
			{
				k += b[j]-b[j-1];
				k = min(k,dp[1-i%2][j]);
			}
			dp[i%2][j] = min(mi[1-i%2][j],k);
			if (j < a[i]) dp[i%2][j]++;
			if (i == n) ans = min(ans,dp[i%2][j]);
		}
		for (j = 0 ; j <= top ; j++)
		{
			dp[1-i%2][j] = mod;
			mi[1-i%2][j] = mod;
		}
	}
	cout << ans << "\n";
	return 0;
}