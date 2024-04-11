#include <iostream>
using namespace std;
int cnt[100005],tree[400005][2];
void update(int node,int start,int end,int idx,int val,int t)
{
    if (start==end)
    tree[node][t]=max(tree[node][t],val);
    else
    {
        int mid=(start+end)/2;
        if (start<=idx && idx<=mid)
        update(2*node,start,mid,idx,val,t);
        else
        update(2*node+1,mid+1,end,idx,val,t);
        tree[node][t]=max(tree[2*node][t],tree[2*node+1][t]);
    }
}
int query(int node,int start,int end,int l,int r,int t)
{
    if (r<start || end<l)
    return 0;
    if (l<=start && end<=r)
    return tree[node][t];
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r,t);
    int p2=query(2*node+1,mid+1,end,l,r,t);
    return max(p1,p2);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		cnt[a]++;
		cnt[b+1]--;
	}
	for (int i=1;i<=m;i++)
	cnt[i]+=cnt[i-1];
	for (int i=1;i<=m;i++)
	{
		update(1,0,n,cnt[i],query(1,0,n,0,cnt[i],0)+1,0);
		update(1,0,n,cnt[i],query(1,0,n,cnt[i],n,1)+1,1);
		update(1,0,n,cnt[i],query(1,0,n,cnt[i],cnt[i],0),1);
	}
	printf("%d",max(query(1,0,n,0,n,0),query(1,0,n,0,n,1)));
}