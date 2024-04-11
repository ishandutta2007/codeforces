#line 1 "a.cpp"
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#line 3 "/home/kotatsugame/library/graph/bimatch.cpp"
struct bimatch{
	int n;
	vector<vector<int> >G;
	vector<int>match;
	vector<bool>used;
	bimatch(int _n=0):n(_n),G(n),match(n),used(n){}
	void add_edge(int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool dfs(int v)
	{
		used[v]=true;
		for(int u:G[v])
		
		{
			int w=match[u];
			if(w<0||!used[w]&&dfs(w))
			{
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
		return false;
	}
	int count()
	{
		int ans=0;
		bool flag=true;
		fill(match.begin(),match.end(),-1);
		while(flag)
		{
			flag=false;
			fill(used.begin(),used.end(),false);
			for(int v=0;v<n;v++)if(match[v]<0&&dfs(v))ans++,flag=true;
		}
		return ans;
	}
};
#line 7 "a.cpp"
int T,N,M;
int d[5]={0,1,0,-1};
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		vector<pair<int,int> >A(M);
		vector<int>ys;
		ys.push_back(1);
		ys.push_back(N);
		for(int i=0;i<M;i++)
		{
			int x,y;scanf("%d%d",&x,&y);
			A[i]=make_pair(y,x);
			if(y>1)ys.push_back(y-1);
			ys.push_back(y);
			if(y<N)ys.push_back(y+1);
		}
		sort(ys.begin(),ys.end());
		ys.erase(unique(ys.begin(),ys.end()),ys.end());
		{
			vector<int>tmpy;
			for(int i=0;i<ys.size();i++)
			{
				if(i+1<ys.size()&&ys[i]+1<ys[i+1])
				{
					if(ys[i]%2!=ys[i+1]%2)i++;
				}
				else tmpy.push_back(ys[i]);
			}
			ys.swap(tmpy);
		}
		sort(A.begin(),A.end());
		vector<vector<bool> >vis(2,vector<bool>(ys.size()));
		int yi=0;
		int cnt=ys.size()*2;
		for(pair<int,int>p:A)
		{
			int y=p.first;
			while(ys[yi]<y)yi++;
			vis[p.second-1][yi]=true;
			cnt--;
		}
		bimatch P(2*ys.size());
		for(int j=0;j<ys.size();j++)
		{
			if(!vis[0][j]&&!vis[1][j])P.add_edge(j,ys.size()+j);
			if(j+1<ys.size())
			{
				if(!vis[0][j]&&!vis[0][j+1])P.add_edge(j,j+1);
				if(!vis[1][j]&&!vis[1][j+1])P.add_edge(ys.size()+j,ys.size()+j+1);
			}
		}
		puts(P.count()*2==cnt?"YES":"NO");
	}
}