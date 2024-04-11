#include <iostream>
#include <vector>
using namespace std;
#define C 10
#define MAX 5670005
int ind(char c)
{
	return c-'0';
}
char s[70005][10];
int trie[MAX][C],en[MAX],cn;
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
		en[node]++;
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
		en[v[i]]--;
		if (!en[v[i]])
		trie[v[i-1]][ind(s[i-1])]=0;
	}
}
int go(int ind_s,int ind2)
{
	int node=0;
	for (int i=ind_s;i<9;i++)
	{
		if (trie[node][ind(s[ind2][i])])
		node=trie[node][ind(s[ind2][i])];
		else
		return i-ind_s+1;
	}
	return (1<<20);
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for (int i=0;i<n;i++)
	{
		gets(s[i]);
		for (int x=0;x<9;x++)
		{
			string tmp="";
			for (int j=x;j<9;j++)
			{
				tmp=tmp+s[i][j];
				insert(tmp);
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<9;x++)
		{
			string tmp="";
			for (int j=x;j<9;j++)
			{
				tmp=tmp+s[i][j];
				erase(tmp);
			}
		}
		int st=0,ans=9;
		for (int x=0;x<9;x++)
		{
			int j=go(x,i);
			if (j<ans)
			{
				st=x;
				ans=j;
			}
		}
		for (int x=0;x<9;x++)
		{
			string tmp="";
			for (int j=x;j<9;j++)
			{
				tmp=tmp+s[i][j];
				insert(tmp);
			}
		}
		for (int x=st;x<st+ans;x++)
		putchar(s[i][x]);
		printf("\n");
	}
}