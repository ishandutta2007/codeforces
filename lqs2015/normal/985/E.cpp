#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,d,a[555555],sz,cur;
bool dp[555555],tree[2222222];
void update(int x)
{
	int pos=sz-1+x;
	while(pos>=1)
	{
		tree[pos]|=1;
		pos/=2;
	}
}
bool query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) return tree[node];
	int mid=(l+r)/2;
	return query(beg,en,l,mid,node*2)|query(beg,en,mid+1,r,node*2+1);
}
int main()
{
	scanf("%d%d%d",&n,&k,&d);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	sz=1;
	while(sz<=n) sz*=2;
	dp[0]=1;
	update(1);
	for (int i=k;i<=n;i++)
	{
		cur=lower_bound(a+1,a+n+1,a[i]-d)-a;
		dp[i]=query(cur,i-k+1,1,sz,1);
		if (dp[i]) update(i+1);
	}
	if (dp[n]) printf("YES\n");
	else printf("NO\n");
	return 0;
}