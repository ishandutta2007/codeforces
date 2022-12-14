#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
bool ss(int n)
{
	for (int i=2;i<=sqrt(n);i++)
	{
		if (n%i==0) return 0;
	}
	return 1;
}
struct edge
{
	int to,cap,rev;
};
int n,a[222],s,t,cnt1,cnt2,cnt;
vector<edge> g[222];
vector<int> v[222];
bool used[222];
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
void rfs(int i)
{
	v[cnt].push_back(i); 
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		edge e=g[i][j];
		if (e.to>n || used[e.to]) continue;
		if (a[i]%2 && e.cap>0) continue;
		if (a[i]%2==0 && e.cap<=0) continue; 
		rfs(e.to);
	}
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if (a[i]%2) cnt1++;
		else cnt2++;
	}
	if (cnt1!=cnt2) 
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	s=n+1;t=n+2;
	for (int i=1;i<=n;i++)
	{
		if (a[i]%2==0) continue;
		for (int j=1;j<=n;j++)
		{
			if (a[j]%2==0 && ss(a[i]+a[j]))
			{
				g[i].push_back((edge){j,1,g[j].size()});
				g[j].push_back((edge){i,0,g[i].size()-1});
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]%2) 
		{
			g[s].push_back((edge){i,2,g[i].size()});
			g[i].push_back((edge){s,0,g[s].size()-1});  
		}
		else
		{
			g[i].push_back((edge){t,2,g[t].size()});
			g[t].push_back((edge){i,0,g[i].size()-1}); 
		}
	}
	int f=maxflow();
	if (f!=n)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	memset(used,0,sizeof(used));
	for (int i=1;i<=n;i++)
	{
		if (!used[i])
		{
			cnt++;
			rfs(i);
		}
	}
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++)
	{
		cout<<v[i].size()<<" ";
		for (int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}