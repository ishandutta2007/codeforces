#include<iostream>
#include<algorithm>
using namespace std;
int N,X,Y;
long long dp[10000002];
long long f(int n)
{
	if(dp[n]!=-1)return dp[n];
	if(n%2==0)return dp[n]=f(n/2)+min((long long)Y,(long long)X*(n/2));
	else
	{
		return dp[n]=min(f(n-1),f(n+1))+X;
	}
}
main()
{
	cin>>N>>X>>Y;
	for(int i=1;i<=N+1;i++)dp[i]=-1;
	dp[1]=X;
	cout<<f(N)<<endl;
}