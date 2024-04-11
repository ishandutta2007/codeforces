#line 1 "a.cpp"
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#line 1 "/home/kotatsugame/library/graph/SCC.cpp"
//Strongly Connected Components
#line 3 "/home/kotatsugame/library/graph/SCC.cpp"
struct SCC{
	int n;
	vector<int>comp,order;
	vector<bool>used;
	vector<vector<int> >G,RG;
	SCC(int _n=0):n(_n),comp(_n,-1),used(_n,false),G(_n),RG(_n){}
	void add_edge(int from,int to)
	{
		G[from].push_back(to);
		RG[to].push_back(from);
	}
	void copy(const vector<vector<int> >&H)
	{
		for(int i=0;i<H.size();i++)
		{
			for(int j=0;j<H[i].size();j++)
			{
				G[i].push_back(H[i][j]);
				RG[H[i][j]].push_back(i);
			}
		}
	}
	int operator[](int u)const{return comp[u];}
	void dfs(int u)
	{
		used[u]=true;
		for(int i=0;i<G[u].size();i++)if(!used[G[u][i]])dfs(G[u][i]);
		order.push_back(u);
	}
	void rdfs(int u,int cnt)
	{
		comp[u]=cnt;
		for(int i=0;i<RG[u].size();i++)if(comp[RG[u][i]]==-1)rdfs(RG[u][i],cnt);
	}
	int build()
	{
		for(int i=0;i<n;i++)if(!used[i])dfs(i);
		int cnt=0;
		for(int i=n-1;i>=0;i--)if(comp[order[i]]==-1)rdfs(order[i],cnt++);
		return cnt;
	}
	int build(vector<vector<int> >&H)
	{
		int ret=build();
		H.assign(ret,vector<int>());
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<G[i].size();j++)
			{
				if(comp[i]!=comp[G[i][j]])
					H[comp[i]].push_back(comp[G[i][j]]);
			}
		}
		return ret;
	}
};
#line 6 "a.cpp"
int H,W;
string S[4<<17];
int d[5]={0,1,0,-1};
main()
{
	cin>>H>>W;
	for(int i=0;i<H;i++)cin>>S[i];
	vector<vector<int> >col(H,vector<int>(W));
	int sz=0;
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(S[i][j]=='#'&&col[i][j]==0)
	{
		queue<pair<int,int> >P;
		P.push(make_pair(i,j));
		col[i][j]=++sz;
		while(!P.empty())
		{
			int x=P.front().first,y=P.front().second;
			P.pop();
			for(int r=0;r<4;r++)
			{
				int tx=x+d[r],ty=y+d[r+1];
				if(tx<0||ty<0||tx>=H||ty>=W||S[tx][ty]=='.'||col[tx][ty]>0)continue;
				col[tx][ty]=sz;
				P.push(make_pair(tx,ty));
			}
		}
	}
	SCC G(sz);
	for(int j=0;j<W;j++)
	{
		int pre[3]={};
		for(int i=H;i--;)
		{
			if(col[i][j]>0)
			{
				for(int k=0;k<3;k++)
				{
					if(pre[k]>0&&pre[k]!=col[i][j])G.add_edge(col[i][j]-1,pre[k]-1);
				}
			}
			for(int k=0;k<3;k++)
			{
				if(j+k-1>=0&&j+k-1<W&&col[i][j+k-1]>0)pre[k]=col[i][j+k-1];
			}
		}
	}
	vector<vector<int> >H;
	int K=G.build(H);
	int ans=0;
	vector<int>indeg(K);
	for(int i=0;i<K;i++)for(int u:H[i])indeg[u]++;
	for(int i=0;i<K;i++)ans+=indeg[i]==0;
	cout<<ans<<endl;
}