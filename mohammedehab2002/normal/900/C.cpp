#include <iostream>
using namespace std;
int tree[400005];
void update(int node,int start,int end,int idx,int val)
{
    if (start==end)
    tree[node]+=val;
    else
    {
        int mid=(start+end)/2;
        if (start<=idx && idx<=mid)
        update(2*node,start,mid,idx,val);
        else
        update(2*node+1,mid+1,end,idx,val);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
int query(int node,int start,int end,int l,int r)
{
    if (r<start || end<l)
    return 0;
    if (l<=start && end<=r)
    return tree[node];
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);
    return (p1+p2);
}
int bad[100005],rec[100005];
int main()
{
	int n,mx=0,rs=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		int cur=query(1,0,n,0,a-1);
		if (cur==i-1)
		bad[mx]++;
		if (cur==i)
		{
			rs++;
			rec[a]=1;
		}
		update(1,0,n,a,1);
		mx=max(mx,a);
	}
	int ans=-1,best=-1;
	for (int i=1;i<=n;i++)
	{
		if (rs+bad[i]-rec[i]>ans)
		{
			ans=rs+bad[i]-rec[i];
			best=i;
		}
	}
	printf("%d",best);
}