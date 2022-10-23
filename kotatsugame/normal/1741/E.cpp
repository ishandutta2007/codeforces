#include<iostream>
using namespace std;
int N,B[2<<17];
bool dp[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>B[i];
		for(int i=0;i<=N;i++)dp[i]=false;
		dp[0]=true;
		for(int i=0;i<N;i++)
		{
			if(i-B[i]>=0&&dp[i-B[i]])dp[i+1]=true;
			if(dp[i]&&i+B[i]+1<=N)dp[i+B[i]+1]=true;
		}
		cout<<(dp[N]?"YES\n":"NO\n");
	}
}