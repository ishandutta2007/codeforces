#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int N,K;
int pr[3<<17];
vector<int>G[3<<17];
int H[3<<17];
int indegH[3<<17];
int cid[3<<17],outc[3<<17];
int root,csz;
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&pr[i]);
		pr[i]--;
		if(pr[i]>=0)G[pr[i]].push_back(i);
		else root=i;
	}
	for(int i=0;i<K;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		x--,y--;
		H[x]=y+1;
		indegH[y]=1;
	}
	vector<int>indeg0;
	for(int i=0;i<N;i++)if(indegH[i]==0)indeg0.push_back(i);
	vector<vector<int> >cs;
	for(int id:indeg0)
	{
		if(H[id]==0)continue;
		csz++;
		int u=id;
		vector<int>now;
		while(u>=0)
		{
			if(pr[u]>=0&&cid[pr[u]]!=csz)outc[csz]++;
			now.push_back(u);
			cid[u]=csz;
			u=H[u]-1;
			K--;
		}
		cs.push_back(now);
	}
	if(K>0)
	{
		puts("0");
		return 0;
	}
	vector<int>ans;
	queue<int>Q;
	if(cid[root]==0)Q.push(root);
	else
	{
		if(outc[cid[root]]>0)
		{
			puts("0");
			return 0;
		}
		Q.push(-cid[root]);
	}
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		if(u>=0)
		{
			ans.push_back(u);
			for(int v:G[u])
			{
				if(cid[v]==0)Q.push(v);
				else
				{
					if(--outc[cid[v]]==0)
					{
						Q.push(-cid[v]);
					}
				}
			}
		}
		else
		{
			int id=-u-1;
			for(int u:cs[id])
			{
				ans.push_back(u);
				for(int v:G[u])
				{
					if(cid[v]==0)Q.push(v);
					else
					{
						if(--outc[cid[v]]==0)
						{
							Q.push(-cid[v]);
						}
					}
				}
			}
		}
	}
	if(ans.size()<N)puts("0");
	else
	{
		for(int i=0;i<N;i++)printf("%d%c",ans[i]+1,i+1==N?'\n':' ');
	}
}