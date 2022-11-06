#include <bits/stdc++.h>
using namespace std;

const int INF=1e9+1;
int tree[800005],a[1000005],ans[1000005];
int n,nn;

int change(int nn)
{
	int n=1;
	while(n<nn)n*=2;
	return n;
}

void build(int l,int r,int node)
{
	if(l==r)tree[node]=a[l];
	else
	{
		int mid=(l+r)/2;
		build(l,mid,node*2);
		build(mid+1,r,node*2+1);
		tree[node]=min(tree[node*2],tree[node*2+1]);
	}
}

void Search(int l,int r,int node,int x,int k)
{
	if(node>=nn*2)return;
	if(l==r&&a[l]<x)
	{
		ans[k]=max(ans[k],l);
//		cout<<a[l]<<endl;
		return;
	}
	int sl=node*2,sr=node*2+1,mid=(l+r)/2;
	if(x>tree[sr])Search(mid+1,r,sr,x,k);
	else Search(l,mid,sl,x,k);
}

void update(int k,int x)
{
	k+=nn-1;
	tree[k]=x;

	while(k>0)
	{
		k=(k-1)/2;
		tree[k]=min(tree[k*2],tree[k*2+1]);
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],ans[i]=i;
	nn=change(n);
	for(int i=n+1;i<=nn;i++)a[i]=INF;
	build(1,nn,1);
	for(int i=1;i<=n;i++)
	{
		Search(1,nn,1,a[i],i);
		if(ans[i]==i)cout<<-1<<" ";
		else cout<<ans[i]-i-1<<" ";
		update(i,INF);
	}
	return 0;
}