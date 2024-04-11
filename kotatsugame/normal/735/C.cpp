#include<iostream>
using namespace std;
typedef long long int ll;

int main()
{
	ll n;cin>>n;
	ll dp[100];
	dp[0]=1;dp[1]=2;
	for(int i=2;i<94;i++)dp[i]=dp[i-1]+dp[i-2];
	int ans;
	for(ans=0;dp[ans]<=n;ans++);
	cout<<ans-1<<endl;
	return 0;
}