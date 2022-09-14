#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
int p[2<<17],c[2<<17];
bool vis[2<<17];
bool check(const vector<int>&A,int g)
{
	for(int i=0;i<g;i++)
	{
		bool flag=true;
		for(int j=i+g;j<A.size();j+=g)
		{
			if(A[i]!=A[j])
			{
				flag=false;
				break;
			}
		}
		if(flag)return true;
	}
	return false;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&p[i]),p[i]--;
		for(int i=0;i<N;i++)scanf("%d",&c[i]);
		for(int i=0;i<N;i++)vis[i]=false;
		int ans=N;
		for(int i=0;i<N;i++)
		{
			if(vis[i])continue;
			int now=i;
			vector<int>A;
			do{
				A.push_back(c[now]);
				vis[now]=true;
				now=p[now];
			}while(now!=i);
			for(int k=1;k*k<=A.size();k++)
			{
				if(A.size()%k!=0)continue;
				if(check(A,k))ans=min(ans,k);
				if(k*k<A.size()&&check(A,(int)A.size()/k))ans=min(ans,(int)A.size()/k);
			}
		}
		printf("%d\n",ans);
	}
}