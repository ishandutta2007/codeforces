#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
long long lazy[888888],tree[888888];
long long n,m,a[222222],l,r,x;
char s[111];
void build(int l,int r,int node)
{
	if (l==r) 
	{
		tree[node]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}
void addtree(int beg,int en,int l,int r,int node)
{
	if (beg>r || en<l) return;
	if (beg>=l && en<=r) 
	{
		lazy[node]+=x;
		return;
	}
	int mid=(beg+en)/2;
	addtree(beg,mid,l,r,node*2);
	addtree(mid+1,en,l,r,node*2+1);
	tree[node]=min(tree[node*2]+lazy[node*2],tree[node*2+1]+lazy[node*2+1]);
}
long long getmin(int beg,int en,int l,int r,int node)
{
	if (beg>r || en<l) return 1e18;
	if (beg>=l && en<=r) return tree[node]+lazy[node];
	int mid=(beg+en)/2;
	return min(getmin(beg,mid,l,r,node*2),getmin(mid+1,en,l,r,node*2+1))+lazy[node];
}
int main()
{
	scanf("%I64d",&n);
	for (int i=0;i<n;i++) scanf("%I64d",&a[i]);
	build(0,n-1,1);
	scanf("%I64d\n",&m);
	while(m--)
	{
		gets(s);
		if (sscanf(s,"%I64d%I64d%I64d",&l,&r,&x)==3)
		{
			if (l<=r) addtree(0,n-1,l,r,1);
			else
			{
				addtree(0,n-1,l,n-1,1);
				addtree(0,n-1,0,r,1);
			}
		}
		else
		{
			if (l<=r) cout<<getmin(0,n-1,l,r,1)<<endl;
			else cout<<min(getmin(0,n-1,l,n-1,1),getmin(0,n-1,0,r,1))<<endl;
		}
	}
	return 0;
}