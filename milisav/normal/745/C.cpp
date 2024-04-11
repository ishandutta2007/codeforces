#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> a[1004];
int n,m,k;
int d[1005][2];
int pri[1006];
bool vis[1006];
vector<int> q;
int r=0;
void bfs(int ui)
{
	int co=0;
	int u,v;
	q.push_back(ui);
	int ind=0;
	vis[ui]=true;
	while(ind<q.size())
	{
		u=q[ind];
		co+=a[u].size();
		for(int j=0;j<a[u].size();j++)
		{
			v=a[u][j];
			if(!vis[v])
			{
				pri[v]=ui;
				d[ui][1]++;
				vis[v]=true;
				q.push_back(v);
			}
		}
		ind++;
	}
	co/=2;
	r+=((d[ui][1])*(d[ui][1]-1)/2-co);
	q.clear();
}
int main()
{
	int u,v;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++) pri[i]=-1;
	for(int i=0;i<n;i++) vis[i]=false;
	for(int i=0;i<k;i++)
	{
		scanf("%d",&u);
		u--;
		pri[u]=u;
		d[i][0]=u;
		d[u][1]=1;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		u--;
		v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=0;i<k;i++)
	{
		bfs(d[i][0]);
	}
	int ma=-1;
	int b=0;
	int od=0;
	for(int i=0;i<n;i++)
	{
		if(pri[i]==i)
		{
			if(d[i][1]!=0)
			{
				if(d[i][1]>ma) ma=d[i][1];
			}
		}
		else
		{
			if(pri[i]==-1)
			{
				b++;
				od+=a[i].size();
			}
		}
	}
	od=od/2;
	r+=b*ma+(b*(b-1)/2-od);
	cout<<r<<endl;
	return 0;
}