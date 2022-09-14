#include<cstdio>
using namespace std;
int T,H,G;
int A[1<<21];
int ans[1<<20];
int vis[25];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&H,&G);
		for(int i=1;i<1<<H;i++)scanf("%d",&A[i]);
		int anscnt=0;
		int dep=0;
		for(int i=1;i<1<<H;i++)
		{
			if((i&i-1)==0)dep++;
			while(A[i])
			{
				int viscnt=0;
				int id=i;
				while(id<1<<H&&A[id]!=0)
				{
					vis[viscnt++]=id;
					if(A[id*2]>A[id*2+1])id=id*2;
					else id=id*2+1;
				}
				if(viscnt<=G-dep+1)break;
				ans[anscnt++]=i;
				for(int j=0;j<viscnt-1;j++)A[vis[j]]=A[vis[j+1]];
				A[vis[viscnt-1]]=0;
			}
		}
		long long sum=0;
		for(int i=1;i<1<<G;i++)sum+=A[i];
		printf("%lld\n",sum);
		for(int i=0;i<anscnt;i++)printf("%d%c",ans[i],i+1==anscnt?'\n':' ');
	}
}