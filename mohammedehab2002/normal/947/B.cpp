#include <iostream>
using namespace std;
int arr[100005],t[100005];
long long cum[100005];
int tree[400005],lazy[400005];
void updateRange(int node,int start,int end,int l,int r,int val)
{
    if (lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if (start!=end)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if (start>end || start>r || end<l)
    return;
    if (start>=l && end<=r)
    {
        tree[node]+=(end-start+1)*val;
        if (start!=end)
        {
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }
    int mid=(start+end)/2;
    updateRange(node*2,start,mid,l,r,val);
    updateRange(node*2+1,mid+1,end,l,r,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int queryRange(int node,int start,int end,int l,int r)
{
    if (start>end || start>r || end<l)
    return 0;
    if (lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if (start!=end)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if (start>=l && end<=r)
    return tree[node];
    int mid=(start+end)/2;
    int p1=queryRange(node*2,start,mid,l,r);
    int p2=queryRange(node*2+1,mid+1,end,l,r);
    return (p1+p2);
}
long long ans[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=0;i<n;i++)
	scanf("%d",&t[i]);
	for (int i=1;i<=n;i++)
	cum[i]=cum[i-1]+t[i-1];
	for (int i=0;i<n;i++)
	{
		int st=i,en=n;
		while (st!=en)
		{
			int mid=(st+en)/2;
			if (cum[mid+1]-cum[i]<arr[i])
			st=mid+1;
			else
			en=mid;
		}
		if (i!=st)
		updateRange(1,0,n-1,i,st-1,1);
		ans[st]+=arr[i]-(cum[st]-cum[i]);
	}
	for (int i=0;i<n;i++)
	printf("%I64d ",ans[i]+(long long)queryRange(1,0,n-1,i,i)*t[i]);
}