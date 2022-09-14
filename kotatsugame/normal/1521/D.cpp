#include<cstdio>
#include<vector>
using namespace std;
int T,N;
vector<vector<int> >G;
vector<pair<pair<int,int>,pair<int,int> > >del;
int dfs(int u,int p)
{
	int ch=0;
	int to=u;
	for(int v:G[u])if(v!=p)
	{
		int x=dfs(v,u);
		if(x<0)continue;
		ch++;
		if(ch==1)to=x;
		else if(ch==2)
		{
			del.push_back(make_pair(make_pair(p,u),make_pair(to,x)));
			to=-1;
		}
		else
		{
			del.push_back(make_pair(make_pair(u,v),make_pair(v,x)));
		}
	}
	return to;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		G.clear();
		G.resize(N);
		del.clear();
		for(int i=1;i<N;i++)
		{
			int a,b;scanf("%d%d",&a,&b);
			a--,b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int root=0;
		while(G[root].size()>1)root++;
		int to=dfs(root,-1);
		printf("%d\n",del.size());
		for(pair<pair<int,int>,pair<int,int> >e:del)
		{
			printf("%d %d %d %d\n",e.first.first+1,e.first.second+1,to+1,e.second.first+1);
			to=e.second.second;
		}
	}
}