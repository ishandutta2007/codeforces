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
	int l[11],r[11];
	int sum;
}tree[500005];
int n,m,q,mp[15][100005],tot=1,num;
int fa[1000005];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
segtree pushup(segtree x,segtree y,int mid)
{
	//cout<<"ok";
	segtree temp;
	temp.sum=x.sum+y.sum;
	for(int i=1;i<=n;i++)
	{
		fa[x.l[i]]=x.l[i];
		fa[y.l[i]]=y.l[i];
		fa[x.r[i]]=x.r[i];
		fa[y.r[i]]=y.r[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[i][mid]==mp[i][mid+1])
		{
			if(find(x.r[i])!=find(y.l[i]))
			{
				temp.sum--;
				merge(x.r[i],y.l[i]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		temp.l[i]=find(x.l[i]);
		temp.r[i]=find(y.r[i]);
	}
	return temp;
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		for(int i=1;i<=n;i++)
		{
			if(mp[i-1][l]==mp[i][l])
			{
				tree[p].l[i]=tree[p].r[i]=tree[p].l[i-1];
			}
			else
			{
				num++;
				tree[p].l[i]=tree[p].r[i]=num;
				tree[p].sum++;
			}
		}
		return;
	}
	int mid=l+r>>1;
	tree[p].ls=++tot;
	tree[p].rs=++tot;
	build(tree[p].ls,l,mid);
	build(tree[p].rs,mid+1,r);
	int temp1=tree[p].ls,temp2=tree[p].rs;
	tree[p]=pushup(tree[tree[p].ls],tree[tree[p].rs],mid);
	tree[p].ls=temp1;tree[p].rs=temp2;
}
segtree query(int p,int l,int r,int x,int y)
{
	
	int mid=l+r>>1;
	if(l==x&&r==y)
	{
		return tree[p];
	}
	if(y<=mid) return query(tree[p].ls,l,mid,x,y);
	else if(x>mid) return query(tree[p].rs,mid+1,r,x,y);
	else
	{//cout<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
	//cout<<tree[p].ls<<endl;
		return pushup(query(tree[p].ls,l,mid,x,mid),query(tree[p].rs,mid+1,r,mid+1,y),mid);
	}
}
int main()
{
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			mp[i][j]=read();
		}
	}
	build(1,1,m);
	while(q--)
	{
		int x=read(),y=read();
		printf("%d\n",query(1,1,m,x,y).sum);
	}
}