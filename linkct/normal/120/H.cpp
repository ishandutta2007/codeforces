#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
struct Bian
{
	int s,t,flow,now,last;
}bian[2000010];
int maxbian=0,last[100010];
void addbian(int s,int t,int flow)
{
	maxbian++;
	bian[maxbian].s=s;
	bian[maxbian].t=t;
	bian[maxbian].last=last[s];
	bian[maxbian].flow=flow;
	bian[maxbian].now=0;
	last[s]=maxbian;
	maxbian++;
	bian[maxbian].s=t;
	bian[maxbian].t=s;
	bian[maxbian].last=last[t];
	bian[maxbian].flow=0;
	bian[maxbian].now=0;
	last[t]=maxbian;
}
int s,t,v[100010],d[100010],p;
queue<int> q;
int bfs()
{
	memset(v,0,sizeof(v));
	v[s]=1;
	q.push(s);
	int t1,t2;
	while(!q.empty())
	{
		t1=q.front();
		q.pop();
		for(t2=last[t1];t2;t2=bian[t2].last)
			if(bian[t2].flow>bian[t2].now&&!v[bian[t2].t])
			{
				v[bian[t2].t]=1;
				d[bian[t2].t]=d[t1]+1;
				q.push(bian[t2].t);
			}
	}
	return v[t];
}
int cur[100010];
int dfs(int x,int a)
{
	if(x==t||a==0)
		return a;
	int flow=0,f;
	for(;cur[x];cur[x]=bian[cur[x]].last)
	{
		if(d[bian[cur[x]].t]==d[x]+1&&(f=dfs(bian[cur[x]].t,min(bian[cur[x]].flow-bian[cur[x]].now,a)))>0)
		{
			bian[cur[x]].now+=f;
			bian[((cur[x]-1)^1)+1].now-=f;
			a-=f;
			flow+=f;
			if(a==0)
				break;
		}
	}
	return flow;
}
int maxflow()
{
	int t1,flow=0;
	while(bfs())
	{
		for(t1=1;t1<=t;t1++)
			cur[t1]=last[t1];
		flow+=dfs(s,inf);
	}
	return flow;
}
map<string,int> mp;
string st[210],str[100010];
int o=0;
int can[210];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>st[i];
		int len=st[i].length();
		for(int z=1;z<(1<<len);z++)
		{
			int x=0;
			for(int j=0;j<len;j++)
				if(z&(1<<j))
					x++;
			if(x>4)
				continue;
			string ss="";
			for(int j=0;j<len;j++)
				if(z&(1<<j))
					ss=ss+st[i][j];
		//	cout<<ss<<endl;
			int k;
			if(mp[ss]==0)
			{
				o++;
				mp[ss]=o;
				str[o]=ss;
			}
			k=mp[ss];
			addbian(i,n+k,1);
		}
	}
//	cout<<o<<endl;
	s=n+o+1;
	t=n+o+2;
	for(int i=1;i<=n;i++)
		addbian(s,i,1);
	for(int i=1;i<=o;i++)
		addbian(i+n,t,1);
	int m=maxflow();
	if(m<n)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=maxbian;i++)
		if(bian[i].s<=n&&bian[i].t>n&&bian[i].t<=n+o&&bian[i].now>0)
		{
			can[bian[i].s]=bian[i].t-n;
		//	cout<<can[i]<<endl;
		}
	for(int i=1;i<=n;i++)
		cout<<str[can[i]]<<endl;
			
			
	
}