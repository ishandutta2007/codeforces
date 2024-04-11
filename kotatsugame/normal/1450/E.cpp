#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
int u[2000],v[2000],b[2000];
int ans[200],ac=-1;
int dist[200];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&b[i]);
		u[i]--,v[i]--;
	}
	for(int st=0;st<N;st++)
	{
		for(int i=0;i<N;i++)dist[i]=1e9;
		dist[st]=0;
		bool out=false;
		for(int tm=0;tm<N;tm++)
		{
			bool ch=false;
			for(int i=0;i<M;i++)
			{
				if(b[i]==0)
				{
					if(dist[v[i]]>dist[u[i]]+1)
					{
						dist[v[i]]=dist[u[i]]+1;
						ch=true;
					}
					if(dist[u[i]]>dist[v[i]]+1)
					{
						dist[u[i]]=dist[v[i]]+1;
						ch=true;
					}
				}
				else
				{
					if(dist[v[i]]>dist[u[i]]+1)
					{
						dist[v[i]]=dist[u[i]]+1;
						ch=true;
					}
					if(dist[u[i]]>dist[v[i]]-1)
					{
						dist[u[i]]=dist[v[i]]-1;
						ch=true;
					}
				}
			}
			if(!ch)break;
			else if(tm==N-1)out=true;
		}
		int mx=0,mn=1e9;
		for(int i=0;i<N;i++)
		{
			if(dist[i]<0)out=true;
			if(mx<dist[i])mx=dist[i];
			if(mn>dist[i])mn=dist[i];
		}
		for(int i=0;i<M;i++)
		{
			if(b[i]==0)
			{
				if(abs(dist[u[i]]-dist[v[i]])!=1)out=true;
			}
			else
			{
				if(dist[v[i]]-dist[u[i]]!=1)out=true;
			}
		}
		if(!out&&ac<mx-mn)
		{
			ac=mx-mn;
			for(int i=0;i<N;i++)ans[i]=dist[i];
		}
	}
	if(ac<0)puts("NO");
	else
	{
		puts("YES");
		printf("%d\n",ac);
		for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?'\n':' ');
	}
}