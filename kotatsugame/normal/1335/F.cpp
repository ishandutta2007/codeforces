#include<cstdio>
#include<vector>
using namespace std;
int T,N,M;
vector<vector<char> >c;
vector<vector<char> >s;
vector<vector<int> >col;
vector<vector<int> >id;
vector<vector<bool> >used;
int ans,cnt;
void dfs(int x,int y,int dep)
{
	col[x][y]=-dep;
	int tx=x,ty=y;
	if(s[x][y]=='U')tx--;
	else if(s[x][y]=='D')tx++;
	else if(s[x][y]=='L')ty--;
	else ty++;
	if(col[tx][ty]<0)
	{
		int sz=col[tx][ty]-dep+1;
		id[x][y]=used.size();
		col[x][y]=0;
		used.push_back(vector<bool>(sz,false));
		ans+=sz;
	}
	else
	{
		int k;
		if(col[tx][ty]==0)
		{
			col[x][y]=dep;
			dfs(tx,ty,dep-1);
		}
		k=col[tx][ty];
		k-=1;
		if(k<0)k=used[id[tx][ty]].size()-1;
		id[x][y]=id[tx][ty];
		col[x][y]=k;
	}
	if(c[x][y]=='0'&&!used[id[x][y]][col[x][y]])
	{
		used[id[x][y]][col[x][y]]=true;
		cnt++;
	}
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		ans=cnt=0;
		scanf("%d%d",&N,&M);
		c.clear();c.resize(N);
		s.clear();s.resize(N);
		col.clear();col.resize(N);
		id.clear();id.resize(N);
		used.clear();
		for(int i=0;i<N;i++)
		{
			c[i].resize(M);
			s[i].resize(M);
			col[i].assign(M,0);
			id[i].resize(M);
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)scanf(" %c",&c[i][j]);
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)scanf(" %c",&s[i][j]);
		}
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			if(col[i][j]==0)dfs(i,j,-1);
		}
		printf("%d %d\n",ans,cnt);
	}
}