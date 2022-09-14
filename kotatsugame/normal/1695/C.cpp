#include<iostream>
#include<bitset>
using namespace std;
int T,N,M,A[1000];
bitset<2001>dp[1000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int j=0;j<M;j++)dp[j].reset();
		dp[0][1000]=1;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				cin>>A[j];
				if(A[j]==1)dp[j]<<=1;
				else dp[j]>>=1;
				if(j+1<M)dp[j+1]|=dp[j];
			}
		}
		cout<<(dp[M-1][1000]==1?"YES\n":"NO\n");
	}
}