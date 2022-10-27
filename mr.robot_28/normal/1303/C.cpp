#include<bits/stdc++.h>
 
using namespace std;
#define int long long
string s1;
vector <set <int> > g;
vector <int> used;
bool dfs(int v, int pred = -1)
{
	char t = v + 'a';
	s1 += t;
	used[v] = 1;
	set <int> :: iterator it;
	for(it = g[v].begin(); it != g[v].end(); it++)
	{
		int to = *it;
		if(to == pred)
		{
			continue;
		}
		if(used[to] == 1)
		{
			return false;
		}
		if(used[to] == 0 && !dfs(to, v))
		{
			return false;
		}
	}
	used[v] = 2;
	return true;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	g.resize(26);
	used.resize(26);
	while(t--)
	{
		string s;
		cin >> s;
		s1 = "";
		for(int i = 0; i < 26; i++)
		{
			used[i] = 0;
			if(g[i].size() != 0)
			{
				g[i].clear();
			}
		}
		for(int i = 0; i < s.size() - 1; i++)
		{
			g[s[i] - 'a'].insert(s[i + 1] - 'a');
			g[s[i + 1] - 'a'].insert(s[i] - 'a');
		}
		bool flag = true;
		bool flag1 = false;
		for(int i = 0; i < 26;i++)
		{
			if(g[i].size() > 2)
			{
				flag = false;
			}
		}
		if(!flag)
		{
			cout << "NO\n";
			continue;
		}
		for(int i = 0; i < 26; i++)
		{
			if(used[i] == 0 && (g[i].size() == 0 || g[i].size() == 1) && !dfs(i))
			{
				flag = false;
				break;
			}
		}
		for(int i = 0; i < 26; i++)
		{
			if(used[i] != 2)
			{
				flag = false;
			}
		}
		if(!flag)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		cout << s1 << "\n";
	}
	return 0;
}