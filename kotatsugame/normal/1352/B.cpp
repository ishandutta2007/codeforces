#include<cstdio>
using namespace std;
int T,N,K;
int ans[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		if(K%2==0)
		{
			if(N%2==1||N<K)
			{
				puts("NO");
				continue;
			}
			else
			{
				for(int i=0;i<K-1;i++)ans[i]=1;
				ans[K-1]=N-(K-1);
			}
		}
		else
		{
			if(N%2==1)
			{
				if(N<K)
				{
					puts("NO");
					continue;
				}
				for(int i=0;i<K-1;i++)ans[i]=1;
				ans[K-1]=N-(K-1);
			}
			else
			{
				if(N<K*2)
				{
					puts("NO");
					continue;
				}
				for(int i=0;i<K-1;i++)ans[i]=2;
				ans[K-1]=N-(K-1)*2;
			}
		}
		puts("YES");
		for(int i=0;i<K;i++)printf("%d%c",ans[i],i+1==K?10:32);
	}
}