#include<iostream>
using namespace std;
int T,N,M;
int A[1<<20];
int dp[5<<20],ex[5<<20];
bool vis[5<<20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=1;i<=M;i++)dp[i]=i,ex[i]=0,vis[i]=false;
		int mn=M;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			mn=min(mn,A[i]);
			if(!vis[A[i]])
			{
				ex[A[i]]++;
				vis[A[i]]=true;
			}
		}
		int mx=M;
		int ans=M;
		for(int L=M;L>=1;L--)
		{
			if(L>1&&L<=M/L)
			{
				for(int i=L*L;i<=M;i+=L)
				{
					if(vis[i])ex[dp[i]]--;
					dp[i]=min(dp[i],dp[i/L]);
					if(vis[i])ex[dp[i]]++;
				}
			}
			while(!ex[mx])mx--;
			ans=min(ans,mx-min(L,mn));
		}
		cout<<ans<<"\n";
	}
}