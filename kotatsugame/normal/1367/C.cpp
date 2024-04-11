#include<cstdio>
using namespace std;
int T,N,K;
char S[2<<17];
bool ok[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%s",&N,&K,S);
		for(int i=0;i<N;i++)ok[i]=true;
		for(int i=0;i<N;i++)if(S[i]=='1')
		{
			for(int j=i-K;j<=i+K;j++)
			{
				if(0<=j&&j<N)ok[j]=false;
			}
		}
		int ans=0;
		for(int i=0;i<N;i++)if(ok[i])
		{
			ans++;
			for(int j=i;j<=i+K&&j<N;j++)ok[j]=false;
		}
		printf("%d\n",ans);
	}
}