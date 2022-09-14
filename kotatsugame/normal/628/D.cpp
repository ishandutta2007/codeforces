#include<iostream>
using namespace std;
int M,D;
string A,B;
const long long mod=1e9+7;
int dp[2][4][2000];
main()
{
	cin>>M>>D>>A>>B;
	int now=0;
	for(int j=0;j<4;j++)for(int k=0;k<M;k++)dp[now][j][k]=0;
	dp[now][0][0]=1;
	for(int i=0;i<A.size();i++)
	{
		int nxt=1-now;
		for(int j=0;j<4;j++)for(int k=0;k<M;k++)dp[nxt][j][k]=0;
		for(int j=0;j<4;j++)for(int k=0;k<M;k++)
		{
			int L=A[i]-'0',R=B[i]-'0';
			if(j&1)L=0;
			if(j&2)R=9;
			for(int d=L;d<=R;d++)
			{
				if(i%2==1?d!=D:d==D)continue;
				(dp[nxt][j|(d<R)*2+(d>L)][(k*10+d)%M]+=dp[now][j][k])%=mod;
			}
		}
		now=nxt;
	}
	int ans=0;
	for(int j=0;j<4;j++)(ans+=dp[now][j][0])%=mod;
	cout<<ans<<endl;
}