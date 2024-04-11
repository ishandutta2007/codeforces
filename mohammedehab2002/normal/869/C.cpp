#include <iostream>
#include <algorithm>
using namespace std;
#define mod 998244353
int arr[3],dp[5005][5005];
long long solve(int n,int r)
{
	if (n<r)
	return 0;
	if (r==0)
	return 1;
	if (dp[n][r])
	return dp[n][r];
	return dp[n][r]=(solve(n-1,r)+solve(n-1,r-1))%mod;
}
long long solve2(int n,int r)
{
	long long ans=0,fact=1;
	for (int i=0;i<=r;i++)
	{
		if (i)
		fact=(fact*i)%mod;
		ans=(ans+((solve(n,i)*solve(r,i))%mod)*fact)%mod;
	}
	return ans;
}
int main()
{
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr,arr+3);
	cout << (((solve2(arr[1],arr[0])*solve2(arr[2],arr[0]))%mod)*solve2(arr[2],arr[1]))%mod;
}