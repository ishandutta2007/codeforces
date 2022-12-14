#include<bits/stdc++.h>
using namespace std;
int n,x,dep[666];
bool used[6666];
map<vector<int>,int> mp;
vector<int> v,vv,vs,vk,g[666],v1,v2,ans;
int ask(vector<int> &a)
{
	if (a.size()==1 || a.size()==0) return 0;
	if (mp.find(a)!=mp.end()) return mp[a];
	printf("? %d\n",(int)a.size());
	fflush(stdout);
	for (int i=0;i<a.size();i++) printf("%d ",a[i]);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	mp[a]=x;
	return x;
}
int qry(vector<int> &a,vector<int> &b)
{
	vector<int> c;
	for (int i=0;i<a.size();i++) c.push_back(a[i]);
	for (int i=0;i<b.size();i++) c.push_back(b[i]);
	sort(c.begin(),c.end());
	return ask(c)-ask(a)-ask(b);  
}
void dfs(int i,int fa)
{
	dep[i]=dep[fa]+1;
	if (dep[i]&1) v1.push_back(i);
	else v2.push_back(i);  
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
	}
}
int dft(int i,int fa)
{
	if (i==vk[0]) 
	{
		ans.push_back(i);
		return 1; 
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (dft(to,i)) 
		{
			ans.push_back(i);
			return 1; 
		}
	} 
	return 0;
}
int main()
{
	scanf("%d",&n);
	v.push_back(1);
	used[1]=1;
	while(v.size()<n)
	{
		vv.clear();
		for (int i=1;i<=n;i++)
		{
			if (!used[i]) vv.push_back(i); 
		}
		vs=v;
		while(vs.size()>1)
		{
			vk.clear();
			int x=(int)vs.size()/2;
			for (int i=0;i<x;i++) vk.push_back(vs[i]);
			if (qry(vk,vv)) vs=vk;
			else 
			{
				vk.clear();
				for (int i=x;i<vs.size();i++) vk.push_back(vs[i]);
				vs=vk; 
			}
		}
		while(vv.size()>1)
		{
			vk.clear();
			int x=(int)vv.size()/2;
			for (int i=0;i<x;i++) vk.push_back(vv[i]);
			if (qry(vs,vk)) vv=vk;
			else 
			{
				vk.clear();
				for (int i=x;i<vv.size();i++) vk.push_back(vv[i]);
				vv=vk; 
			}
		}
		g[vs[0]].push_back(vv[0]);
		g[vv[0]].push_back(vs[0]); 
		used[vv[0]]=1;
		v.push_back(vv[0]);  
	}
	dfs(1,0);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	vs.clear();vk.clear();
	if (ask(v1))
	{
		for (int i=0;i<v1.size();i++)
		{
			vs.clear();vk.clear();
			vs.push_back(v1[i]); 
			for (int j=0;j<v1.size();j++)
			{
				if (i==j) continue;
				vk.push_back(v1[j]); 
			}
			if (qry(vs,vk)) break;
		}
		while(vk.size()>1)
		{
			vv.clear();
			int x=(int)vk.size()/2;
			for (int i=0;i<x;i++) vv.push_back(vk[i]);
			if (qry(vs,vv)) vk=vv;
			else 
			{
				vv.clear();
				for (int i=x;i<vk.size();i++) vv.push_back(vk[i]);
				vk=vv; 
			} 
		}
		dft(vs[0],0);
		printf("N %d\n",(int)ans.size());
		fflush(stdout);
		for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
		fflush(stdout);
	}
	else if (ask(v2))
	{
		for (int i=0;i<v2.size();i++)
		{
			vs.clear();vk.clear();
			vs.push_back(v2[i]); 
			for (int j=0;j<v2.size();j++)
			{
				if (i==j) continue;
				vk.push_back(v2[j]); 
			}
			if (qry(vs,vk)) break;
		}
		while(vk.size()>1)
		{
			vv.clear();
			int x=(int)vk.size()/2;
			for (int i=0;i<x;i++) vv.push_back(vk[i]);
			if (qry(vs,vv)) vk=vv;
			else 
			{
				vv.clear();
				for (int i=x;i<vk.size();i++) vv.push_back(vk[i]);
				vk=vv; 
			} 
		}
		dft(vs[0],0);
		printf("N %d\n",(int)ans.size());
		fflush(stdout);
		for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
		fflush(stdout);
	}
	else
	{
		printf("Y %d\n",(int)v1.size());
		fflush(stdout);
		for (int i=0;i<v1.size();i++) 
		{
			printf("%d ",v1[i]);
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}