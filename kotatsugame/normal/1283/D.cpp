#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
int X[2<<17];
int Y[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&X[i]);
	}
	sort(X,X+N);
	int kL=0,kR=3e5;
	while(kR-kL>1)
	{
		int kM=(kL+kR)/2;
		long long now=2*kM;
		for(int i=1;i<N;i++)
		{
			now+=min(X[i]-X[i-1]-1,2*kM);
		}
		if(now>=M)kR=kM;
		else kL=kM;
	}
	int id=0;
	long long ans=0;
	int K=kR-1;
	for(int j=X[0]-K;j<X[0];j++)
	{
		Y[id++]=j;
		ans+=abs(X[0]-j);
	}
	for(int j=X[N-1]+1;j<=X[N-1]+K;j++)
	{
		Y[id++]=j;
		ans+=abs(X[N-1]-j);
	}
	for(int i=1;i<N;i++)
	{
		if(X[i]-X[i-1]-1>=2*K)
		{
			for(int j=1;j<=K;j++)
			{
				Y[id++]=X[i-1]+j;
				ans+=j;
				Y[id++]=X[i]-j;
				ans+=j;
			}
		}
		else
		{
			for(int j=X[i-1]+1;j<X[i];j++)
			{
				Y[id++]=j;
				ans+=min(abs(X[i-1]-j),abs(X[i]-j));
			}
		}
	}
	if(id<M)
	{
		Y[id++]=X[0]-K-1;
		ans+=K+1;
	}
	if(id<M)
	{
		Y[id++]=X[N-1]+K+1;
		ans+=K+1;
	}
	for(int i=1;id<M&&i<N;i++)
	{
		if(X[i]-X[i-1]-1<=2*K)continue;
		if(X[i]-X[i-1]-1==2*K+1)
		{
			Y[id++]=X[i-1]+K+1;
			ans+=K+1;
		}
		else if(X[i]-X[i-1]-1>=2*K+2)
		{
			Y[id++]=X[i-1]+K+1;
			ans+=K+1;
			if(id<M)
			{
				Y[id++]=X[i]-K-1;
				ans+=K+1;
			}
		}
	}
	printf("%lld\n",ans);
	for(int i=0;i<M;i++)printf("%d%c",Y[i],i==M-1?'\n':' ');
}