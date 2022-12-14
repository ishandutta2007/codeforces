#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
struct edge
{
	int to,cap,rev;
};
bool f[55555],used[111],u[111];
int n,m,a[111],x,y,prime[55555],cnt,num[111],s,t,ans;
vector<int> v[111];
vector<edge> g[111];
int dfs(int i)
{
	if (i==t) return 1;
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		edge e=g[i][j];
		if (e.cap>0 && !used[e.to])
		{
			int d=dfs(e.to);
			if (d!=-1)
			{
				g[i][j].cap--;
				g[e.to][e.rev].cap++;
				return d;
			}
		}
	}
	return -1;
}
int maxflow()
{
	int f=0,cur;
	while(1)
	{
		memset(used,0,sizeof(used));
		cur=dfs(s);
		if (cur==-1) break;
		f+=cur;
	}
	return f;
}
int main()
{
	for (int i=2;i<=40000;i++)
	{
		for (int j=i+i;j<=40000;j+=i)
		f[j]=1;
	}
	for (int i=2;i<=40000;i++) 
	{
		if (!f[i]) prime[++cnt]=i;
	}
	cin>>n>>m;
	s=n+1;t=n+2;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);  
	}
	for (int i=1;i<=cnt;i++)
	{
		memset(num,0,sizeof(num));
		for (int j=1;j<=n;j++)
		{
			while(a[j]%prime[i]==0)
			{
				num[j]++;
				a[j]/=prime[i];
			}
		}
		for (int j=1;j<=t;j++) g[j].clear();
		for (int j=1;j<=n;j++)
		{
			if (j%2==0) continue;
			for (int k=0;k<v[j].size();k++)
			{
				int to=v[j][k];
				g[j].push_back((edge){to,1e9,g[to].size()});
				g[to].push_back((edge){j,0,g[j].size()-1}); 
			}
		}
		for (int j=1;j<=n;j++)
		{
			if (j%2==1) 
			{
				g[s].push_back((edge){j,num[j],g[j].size()});
				g[j].push_back((edge){s,0,g[s].size()-1}); 
			}
			else
			{
				g[j].push_back((edge){t,num[j],g[t].size()});
				g[t].push_back((edge){j,0,g[j].size()-1});  
			}		
		}
		ans+=maxflow();
	}
	for (int i=1;i<=n;i++)
	{
		if (u[i] || a[i]==1) continue;
		memset(num,0,sizeof(num));
		for (int j=1;j<=n;j++)
		{
			if (a[j]==a[i]) 
			{
				u[j]=1;
				num[j]=1;
			}
		}
		for (int j=1;j<=t;j++) g[j].clear();
		for (int j=1;j<=n;j++)
		{
			if (j%2==0) continue;
			for (int k=0;k<v[j].size();k++)
			{
				int to=v[j][k];
				g[j].push_back((edge){to,1e9,g[to].size()});
				g[to].push_back((edge){j,0,g[j].size()-1}); 
			}
		}
		for (int j=1;j<=n;j++)
		{
			if (j%2==1) 
			{
				g[s].push_back((edge){j,num[j],g[j].size()});
				g[j].push_back((edge){s,0,g[s].size()-1}); 
			}
			else
			{
				g[j].push_back((edge){t,num[j],g[t].size()});
				g[t].push_back((edge){j,0,g[j].size()-1});  
			}		
		}
		ans+=maxflow();
	}
	cout<<ans<<endl;
	return 0;
}