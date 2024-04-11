#include <iostream>
using namespace std;
int k,arr[1000005],trie[30000005][2],cnt[30000005],cn;
void insert(int x)
{
	int cur=0;
	for (int i=29;i>=0;i--)
	{
		bool b=(x&(1<<i));
		if (!trie[cur][b])
		trie[cur][b]=++cn;
		cur=trie[cur][b];
		cnt[cur]++;
	}
}
void erase(int x)
{
	int cur=0;
	for (int i=29;i>=0;i--)
	{
		bool b=(x&(1<<i));
		cur=trie[cur][b];
		cnt[cur]--;
	}
}
int go(int x)
{
	int cur=0,ret=0;
	for (int i=29;i>=0;i--)
	{
		bool b=(x&(1<<i)),bk=(k&(1<<i));
		if (!bk)
		ret+=cnt[trie[cur][!b]];
		cur=trie[cur][b^bk];
		if (!cur)
		return ret;
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	k--;
	long long ans=0;
	int x=0;
	for (int i=0;i<n;i++)
	{
		insert(x);
		x^=arr[i];
		ans+=go(x);
	}
	printf("%I64d",ans);
}