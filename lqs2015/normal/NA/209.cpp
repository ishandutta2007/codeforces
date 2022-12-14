#include<bits/stdc++.h>
using namespace std;
const int maxt=10000;
int n,m,match[222222],all,x,y,xx,yy,sz[222222],cc,col[222222],arr[222222],cnt;
vector<int> g[222222],rg[222222],v,ng[222222],h[222222];
bool used[222222],rig[222222];
bitset<10010> b[222222];
long long ans;
map<pair<int,int>,int> mp;
int get(int x,int y)
{
	return (x-1)*m+y;
}
char s[222222];
void addedge(int x,int y)
{
	g[x].push_back(y);
	rg[y].push_back(x);
}
void pro1(int d)
{
	x=(d-1)/m+1;y=(d-1)%m+1;
	if ((x+y)&1)
	{
		addedge(d,d+1);
		if (y-1>=1) addedge(d-1,d+1);
		if (y+2<=m) addedge(d,d+2);
	}
	else
	{
		addedge(d+1,d);
		if (y-1>=1) addedge(d+1,d-1);
		if (y+2<=m) addedge(d+2,d);
 	}
}
void pro2(int d)
{
	x=(d-1)/m+1;y=(d-1)%m+1;
	if ((x+y)&1)
	{
		addedge(d,d+m);
		if (x-1>=1) addedge(d-m,d+m);
		if (x+2<=n) addedge(d,d+2*m);
	}
	else
	{
		addedge(d+m,d);
		if (x-1>=1) addedge(d+m,d-m);
		if (x+2<=n) addedge(d+2*m,d);
	}
}
void dfs(int i)
{
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		if (!used[g[i][j]]) dfs(g[i][j]);
	}
	v.push_back(i);
}
void rdfs(int i)
{
	col[i]=cc;sz[cc]++;
	h[cc].push_back(i);
	for (int j=0;j<rg[i].size();j++)
	{
		int to=rg[i][j];
		if (!col[to]) rdfs(to);
	}
}
int main()
{
	scanf("%d%d",&n,&m);all=n*m;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=1;j<=m;j++)
		{
			if (s[j-1]=='U') match[get(i,j)]=get(i+1,j);
			else if (s[j-1]=='D') match[get(i,j)]=get(i-1,j);
			else if (s[j-1]=='L') match[get(i,j)]=get(i,j+1);
			else match[get(i,j)]=get(i,j-1);
		}
	}
	for (int i=1;i<=all;i++)
	{
		if (match[i]==i+1 && m!=1) pro1(i);
		else if (match[i]==i+m) pro2(i);
	}
	for (int i=1;i<=all;i++)
	{
		if (!used[i]) dfs(i);
	}
	for (int i=(int)v.size()-1;i>=0;i--)
	{
		if (!col[v[i]])
		{
			++cc;
			rdfs(v[i]);
		}
	}
	for (int i=1;i<=all;i++)
	{
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			if (col[i]==col[to] || mp.find(make_pair(col[i],col[to]))!=mp.end()) continue;
			ng[col[i]].push_back(col[to]);
			mp[make_pair(col[i],col[to])]=1;
		}
	}
	for (int i=1;i<=all;i++)
	{
		x=(i-1)/m+1;y=(i-1)%m+1;
		if ((x+y)%2==0) 
		{
			arr[++cnt]=i;
			rig[col[i]]=1;
		}
	}
	for (int i=0;i*maxt+1<=cnt;i++)
	{
		xx=i*maxt+1;yy=min(cnt,(i+1)*maxt);
		for (int j=1;j<=cc;j++) b[j].reset();
		for (int j=xx;j<=yy;j++) b[col[arr[j]]][j-xx]=1;
		for (int j=cc;j>=1;j--)
		{
			for (int k=0;k<ng[j].size();k++) b[j]|=b[ng[j][k]];
			if (!rig[j]) ans+=(1ll*sz[j]*b[j].count());
		}
	}
	printf("%lld\n",ans);
	return 0;
}