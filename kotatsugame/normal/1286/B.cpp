#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
int N;
int c[2000];
vector<int>G[2000];
vector<int>dfs(int u,int p)
{
	vector<int>now(0);
	bool ok=false;
	if(c[u]==0)
	{
		now.push_back(u);
		ok=true;
	}
	for(int v:G[u])
	{
		vector<int>nxt=dfs(v,u);
		for(int i=0;i<nxt.size();i++)
		{
			now.push_back(nxt[i]);
			if(now.size()==c[u])
			{
				now.push_back(u);
				ok=true;
			}
		}
	}
	if(!ok)
	{
		puts("NO");
		exit(0);
	}
	return now;
}
main()
{
	scanf("%d",&N);
	int root;
	for(int i=0;i<N;i++)
	{
		int p;scanf("%d%d",&p,&c[i]);
		if(p!=0)
		{
			G[p-1].push_back(i);
		}
		else root=i;
	}
	vector<int>ans=dfs(root,-1);
	vector<int>a(N);
	for(int i=0;i<N;i++)
	{
		a[ans[i]]=i+1;
	}
	puts("YES");
	for(int i=0;i<N;i++)printf("%d%c",a[i],i==N-1?'\n':' ');
}