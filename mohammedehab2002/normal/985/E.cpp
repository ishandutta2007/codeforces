#include <iostream>
#include <algorithm>
using namespace std;
int tree[2000005];
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
        tree[node]=(tree[2*node]|tree[2*node+1]);
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
    return (p1|p2);
}
int arr[500005];
int main()
{
	int n,k,d;
	scanf("%d%d%d",&n,&k,&d);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	sort(arr+1,arr+n+1);
	update(1,0,n,0,1);
	for (int i=1;i<=n;i++)
	{
		int l=lower_bound(arr+1,arr+n+1,arr[i]-d)-arr,r=i-k+1;
		if (l<=r)
		update(1,0,n,i,query(1,0,n,l-1,r-1));
	}
	if (query(1,0,n,n,n))
	printf("YES");
	else
	printf("NO");
}