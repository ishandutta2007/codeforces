#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int x,int y)
{
	if (!x)
	return y;
	if (!y)
	return x;
	return __gcd(x,y);
}
int tree[2000005],n;
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
        tree[node]=gcd(tree[2*node],tree[2*node+1]);
    }
}
int query(int node,int start,int end,int l,int r,int x)
{
    if (r<start || end<l)
    return 0;
    if (l<=start && end<=r)
    {
    	if (tree[node]%x)
    	return 1;
    	return 0;
	}
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r,x);
    int p2=query(2*node+1,mid+1,end,l,r,x);
    return p1+p2;
}
bool go(int node,int start,int end,int l,int r,int x)
{
    if (r<start || end<l)
    return 1;
    if (l<=start && end<=r)
    {
    	if (start==end)
    	return 1;
    	if (tree[node]%x==0)
    	return 1;
    	if (tree[2*node]%x && tree[2*node+1]%x)
    	return 0;
	}
    int mid=(start+end)/2;
    bool p1=go(2*node,start,mid,l,r,x);
    bool p2=go(2*node+1,mid+1,end,l,r,x);
    return (p1 && p2);
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		update(1,0,n-1,i,a);
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);
		if (t==1)
		{
			int x;
			scanf("%d",&x);
			int y=query(1,0,n-1,a-1,b-1,x);
			if (!y)
			printf("YES\n");
			else if (y==1)
			{
				if (go(1,0,n-1,a-1,b-1,x))
				printf("YES\n");
				else
				printf("NO\n");
			}
			else
			printf("NO\n");
		}
		else
		update(1,0,n-1,a-1,b);
	}
}