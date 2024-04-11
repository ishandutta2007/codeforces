#include<cstdio>
#include<vector>
using namespace std;
int T,N,A[1<<20],D;
bool vis[1<<20];
vector<int>now;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&D);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			vis[i]=false;
		}
		int ans=0;
		for(int i=0;i<N;i++)if(!vis[i])
		{
			now.clear();
			int u=i;
			int fst=-1;
			while(!vis[u])
			{
				if(A[u]==0)fst=now.size();
				now.push_back(A[u]);
				vis[u]=true;
				u=(u+D)%N;
			}
			if(fst==-1)
			{
				ans=-1;
				break;
			}
			int len=now.size();
			for(int i=0;i<len;)
			{
				if(now[(i+fst)%len]==0)
				{
					i++;
					continue;
				}
				int j=i+1;
				while(j<len&&now[(j+fst)%len]==1)j++;
				int x=j-i;
				if(ans<x)ans=x;
				i=j;
			}
		}
		printf("%d\n",ans);
	}
}