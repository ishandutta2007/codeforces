#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
#define C 2
#define MAX 32*200005
int ind(char c)
{
	return c-'0';
}
int trie[MAX][C],c[MAX],cn;
map<int,int> m;
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
			c[node]++;
			trie[node][ind(s[i])]=cn;
			node=cn;
		}
	}
}
void erase(string s)
{
	vector<int> v(1,0);
	int node=0;
	for (int i=0;i<s.size();i++)
	{
		if (trie[node][ind(s[i])])
		node=trie[node][ind(s[i])],v.push_back(node);
		else
		return;
	}
	for (int i=v.size()-1;i>0;i--)
	{
		if (!c[v[i]])
		trie[v[i-1]][ind(s[i-1])]=0,c[v[i-1]]--;
		else
		return;
	}
}
int solve(string s)
{
	int node=0,ans=0;
	for (int i=0;i<s.size();i++)
	{
		if (trie[node][!ind(s[i])])
		node=trie[node][!ind(s[i])],ans+=(1<<(31-i-1));
		else
		node=trie[node][ind(s[i])];
	}
	return ans;
}
string convert(int n,int base)
{
	string ret="";
	while (n)
	{
		ret+=n%base+'0';
		n/=base;
	}
	for (int i=ret.size();i<31;i++)
	ret+='0';
	reverse(ret.begin(),ret.end());
	return ret;
}
int main()
{
	insert(convert(0,2));
	int q;
	scanf("%d",&q);
	while (q--)
	{
		char t;
		int a;
		cin >> t >> a;
		if (t=='+')
		m[a]++,insert(convert(a,2));
		else if (t=='-')
		{
			m[a]--;
			if (!m[a])
			erase(convert(a,2));
		}
		else
		cout << solve(convert(a,2)) << endl;
	}
}