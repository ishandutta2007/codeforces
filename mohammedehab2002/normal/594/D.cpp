#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
#define mod 1000000007
vector<pair<pair<int,int>,int> > v;
vector<int> d[1000005],q[1000005];
long long tree[800005],cum[200005],res[200005];
int arr[200005];
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
void update(int node,int st,int en,int idx,int val)
{
	if (st==en)
	{
		tree[node]=(tree[node]*(val-1))%mod;
		tree[node]=(tree[node]*pow_log(val,mod-2))%mod;
	}
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx,val);
		else
		update(2*node+1,mid+1,en,idx,val);
		tree[node]=(tree[2*node]*tree[2*node+1])%mod;
	}
}
long long query(int node,int st,int en,int l,int r)
{
	if (st>r || en<l || r<l)
	return 1;
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return (query(2*node,st,mid,l,r)*query(2*node+1,mid+1,en,l,r))%mod;
}
bool pr[1000005];
int main()
{
	for (int i=2;i<=1000000;i++)
	{
		if (!pr[i])
		{
			for (int x=i;x<=1000000;x+=i)
			{
				pr[x]=1;
				d[x].push_back(i);
			}
		}
	}
	int n;
	scanf("%d",&n);
	cum[0]=1;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		arr[i]=a;
		cum[i+1]=(cum[i]*a)%mod;
		for (int x:d[a])
		q[x].push_back(i);
	}
	for (int i=0;i<4*n+5;i++)
	tree[i]=1;
	for (int i=2;i<=1000000;i++)
	{
		if (q[i].empty())
		continue;
		update(1,0,n-1,q[i][0],i);
		reverse(q[i].begin(),q[i].end());
	}
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		v.push_back({{l,r},i});
	}
	sort(v.begin(),v.end());
	int po=0;
	for (auto p:v)
	{
		int l=p.first.first,r=p.first.second;
		while (po<l-1)
		{
			for (int x:d[arr[po]])
			{
				q[x].pop_back();
				if (!q[x].empty())
				update(1,0,n-1,q[x].back(),x);
			}
			po++;
		}
		long long ans=(cum[r]*pow_log(cum[l-1],mod-2))%mod;
		ans=(ans*query(1,0,n-1,l-1,r-1))%mod;
		res[p.second]=ans;
	}
	for (int i=0;i<m;i++)
	printf("%I64d\n",res[i]);
}