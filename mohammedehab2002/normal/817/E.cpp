#include <iostream>
using namespace std;
int trie[3000000][2],cnt[3000000],cn;
void add(int p,int a)
{
	int cur=0;
	for (int i=28;i>=0;i--)
	{
		bool b=(p&(1<<i));
		if (!trie[cur][b])
		trie[cur][b]=++cn;
		cur=trie[cur][b];
		cnt[cur]+=a;
	}
}
int go(int p,int l)
{
	int cur=0,ans=0;
	for (int i=28;i>=0;i--)
	{
		bool b=(p&(1<<i)),b2=(l&(1<<i));
		if (b2 && trie[cur][b])
		ans+=cnt[trie[cur][b]];
		if (!trie[cur][b^b2])
		return ans;
		cur=trie[cur][b^b2];
	}
	return ans;
}
int main()
{
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int t,p;
		scanf("%d%d",&t,&p);
		if (t==3)
		{
			int l;
			scanf("%d",&l);
			printf("%d\n",go(p,l));
		}
		else
		add(p,-2*t+3);
	}
}