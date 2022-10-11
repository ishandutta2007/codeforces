#include <iostream>
#include <algorithm>
using namespace std;
int tree[400005];
void update(int node,int start,int end,int idx,int val)
{
    if (start==end)
    tree[node]=val;
    else
    {
        int mid=(start+end)/2;
        if (start<=idx && idx<=mid)
        update(2*node,start,mid,idx,val);
        else
        update(2*node+1,mid+1,end,idx,val);
        tree[node]=max(tree[2*node],tree[2*node+1]);
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
    return max(p1,p2);
}
int main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		int x=query(1,0,n,0,a-1)+1;
		ans=max(ans,x);
		update(1,0,n,a,x);
	}
	printf("%d",ans);
}