#include <iostream>
using namespace std;
int op=0;
int tree[(1<<19)+5];
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
        if (op)
        tree[node]=(tree[2*node]^tree[2*node+1]);
        else
        tree[node]=(tree[2*node]|tree[2*node+1]);
        op^=1;
    }
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	n=(1<<n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		op=0;
		update(1,0,n-1,i,a);
	}
	while (q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		op=0;
		update(1,0,n-1,a-1,b);
		printf("%d\n",tree[1]);
	}
}