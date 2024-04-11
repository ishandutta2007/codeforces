#include<iostream>
#include<algorithm>
using namespace std;
int T,N,M;
string S[400];
int fsum[400][401];
int sum[404];
int bd[404];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)cin>>S[i];
		for(int i=0;i<N;i++)
		{
			fsum[i][0]=0;
			for(int j=0;j<M;j++)
			{
				fsum[i][j+1]=fsum[i][j];
				if(S[i][j]=='1')fsum[i][j+1]++;
			}
		}
		int ans=1e9;
		for(int i=0;i<M;i++)for(int j=i+3;j<M;j++)
		{
			sum[0]=0;
			for(int k=0;k<N;k++)
			{
				int now=fsum[k][j]-fsum[k][i+1];
				bd[k]=(j-i-1)-now;
				if(S[k][j]=='0')now++;
				if(S[k][i]=='0')now++;
				sum[k+1]=sum[k]+now;
			}
			int mn=1e9;
			for(int k=0;k<N;k++)
			{
				if(k>=4)
				{
					mn=min(mn,-sum[k-4+1]+bd[k-4]);
				}
				ans=min(ans,sum[k]+bd[k]+mn);
			}
		}
		cout<<ans<<"\n";
	}
}