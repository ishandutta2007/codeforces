#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define f first
#define s second
map<int,int> m;
pair<int,int> arr[200005];
int tree[1600005];
void update(int node,int start,int end,int idx,int val)
{
    if (start==end)
    tree[node]=max(tree[node],val);
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
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&arr[i].first,&arr[i].second);
		m[arr[i].f+arr[i].s];
		m[arr[i].f-arr[i].s];
	}
	int cur=0;
	for (map<int,int>::iterator it=m.begin();it!=m.end();it++)
	it->second=cur++;
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	{
		int x=query(1,0,2*n,0,m[arr[i].f-arr[i].s]);
		update(1,0,2*n,m[arr[i].f+arr[i].s],x+1);
	}
	printf("%d",query(1,0,2*n,0,2*n));
}