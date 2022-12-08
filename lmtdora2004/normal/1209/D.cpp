#include <bits/stdc++.h>

using namespace std;

int n, k;
pair<int, int> a[100005];
bool used[100005];
int eat[100005];
vector<int> cac[100005];

void dfs(int i)
{
	for(auto j:cac[i])
	{
		if(!used[i])
		{
			eat[i]=j;
			used[i]=true;
		}
		if(!used[a[j].first])
		{
			eat[a[j].first]=j;
			used[a[j].first]=true;
			dfs(a[j].first);
		}
		if(!used[a[j].second])
		{
			eat[a[j].second]=j;
			used[a[j].second]=true;
			dfs(a[j].second);
		}
	}
}

signed main()
{
	cin>>n>>k;
	for(int i=1; i<=k; i++)
	{
		cin>>a[i].first>>a[i].second;
		cac[a[i].first].push_back(i);
		cac[a[i].second].push_back(i);
	}
	for(int i=1; i<=n; i++)
	{
		if(!used[i]) dfs(i);
	}
	int lel=0;
	for(int i=1; i<=k; i++)
	{
		if(eat[a[i].first]!=i&&eat[a[i].second]!=i)
		{
			lel++;
		}
	}
	cout<<lel;
}