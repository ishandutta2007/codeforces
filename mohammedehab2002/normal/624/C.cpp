#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
bool mat[505][505];
int cnt[505],n;
string s;
char cur='a';
vector<int> q;
void dfs(int node)
{
	if (s[node-1]!='d')
	return;
	for (int i=0;i<q.size();i++)
	{
		if (!mat[q[i]][node])
		{
			printf("NO");
			exit(0);
		}
	}
	q.push_back(node);
	s[node-1]=cur;
	for (int i=1;i<=n;i++)
	{
		if (mat[node][i])
		dfs(i);
	}
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		mat[a][b]=1;
		mat[b][a]=1;
		cnt[a]++;
		cnt[b]++;
	}
	s=string(n,'d');
	for (int i=1;i<=n;i++)
	{
		if (cnt[i]==n-1)
		s[i-1]='b';
	}
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='d')
		{
			if (cur=='e')
			{
				printf("No");
				return 0;
			}
			q.clear();
			dfs(i);
			cur+=2;
		}
	}
	printf("Yes\n%s",s.c_str());
}