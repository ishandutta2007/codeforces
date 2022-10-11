#include <iostream>
using namespace std;
pair<int,int> tree[400005];
void update(int node,int st,int en,int idx,int val)
{
	if (st==en)
	tree[node]={val,st};
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx,val);
		else
		update(2*node+1,mid+1,en,idx,val);
		tree[node]=max(tree[2*node],tree[2*node+1]);
	}
}
pair<int,int> query(int node,int st,int en,int l,int r)
{
	if (en<l || st>r || r<l)
	return {0,0};
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return max(query(2*node,st,mid,l,r),query(2*node+1,mid+1,en,l,r));
}
int arr[100005];
long long dp[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	scanf("%d",&arr[i]);
	long long sum=0;
	for (int i=n-1;i>0;i--)
	{
		if (arr[i]==n)
		dp[i]=n-i;
		else
		{
			int idx=query(1,1,n,i+1,arr[i]).second;
			dp[i]=dp[idx]+n-i-arr[i]+idx;
		}
		sum+=dp[i];
		update(1,1,n,i,arr[i]);
	}
	printf("%I64d",sum);
}