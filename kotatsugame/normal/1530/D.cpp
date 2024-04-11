#include<cstdio>
#include<vector>
using namespace std;
int T,N;
int A[2<<17];
int B[2<<17];
int id[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&A[i]);
			id[i]=0;
		}
		int ans=0;
		vector<int>rest;
		for(int i=1;i<=N;i++)
		{
			if(id[A[i]]==0)
			{
				id[A[i]]=i;
				B[i]=A[i];
				ans++;
			}
			else
			{
				rest.push_back(i);
			}
		}
		vector<int>to;
		for(int i=1;i<=N;i++)if(id[i]==0)to.push_back(i);
		for(int i=0;i+1<to.size();i++)
		{
			if(rest[i]==to[i])swap(to[i],to[i+1]);
			B[rest[i]]=to[i];
		}
		if(to.size()>=1)
		{
			int x=rest.back();
			int y=to.back();
			if(x!=y)B[x]=y;
			else
			{
				B[x]=A[x];
				B[id[A[x]]]=y;
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=N;i++)printf("%d%c",B[i],i==N?10:32);
	}
}