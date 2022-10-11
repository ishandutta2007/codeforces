#include <iostream>
#include <vector>
using namespace std;
#define C 26
#define MAX 100005
int ind(char c)
{
	return c-'a';
}
int trie[MAX][C],cn,dp[MAX],dp2[MAX];
void insert(string s)
{
	int node=0;
	for (int i=0;i<s.size();i++)
	{
		if (trie[node][ind(s[i])])
		node=trie[node][ind(s[i])];
		else
		{
			cn++;
			trie[node][ind(s[i])]=cn;
			node=cn;
		}
	}
}
void dfs(int node)
{
	bool b=1;
	for (int i=0;i<26;i++)
	{
		if (trie[node][i])
		{
			dfs(trie[node][i]);
			b=0;
		}
	}
	if (b)
	dp2[node]=1;
	else
	{
		for (int i=0;i<26;i++)
		{
			if (trie[node][i])
			{
				dp[node]|=!dp[trie[node][i]];
				dp2[node]|=!dp2[trie[node][i]];
			}
		}
	}
}
int main()
{
	int n,k;
	cin >> n >> k;
	while (n--)
	{
		string s;
		cin >> s;
		insert(s);
	}
	dfs(0);
	if (!dp[0])
	cout << "Second";
	else if (dp2[0])
	cout << "First";
	else if (k%2)
	cout << "First";
	else
	cout << "Second";
}