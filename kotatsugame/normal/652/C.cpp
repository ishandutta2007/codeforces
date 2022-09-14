#include<cstdio>
#include<algorithm>
using namespace std;
int N,M;
int P[3<<17],inv[3<<17],R[3<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&P[i]);
		inv[P[i]]=i;
		R[i]=N;
	}
	for(int i=0;i<M;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		if(inv[x]>inv[y])swap(x,y);
		R[inv[x]]=min(R[inv[x]],inv[y]);
	}
	long long ans=0;
	int mn=N;
	for(int i=N;i--;)
	{
		mn=min(mn,R[i]);
		ans+=mn-i;
	}
	printf("%lld\n",ans);
}