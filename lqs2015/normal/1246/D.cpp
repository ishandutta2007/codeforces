#include<bits/stdc++.h>
using namespace std;
int n,pa[111111],dep[111111],mxp;
set<int> sons[111111];
vector<int> ans,fuck;
void dfs(int i)
{
	for (set<int>::iterator it=sons[i].begin();it!=sons[i].end();it++)
	{
		dep[*it]=dep[i]+1;
		dfs(*it);
	}
}
int main()
{
	scanf("%d",&n);
	pa[0]=-1;
	for (int i=1;i<n;i++)
	{
		scanf("%d",&pa[i]);
		sons[pa[i]].insert(i);
	}
	dfs(0);mxp=0;
	for (int i=1;i<n;i++)
	{
		if (dep[i]>dep[mxp]) mxp=i;
	}
	while(mxp)
	{
		if ((int)sons[pa[mxp]].size()<=1) mxp=pa[mxp];
		else 
		{
			set<int>::iterator it=sons[pa[mxp]].begin();
			if ((*it)==mxp) it++;
			ans.push_back(mxp);
			int pp=pa[mxp],tt=(*it);
			pa[mxp]=(*it);
			sons[pp].erase(sons[pp].find(mxp));
			sons[tt].insert(mxp);
		}
	}
	for (int i=0;i<n;i++)
	{
		if (sons[i].empty()) mxp=i;
	}
	while(mxp)
	{
		fuck.push_back(mxp);
		mxp=pa[mxp];
	}
	fuck.push_back(0);
	for (int i=(int)fuck.size()-1;i>=0;i--) printf("%d ",fuck[i]);
	printf("\n");
	printf("%d\n",(int)ans.size());
	for (int i=(int)ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}