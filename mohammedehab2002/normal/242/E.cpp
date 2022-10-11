#include <iostream>
using namespace std;
long long arr[100005],tree[500005][25];
bool lazy[500005][25];
void build(int node,int start,int end,int b)
{
    if (start==end)
    tree[node][b]=(bool)(arr[start]&(1<<b));
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid,b);
        build(2*node+1,mid+1,end,b);
        tree[node][b]=tree[2*node][b]+tree[2*node+1][b];
    }
}
void updateRange(int node,int start,int end,int l,int r,int b)
{
    if (lazy[node][b])
    {
        tree[node][b]=(end-start+1)-tree[node][b];
        if (start!=end)
        {
            lazy[node*2][b]^=1;
            lazy[node*2+1][b]^=1;
        }
        lazy[node][b]=0;
    }
    if (start>end || start>r || end<l)
    return;
    if (start>=l && end<=r)
    {
        tree[node][b]=(end-start+1)-tree[node][b];
        if (start!=end)
        {
            lazy[node*2][b]^=1;
            lazy[node*2+1][b]^=1;
        }
        return;
    }
    int mid=(start+end)/2;
    updateRange(node*2,start,mid,l,r,b);
    updateRange(node*2+1,mid+1,end,l,r,b);
    tree[node][b]=tree[node*2][b]+tree[node*2+1][b];
}
long long queryRange(int node,int start,int end,int l,int r,int b)
{
    if (start>end || start>r || end<l)
    return 0;
    if (lazy[node][b]!=0)
    {
        tree[node][b]=(end-start+1)-tree[node][b];
        if (start!=end)
        {
            lazy[node*2][b]^=1;
            lazy[node*2+1][b]^=1;
        }
        lazy[node][b]=0;
    }
    if (start>= l && end<=r)
    return tree[node][b];
    int mid=(start+end)/2;
    long long p1=queryRange(node*2,start,mid,l,r,b),p2=queryRange(node*2+1,mid+1,end,l,r,b);
    return (p1+p2);
}
int main()
{
	int n,q;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=0;i<25;i++)
	build(1,0,n-1,i);
	scanf("%d",&q);
	while (q--)
	{
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);
		a--,b--;
		if (t==1)
		{
			long long ans=0;
			for (int i=0;i<25;i++)
			ans+=queryRange(1,0,n-1,a,b,i)*(1<<i);
			printf("%I64d\n",ans);
		}
		else
		{
			int val;
			scanf("%d",&val);
			for (int i=0;i<25;i++)
			{
				if ((val&(1<<i)))
				updateRange(1,0,n-1,a,b,i);
			}
		}
	}
}