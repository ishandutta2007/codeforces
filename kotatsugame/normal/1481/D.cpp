#include<cstdio>
using namespace std;
int T,N,M;
int ans[1<<17];
char S[1010][1010];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)scanf("%s",S[i]);
		int u=-1,v;
		for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
		{
			if(S[i][j]==S[j][i])
			{
				u=i;v=j;
			}
		}
		if(u!=-1)
		{
			for(int i=0;i<=M;i++)ans[i]=i%2==0?u:v;
		}
		else if(M%2==1)
		{
			for(int i=0;i<=M;i++)ans[i]=i%2==0?0:1;
		}
		else
		{
			int v1,v2;
			for(int i=0;i<N;i++)
			{
				int a=-1,b=-1;
				for(int j=0;j<N;j++)if(i!=j)
				{
					if(S[i][j]=='a')a=j;
					else b=j;
				}
				if(a!=-1&&b!=-1)
				{
					u=i;
					v1=a;
					v2=b;
					break;
				}
			}
			if(u==-1)
			{
				puts("NO");
				continue;
			}
			if(M/2%2==0)
			{
				for(int i=0;i<=M/2;i++)ans[i]=i%2?v1:u;
				for(int i=M/2;i<=M;i++)ans[i]=i%2?v2:u;
			}
			else
			{
				for(int i=0;i<=M/2;i++)ans[i]=i%2?u:v1;
				for(int i=M/2;i<=M;i++)ans[i]=i%2?u:v2;
			}
		}
		puts("YES");
		for(int i=0;i<=M;i++)printf("%d%c",ans[i]+1,i==M?10:32);
	}
}