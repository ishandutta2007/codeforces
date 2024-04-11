#include<cstdio>
#include<algorithm>
using namespace std;
int N,M;
char S[1010][1010];
int L[1010][1010],R[1010][1010],U[1010][1010],D[1010][1010];
int X[1<<20],Y[1<<20],r[1<<20],sz;
int C[1010][1010];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%s",S[i]);
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)
	{
		if(S[i][j]=='*')
		{
			U[i][j]=i==0?1:U[i-1][j]+1;
			L[i][j]=j==0?1:L[i][j-1]+1;
		}
	}
	for(int i=N;i--;)for(int j=M;j--;)
	{
		if(S[i][j]=='*')
		{
			D[i][j]=D[i+1][j]+1;
			R[i][j]=R[i][j+1]+1;
		}
	}
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)
	{
		int T=min(min(U[i][j],L[i][j]),min(D[i][j],R[i][j]));
		if(T>=2)
		{
			X[sz]=i;
			Y[sz]=j;
			r[sz]=T-1;
			C[i-r[sz]][j]++;
			C[i-r[sz]][j+1]--;
			C[i+r[sz]+1][j]--;
			C[i+r[sz]+1][j+1]++;
			C[i][j-r[sz]]++;
			C[i+1][j-r[sz]]--;
			C[i][j+r[sz]+1]--;
			C[i+1][j+r[sz]+1]++;
			sz++;
		}
	}
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)
	{
		C[i][j]+=(i?C[i-1][j]:0)+(j?C[i][j-1]:0)-(i&&j?C[i-1][j-1]:0);
		if(S[i][j]=='*'&&C[i][j]==0)
		{
			puts("-1");
			return 0;
		}
	}
	printf("%d\n",sz);
	for(int i=0;i<sz;i++)printf("%d %d %d\n",X[i]+1,Y[i]+1,r[i]);
}