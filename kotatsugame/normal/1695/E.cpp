#include<iostream>
#include<vector>
#include<map>
using namespace std;
int N;
vector<pair<int,int> >G[6<<17];
vector<vector<int> >loops;
bool vis[6<<17];
bool usd[3<<17];
void dfs(int u)
{
	loops.back().push_back(u);
	vis[u]=true;
	for(pair<int,int>e:G[u])if(!usd[e.second])
	{
		usd[e.second]=true;
		if(!vis[e.first])dfs(e.first);
		else
		{
			loops.back().push_back(e.first);
		}
		loops.back().push_back(u);
	}
}
vector<int>ans[2];
string A[2][2];
void nxt(int&x,int&y,int l,int r)
{
	if(x==0)
	{
		y++;
		if(y==r)y--,x=1;
	}
	else
	{
		y--;
		if(y<l)y++,x=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(make_pair(y,i));
		G[y].push_back(make_pair(x,i));
	}
	for(int i=1;i<=2*N;i++)if(!vis[i]&&!G[i].empty())
	{
		loops.emplace_back();
		dfs(i);
		if(loops.back().size()==3)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=0;i<loops.size();i++)
	{
		int n=loops[i].size()/2;
		int pn=ans[0].size();
		ans[0].resize(pn+n);
		ans[1].resize(pn+n);
		A[0][0]+=string(n,'_');
		A[0][1]+=string(n,'_');
		A[1][0]+=string(n,'_');
		A[1][1]+=string(n,'_');
		for(int j=0;j<n;j++)
		{
			ans[0][pn+j]=loops[i][j];
			ans[1][pn+j]=loops[i][2*n-j-1];
		}
		for(int j=0;j<2;j++)
		{
			int x=0,y=pn+j;
			for(int _=0;_<n;_++)
			{
				int nx=x,ny=y;
				nxt(nx,ny,pn,pn+n);
				if(x==nx)
				{
					if(y<ny)A[j][nx][y]='L',A[j][nx][ny]='R';
					else A[j][nx][ny]='L',A[j][nx][y]='R';
				}
				else
				{
					if(x<nx)A[j][x][y]='U',A[j][nx][y]='D';
					else A[j][nx][y]='U',A[j][x][y]='D';
				}
				x=nx,y=ny;
				nxt(x,y,pn,pn+n);
			}
		}
	}
	cout<<"2 "<<N<<"\n\n";
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<N;j++)cout<<ans[i][j]<<(j+1==N?"\n":" ");
	}
	cout<<"\n";
	for(int i=0;i<2;i++)cout<<A[0][i]<<"\n";
	cout<<"\n";
	for(int i=0;i<2;i++)cout<<A[1][i]<<"\n";
}