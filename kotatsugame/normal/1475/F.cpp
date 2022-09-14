#include<cstdio>
using namespace std;
int T,N;
int A[1010][1010];
char S[1010];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d\n",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%s\n",S);
			for(int j=0;j<N;j++)A[i][j]=S[j]-'0';
		}
		scanf("\n");
		for(int i=0;i<N;i++)
		{
			scanf("%s\n",S);
			for(int j=0;j<N;j++)A[i][j]^=S[j]-'0';
		}
		for(int j=0;j<N;j++)if(A[0][j]==1)
		{
			for(int k=0;k<N;k++)A[k][j]^=1;
		}
		bool ok=true;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)if(A[i][0]!=A[i][j])ok=false;
		}
		puts(ok?"YES":"NO");
	}
}