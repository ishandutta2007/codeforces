#include <iostream>
#include <set>
using namespace std;
int cnt[1000005],lp[1000005],arr[300005];
long long tree[2000005];
void update(int node,int start,int end,int idx,int val)
{
    if (start==end)
    {
    	arr[idx]=val;
    	tree[node]=val;
    }
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
long long query(int node,int start,int end,int l,int r)
{
    if (r<start || end<l)
    return 0;
    if (l<=start && end<=r)
    return tree[node];
    int mid=(start+end)/2;
    long long p1=query(2*node,start,mid,l,r);
    long long p2=query(2*node+1,mid+1,end,l,r);
    return (p1+p2);
}
int main()
{
	set<int> s;
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		update(1,0,n-1,i,arr[i]);
		if (arr[i]>2)
		s.insert(i);
	}
	s.insert(n);
	cnt[1]=1;
	lp[1]=1;
	for (int i=2;i<=1000000;i++)
	{
		if (!lp[i])
		{
		    for (int x=i;x<=1000000;x+=i)
		    {
		        if (!lp[x])
		        lp[x]=i;
		    }
		}
		int tmp=i,c=1;
		while (lp[tmp]==lp[i])
		{   
		    tmp/=lp[tmp];
		    c++;
		}
		cnt[i]=cnt[tmp]*c;
	}
	while (q--)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		l--;
		r--;
		if (t==1)
		{
			while (1)
			{
				set<int>::iterator it=s.lower_bound(l);
				int idx=*it;
				if (idx>r)
				break;
				update(1,0,n-1,idx,cnt[arr[idx]]);
				if (arr[idx]==2)
				s.erase(it);
				l=idx+1;
			}
		}
		else
		printf("%I64d\n",query(1,0,n-1,l,r));
	}
}