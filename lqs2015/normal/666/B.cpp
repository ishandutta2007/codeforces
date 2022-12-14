#include<iostream>
#include<queue>
#include<vector>
#include<cstring> 
using namespace std;
typedef pair<int,int> ii;
int dist[3333][3333],n,m,x,y,mx,ans1,ans2,ans3,ans4;
queue<int> q;
pair<int,int> my[3333][5],his[3333][5];
vector<int> g[3333];
const int inf=1e9;
void bfs(int i)
{
	dist[i][i]=0;
	q.push(i); 
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for (int j=0;j<g[x].size();j++)
		{
			if (dist[i][g[x][j]]>dist[i][x]+1)
			{
				dist[i][g[x][j]]=dist[i][x]+1;
				q.push(g[x][j]); 
			}
		}
	}
}
void propose(ii best[],ii val)
{
	if (val.first>best[0].first) 
	{
		best[2]=best[1];
		best[1]=best[0];
		best[0]=val;
	}
	else if (val.first>best[1].first)
	{
		best[2]=best[1];
		best[1]=val;
	}
	else if (val.first>best[2].first)
	{
		best[2]=val;
	}
}
void tried(int val,int a,int b,int c,int d)
{
	if (mx<val)
	{
		mx=val;
		ans1=a;
		ans2=b;
		ans3=c;
		ans4=d;
	}
}
int main()
{
	 cin>>n>>m;
	 for (int i=1;i<=m;i++)
	 {
	     cin>>x>>y;
	     g[x].push_back(y); 
	 }
	 for (int i=0;i<=3000;i++)
	 {
	 	for (int j=0;j<=3000;j++)
	 	{
	 		dist[i][j]=inf;
		 }
	 }
	 for (int i=1;i<=n;i++)
	 {
	 	 bfs(i);
	 }
	 for (int i=1;i<=n;i++)
	 {
	 	my[i][0]=my[i][1]=my[i][2]=his[i][0]=his[i][1]=his[i][2]=make_pair(-inf,0);
	 }
	 for (int i=1;i<=n;i++)
	 {
	 	for (int j=1;j<=n;j++)
	 	{
	 		if (i!=j && dist[i][j]!=inf)
	 		{
	 			propose(my[i],ii(dist[i][j],j));
	 			propose(his[j],ii(dist[i][j],i));
			}
		}
	 }
	 for (int i=1;i<=n;i++)
	 {
	 	for (int j=1;j<=n;j++)
	 	{
	 		if (dist[i][j]==inf || i==j) continue;
			for (int p=0;p<=2;p++)
			{
				if (his[i][p].first==-inf) continue;
				for (int q=0;q<=2;q++)
				{
					if (my[j][q].first==-inf) continue;
					if (his[i][p].second!=j && my[j][q].second!=i && his[i][p].second!=my[j][q].second)
					{
						tried(his[i][p].first+dist[i][j]+my[j][q].first,his[i][p].second,i,j,my[j][q].second);
					}
				}
			} 
		}
	 }
	 cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
	 return 0;
}