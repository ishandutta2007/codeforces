#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
char S[2020][2020];
int L[2020][10],R[2020][10];
int U[2020][10],D[2020][10];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d\n",&N);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<10;j++)
			{
				L[i][j]=R[i][j]=U[i][j]=D[i][j]=-1;
			}
		}
		for(int i=0;i<N;i++)
		{
			scanf("%s\n",S[i]);
			for(int j=0;j<N;j++)
			{
				int d=S[i][j]-'0';
				R[i][d]=j;
				if(L[i][d]==-1)L[i][d]=j;
				if(U[j][d]==-1)U[j][d]=i;
				D[j][d]=i;
			}
		}
		for(int d=0;d<10;d++)
		{
			int ans=0;
			for(int i=0;i<N;i++)
			{
				if(L[i][d]!=-1)
				{
					ans=max(ans,(R[i][d]-L[i][d])*max(N-i-1,i));
				}
				if(U[i][d]!=-1)
				{
					ans=max(ans,(D[i][d]-U[i][d])*max(N-i-1,i));
				}
			}
			{
				int rM=0;
				for(int i=0;i<N;i++)rM=max(rM,R[i][d]);
				for(int i=0;i<N;i++)if(L[i][d]!=-1)ans=max(ans,max(N-i-1,i)*(rM-L[i][d]));
			}
			{
				int lM=5000;
				for(int i=0;i<N;i++)if(L[i][d]!=-1)lM=min(lM,L[i][d]);
				for(int i=0;i<N;i++)if(R[i][d]!=-1)ans=max(ans,max(N-i-1,i)*(R[i][d]-lM));
			}
			{
				int dM=0;
				for(int i=0;i<N;i++)dM=max(dM,D[i][d]);
				for(int i=0;i<N;i++)if(U[i][d]!=-1)ans=max(ans,max(N-i-1,i)*(dM-U[i][d]));
			}
			{
				int uM=5000;
				for(int i=0;i<N;i++)if(U[i][d]!=-1)uM=min(uM,U[i][d]);
				for(int i=0;i<N;i++)if(D[i][d]!=-1)ans=max(ans,max(N-i-1,i)*(D[i][d]-uM));
			}
			printf("%d%c",ans,d==9?'\n':' ');
		}
	}
}