#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
struct segtree
{
	int ls;
	int rs;
	int maxx;
	int mark;
}tree[2000005];
int cnt=1;
void build(int p,int l,int r)
{
	int mid=l+r>>1;
	if(l==r) return;
	tree[p].ls=++cnt;
	tree[p].rs=++cnt;
	build(tree[p].ls,l,mid);
	build(tree[p].rs,mid+1,r);
}
void modify(int p,int l,int r,int x,int y,int z)
{
	int mid=l+r>>1;
	if(l==x&&r==y)
	{
		tree[p].maxx+=z;
		tree[p].mark+=z;
		return;
	}
	if(tree[p].mark)
	{
		tree[tree[p].ls].mark+=tree[p].mark;
		tree[tree[p].rs].mark+=tree[p].mark;
		tree[tree[p].ls].maxx+=tree[p].mark;
		tree[tree[p].rs].maxx+=tree[p].mark;
		tree[p].mark=0;
	}
	if(y<=mid) modify(tree[p].ls,l,mid,x,y,z);
	else if(x>mid) modify(tree[p].rs,mid+1,r,x,y,z);
	else modify(tree[p].ls,l,mid,x,mid,z),modify(tree[p].rs,mid+1,r,mid+1,y,z);
	tree[p].maxx=max(tree[tree[p].ls].maxx,tree[tree[p].rs].maxx);
}
int pla[500005],a[500005],n,ans;
int main()
{
	n=read();
	ans=n;
	for(int i=1;i<=n;i++) a[i]=read(),pla[a[i]]=i;
	cout<<n<<" ";
	build(1,1,n);
	modify(1,1,n,1,pla[n],1);
	for(int i=1;i<n;i++)
	{
		modify(1,1,n,1,read(),-1);
		while(tree[1].maxx<=0)
		{
			ans--;
			modify(1,1,n,1,pla[ans],1);
		}
		printf("%d ",ans);
	}
}