#include <iostream>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <set>
using namespace std;
set<int> s,part[2];
int par[605],dep[605];
vector<int> v[605],a;
int ask()
{
	if (a.size()<=1)
	return 0;
	printf("? %d\n",a.size());
	for (int i:a)
	printf("%d ",i);
	printf("\n");
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	assert(ans!=-1);
	return ans;
}
vector<int> vec(int l,int r)
{
	vector<int> ret;
	int i=0;
	for (int u:s)
	{
		if (i>=l && i<=r)
		ret.push_back(u);
		i++;
	}
	return ret;
}
void dfs(int node,int d)
{
	part[d%2].insert(node);
	dep[node]=d;
	int i=0;
	while (1)
	{
		int st=i,en=s.size();
		while (st!=en)
		{
			int mid=(st+en)/2;
			a=vec(i,mid);
			a.push_back(node);
			int cur=ask();
			a.pop_back();
			if (cur-ask())
			en=mid;
			else
			st=mid+1;
		}
		if (st==s.size())
		break;
		a=vec(st,st);
		v[node].push_back(a[0]);
		s.erase(a[0]);
		i=st;
	}
	for (int u:v[node])
	{
		par[u]=node;
		dfs(u,d+1);
	}
}
void no(int u1,int u2)
{
	vector<int> v1(1,u1),v2;
	while (u1!=u2)
	{
		if (dep[u1]>dep[u2])
		{
			u1=par[u1];
			v1.push_back(u1);
		}
		else
		{
			v2.push_back(u2);
			u2=par[u2];
		}
	}
	reverse(v2.begin(),v2.end());
	printf("N %d\n",v1.size()+v2.size());
	for (int u:v1)
	printf("%d ",u);
	for (int u:v2)
	printf("%d ",u);
	fflush(stdout);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	s.insert(i);
	dfs(1,0);
	for (int i=1;i<=n;i++)
	{
		int c=dep[i]%2;
		part[c].erase(i);
		a=vector<int>(part[c].begin(),part[c].end());
		int ans=ask();
		a.push_back(i);
		if (ask()-ans)
		{
			s=part[c];
			int st=0,en=s.size()-1;
			while (st!=en)
			{
				int mid=(st+en)/2;
				a=vec(0,mid);
				a.push_back(i);
				int cur=ask();
				a.pop_back();
				if (cur-ask())
				en=mid;
				else
				st=mid+1;
			}
			a=vec(st,st);
			no(i,a[0]);
			return 0;
		}
		part[c].insert(i);
	}
	printf("Y %d\n",part[0].size());
	for (int u:part[0])
	printf("%d ",u);
	fflush(stdout);
}