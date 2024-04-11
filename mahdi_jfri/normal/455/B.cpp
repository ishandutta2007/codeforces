#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 3e5 + 20;

map<char , int> mp[maxn];

int tah = 1;

bool dp[maxn][2];

string s[maxn];

void insert(int x)
{
	int pos = 0;
	for(int i = 0; i < (int)s[x].size(); i++)
	{
		if(!mp[pos][s[x][i]])
			mp[pos][s[x][i]] = tah++;
		pos = mp[pos][s[x][i]];
	}
}

void dfs(int v)
{
	if(!mp[v].size())
	{
		dp[v][1] = 1;
		return;
	}
	for(auto x : mp[v])
	{
		dfs(x.second);
		dp[v][0] |= !dp[x.second][0];
		dp[v][1] |= !dp[x.second][1];
	}
}

int main()
{
	int n , k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> s[i] , insert(i);
	dfs(0);
	if(dp[0][0] && dp[0][1])
		cout << "First" << endl;
	if(dp[0][0] && !dp[0][1])
		cout << ((k % 2)? "First" : "Second") << endl;
	if(!dp[0][0] && dp[0][1])
		cout << "Second" << endl;
	if(!dp[0][0] && !dp[0][1])
		cout << "Second" << endl;
}