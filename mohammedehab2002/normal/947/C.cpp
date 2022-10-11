#include <iostream>
using namespace std;
int trie[9000005][2],cnt[9000005],cn;
void insert(int x)
{
	int cur=0;
	for (int i=30;i>=0;i--)
	{
		bool b=(x&(1<<i));
		if (trie[cur][b])
		cur=trie[cur][b];
		else
		{
			trie[cur][b]=++cn;
			cur=cn;
		}
		cnt[cur]++;
	}
}
int go(int x)
{
	int cur=0,ans=0;
	for (int i=30;i>=0;i--)
	{
		bool b=(x&(1<<i));
		if (trie[cur][b] && cnt[trie[cur][b]])
		cur=trie[cur][b];
		else
		{
			cur=trie[cur][!b];
			ans^=(1<<i);
		}
	}
	return ans;
}
void erase(int node,int x,int d)
{
	int cur=0;
	for (int i=30;i>=0;i--)
	{
		bool b=(x&(1<<i));
		cur=trie[cur][b];
		cnt[cur]--;
	}
}
int arr[300005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int x=0;x<n;x++)
	{
		int a;
		scanf("%d",&a);
		insert(a);
	}
	for (int i=0;i<n;i++)
	{
		printf("%d ",go(arr[i]));
		erase(0,(go(arr[i])^arr[i]),30);
	}
}