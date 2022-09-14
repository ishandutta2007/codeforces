#include<iostream>
#include<algorithm>
using namespace std;
int T,N,A,B;
string X;
bool dp[41][40][40][81];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>A>>B>>X;
		for(int i=0;i<A;i++)for(int j=0;j<B;j++)for(int c=-N;c<=N;c++)dp[0][i][j][c+N]=false;
		dp[0][0][0][N]=true;
		for(int i=0;i<N;i++)
		{
			int now=X[i]-'0';
			for(int j=0;j<A;j++)for(int k=0;k<B;k++)for(int l=0;l<=2*N;l++)dp[i+1][j][k][l]=false;
			for(int j=0;j<A;j++)for(int k=0;k<B;k++)for(int l=0;l<=2*N;l++)if(dp[i][j][k][l])
			{
				if(l<2*N)dp[i+1][(j*10+now)%A][k][l+1]=true;
				if(l>0)dp[i+1][j][(k*10+now)%B][l-1]=true;
			}
		}
		int d=-1;
		for(int i=1;i<2*N;i++)if(dp[N][0][0][i])
		{
			int x=abs(N-d),y=abs(N-i);
			if(x>y)d=i;
		}
		if(d==-1)cout<<"-1\n";
		else
		{
			string ans(N,'_');
			int j=0,k=0,l=d;
			for(int i=N;i--;)
			{
				int now=X[i]-'0';
				bool fn=false;
				if(!fn&&l>0)
				{
					for(int nj=0;nj<A;nj++)if((nj*10+now)%A==j&&dp[i][nj][k][l-1])
					{
						j=nj;
						l--;
						ans[i]='R';
						fn=true;
						break;
					}
				}
				if(!fn&&l<2*N)
				{
					for(int nk=0;nk<B;nk++)if((nk*10+now)%B==k&&dp[i][j][nk][l+1])
					{
						k=nk;
						l++;
						ans[i]='B';
						fn=true;
						break;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
}