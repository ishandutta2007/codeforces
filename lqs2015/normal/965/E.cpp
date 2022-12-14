#include<iostream>
#include<string>
#include<queue>
using namespace std;
int n,sz,pos;
string s;
int trie[111111][26],dep[111111],ans;
bool f[111111];
priority_queue<int> q;
void Init(int i)
{
	for (int j=0;j<26;j++)
	{
		int to=trie[i][j];
		if (!to) continue;
		dep[to]=dep[i]+1;
		Init(to);
	}
}
void dfs(int i,priority_queue<int> &q)
{
	priority_queue<int> p;
	for (int j=0;j<26;j++)
	{
		int to=trie[i][j];
		if (!to) continue;
		dfs(to,p);
		if (q.size()<p.size()) swap(p,q);
		while(!p.empty()) 
		{
			q.push(p.top());
			p.pop();
		}
	}
	if (i==1) return;
	if (f[i]) q.push(dep[i]);
	else
	{
		q.pop();
		q.push(dep[i]); 
	} 
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	sz=1;
	for (int i=1;i<=n;i++)
	{
		pos=1;
		cin>>s;
		for (int j=0;j<s.size();j++)
		{
			if (!trie[pos][s[j]-'a'])
			{
				trie[pos][s[j]-'a']=++sz;
				pos=sz;
			}
			else pos=trie[pos][s[j]-'a'];
		}
		f[pos]=1;
	}
	Init(1);
	dfs(1,q);
	while(!q.empty()) 
	{
		ans+=q.top();
		q.pop();
	}
	cout<<ans<<endl;
	return 0;
}