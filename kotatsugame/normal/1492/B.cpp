#include<cstdio>
using namespace std;
int T,N;
int P[1<<17],Q[1<<17];
int inv[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&P[i]);
			inv[--P[i]]=i;
		}
		int pre=N,sz=0;
		for(int i=N;i--;)
		{
			if(inv[i]<pre)
			{
				for(int j=inv[i];j<pre;j++)
				{
					Q[sz++]=P[j];
				}
				pre=inv[i];
			}
		}
		for(int i=0;i<N;i++)printf("%d%c",Q[i]+1,i+1==N?10:32);
	}
}