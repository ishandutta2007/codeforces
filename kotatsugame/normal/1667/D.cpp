#include<iostream>
#include<vector>
#include<list>
using namespace std;
int T,N;
vector<int>G[2<<17];
int dp[2<<17];
bool ok;
void dfs(int u,int p)
{
	int c01=0,c10=0,c11=0;
	for(int v:G[u])if(v!=p)
	{
		dfs(v,u);
		if(dp[v]==1)c01++;
		else if(dp[v]==2)c10++;
		else c11++;
	}
	int n01=0,n10=0;
	if(G[u].size()%2==0)n01=n10=G[u].size()/2;
	else n01=G[u].size()/2,n10=(G[u].size()+1)/2;
	n01-=c01;
	n10-=c10;
	if(n01<0||n10<0)
	{
		ok=false;
		return;
	}
	if(p!=-1)
	{
		dp[u]=(n01>0)+(n10>0)*2;
		return;
	}
}
list<pair<int,int> >ret;
void dfs2(int u,int p,int del)
{
	list<pair<int,int> >now;
	vector<int>v01,v10,v11;
	for(int v:G[u])if(v!=p)
	{
		if(dp[v]==1)v01.push_back(v);
		else if(dp[v]==2)v10.push_back(v);
		else v11.push_back(v);
	}
	if(del==1)v01.push_back(-1);
	else if(del==2)v10.push_back(-1);
	for(int c=G[u].size();c>=1;c--)
	{
		if(c%2==0)
		{
			int to;
			if(!v01.empty())
			{
				to=v01.back();
				v01.pop_back();
			}
			else
			{
				to=v11.back();
				v11.pop_back();
			}
			if(to==-1)now.push_back(make_pair(u,p));
			else
			{
				dfs2(to,u,1);
				if(now.size()>ret.size())
				{
					for(pair<int,int>p:ret)now.push_back(p);
				}
				else
				{
					now.swap(ret);
					for(auto it=ret.rbegin();it!=ret.rend();it++)now.push_front(*it);
				}
			}
		}
		else
		{
			int to;
			if(!v10.empty())
			{
				to=v10.back();
				v10.pop_back();
			}
			else
			{
				to=v11.back();
				v11.pop_back();
			}
			if(to==-1)now.push_back(make_pair(u,p));
			else
			{
				dfs2(to,u,2);
				if(now.size()>ret.size())
				{
					for(pair<int,int>p:ret)now.push_back(p);
				}
				else
				{
					now.swap(ret);
					for(auto it=ret.rbegin();it!=ret.rend();it++)now.push_front(*it);
				}
			}
		}
	}
	ret.swap(now);
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;cin>>u>>v;
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ok=true;
		dfs(0,-1);
		if(!ok)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		dfs2(0,-1,0);
		for(pair<int,int>p:ret)cout<<p.first+1<<" "<<p.second+1<<"\n";
	}
}