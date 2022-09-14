#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
string S[2];
int L[2<<17][4],R[2<<17][4];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S[0]>>S[1];
		for(int i=0;i<=N;i++)for(int j=0;j<4;j++)
		{
			L[i][j]=R[i][j]=1e9;
		}
		L[0][0]=0;
		for(int i=0;i<N;i++)
		{
			int now=(S[0][i]=='*')+(S[1][i]=='*')*2;
			for(int j=0;j<4;j++)
			{
				L[i+1][j|now]=min(L[i+1][j|now],L[i][j]+(j&1)+(j>>1&1));
			}
			L[i+1][1]=min(L[i+1][1],L[i+1][3]+1);
			L[i+1][2]=min(L[i+1][2],L[i+1][3]+1);
		}
		R[N][0]=0;
		for(int i=N;i--;)
		{
			int now=(S[0][i]=='*')+(S[1][i]=='*')*2;
			for(int j=0;j<4;j++)
			{
				R[i][j|now]=min(R[i][j|now],R[i+1][j]+(j&1)+(j>>1&1));
			}
			R[i][1]=min(R[i][1],R[i][3]+1);
			R[i][2]=min(R[i][2],R[i][3]+1);
		}
		int ans=1e9;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<4;j++)for(int k=0;k<4;k++)
			{
				int now=L[i+1][j]+R[i][k];
				if((j|k)==3)now++;
				ans=min(ans,now);
			}
		}
		cout<<ans<<"\n";
	}
}