#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
string s[105],ans="";
vector<int> v[30];
bool vis[100005];
int cur;
bool check(int node)
{
	if (node==cur && vis[node])
	return 0;
	if (vis[node])
	return 1;
	vis[node]=1;
	bool ret=1;
	for (int i=0;i<v[node].size();i++)
	ret&=check(v[node][i]);
	return ret;
}
void dfs(int node)
{
	if (vis[node])
	return;
	vis[node]=1;
	for (int i=0;i<v[node].size();i++)
	dfs(v[node][i]);
	ans+=node+'a';
}
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	cin >> s[i];
	for (int i=0;i<n-1;i++)
	{
		int x=0;
		while (s[i][x]==s[i+1][x])
		{
			x++;
			if (s[i].size()==x || s[i+1].size()==x)
			break;
		}
		if (s[i].size()==x)
		continue;
		if (s[i+1].size()==x)
		{
			cout << "Impossible";
			return 0;
		}
		v[s[i][x]-'a'].push_back(s[i+1][x]-'a');
	}
	for (int i=0;i<26;i++)
	{
		cur=i;
		if (!check(i))
		{
			cout << "Impossible";
			return 0;
		}
		memset(vis,0,sizeof(vis));
	}
	for (int i=0;i<26;i++)
	{
		if (!vis[i])
		dfs(i);
	}
	reverse(ans.begin(),ans.end());
	cout << ans;
}