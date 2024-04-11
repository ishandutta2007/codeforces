#include<cstdio>
using namespace std;
int T,N,M;
char S[100][66];
bool dn[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)
		{
			scanf("%s",S[i]);
			dn[i]=false;
		}
		long long K=((1LL<<M)-N-1)/2;
		for(int i=0;i<M;i++)
		{
			int cnt=0;
			for(int j=0;j<N;j++)if(!dn[j]&&S[j][i]=='0')cnt++;
			long long U=1LL<<M-i-1;U-=cnt;
			if(K>=U)
			{
				K-=U;
				putchar('1');
				for(int j=0;j<N;j++)if(!dn[j]&&S[j][i]=='0')dn[j]=true;
			}
			else
			{
				putchar('0');
				for(int j=0;j<N;j++)if(!dn[j]&&S[j][i]=='1')dn[j]=true;
			}
		}
		puts("");
	}
}