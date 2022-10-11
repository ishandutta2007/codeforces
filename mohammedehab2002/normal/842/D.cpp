#include <iostream>
using namespace std;
bool b[(1<<19)];
int trie[19*(1<<19)][2],cn;
void insert(int x)
{
	int cur=0;
	for (int i=18;i>=0;i--)
	{
		bool b=(x&(1<<i));
		if (!trie[cur][b])
		trie[cur][b]=++cn;
		cur=trie[cur][b];
	}
}
int go(int x)
{
	int cur=0,ans=0;
	for (int i=18;i>=0;i--)
	{
		bool b=(x&(1<<i));
		if (!trie[cur][b])
		{
			ans|=(1<<i);
			b=!b;
		}
		cur=trie[cur][b];
	}
	return ans;
}
int main()
{
	int n,m,cum=0;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		b[a]=1;
	}
	for (int i=0;i<(1<<19);i++)
	{
		if (!b[i])
		insert(i);
	}
	while (m--)
	{
		int x;
		scanf("%d",&x);
		cum^=x;
		printf("%d\n",go(cum));
	}
}