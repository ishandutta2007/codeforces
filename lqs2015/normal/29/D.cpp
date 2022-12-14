#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> g[333],ans,v;
int n,k,x,y,p,pr;
bool used[333];
bool dfs(int fa,int i,int p)
{
	used[i]=1;
	if (i==p)
	{
		v.push_back(i); 
		return 1;
	}
	bool res=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (dfs(i,to,p)) res=1;
	}
	if (res && fa) v.push_back(i); 
	return res;
}
void DFS(int fa,int i,int p)
{
	v.clear();
	memset(used,0,sizeof(used));
	dfs(fa,i,p);
	pr=p;
	for (int j=v.size()-1;j>=0;j--) ans.push_back(v[j]); 
}
int main()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	for (int i=2;i<=n;i++)
	{
		if (g[i].size()==1) k++;
	}
	cin>>p;
	ans.push_back(1); 
	DFS(0,1,p);
	for (int i=1;i<k;i++)
	{
		cin>>p;
		DFS(0,pr,p);
	}
	DFS(0,p,1);
	if (ans.size()!=2*n-1) cout<<-1<<endl;
	else
	{
		for (int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}