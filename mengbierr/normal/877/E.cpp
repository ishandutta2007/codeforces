#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
struct node
{
	int from;
	int to;
	int next;
	int w;
}edge[500005];
struct segtree
{
	int ls;
	int rs;
	int sum;
	int mark;
}tree[800005];
int tot=1,head[200005],a[200005],size[200005];
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
int fa[200005],pos[200005],npos[200005];
int cnt;
void dfs(int x)
{
	size[x]=1;
	pos[x]=++cnt;npos[cnt]=x;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(fa[x]!=edge[i].to)
		{
			dfs(edge[i].to);
			size[x]+=size[edge[i].to];
		}
	}
}
void build(int p,int l,int r)
{
	int mid=l+r>>1;
	if(l==r)
	{
		tree[p].sum=a[npos[l]];
		return;
	}
	tree[p].ls=++tot;
	tree[p].rs=++tot;
	build(tree[p].ls,l,mid);
	build(tree[p].rs,mid+1,r);
	tree[p].sum=tree[tree[p].ls].sum+tree[tree[p].rs].sum;
}
void modify(int p,int l,int r,int x,int y)
{
	int mid=l+r>>1;
	if(l==x&&r==y)
	{
		tree[p].mark^=1;
		tree[p].sum=r-l+1-tree[p].sum;
		return;
	}
	if(tree[p].mark)
	{
		tree[tree[p].ls].mark^=1;
		tree[tree[p].rs].mark^=1;
		tree[tree[p].ls].sum=mid-l+1-tree[tree[p].ls].sum;
		tree[tree[p].rs].sum=r-mid-tree[tree[p].rs].sum;
		tree[p].mark=0;
	}
	if(y<=mid) modify(tree[p].ls,l,mid,x,y);
	else if(x>mid) modify(tree[p].rs,mid+1,r,x,y);
	else
	{
		modify(tree[p].ls,l,mid,x,mid);
		modify(tree[p].rs,mid+1,r,mid+1,y);
	}
	tree[p].sum=tree[tree[p].ls].sum+tree[tree[p].rs].sum;
}
int query(int p,int l,int r,int x,int y)
{
	int mid=l+r>>1;
	if(l==x&&r==y)
	{
		return tree[p].sum;
	}
	if(tree[p].mark)
	{
		tree[tree[p].ls].mark^=1;
		tree[tree[p].rs].mark^=1;
		tree[tree[p].ls].sum=mid-l+1-tree[tree[p].ls].sum;
		tree[tree[p].rs].sum=r-mid-tree[tree[p].rs].sum;
		tree[p].mark=0;
	}
	if(y<=mid) return query(tree[p].ls,l,mid,x,y);
	else if(x>mid) return query(tree[p].rs,mid+1,r,x,y);
	else return query(tree[p].ls,l,mid,x,mid)+query(tree[p].rs,mid+1,r,mid+1,y);
}
int main()
{
	memset(head,-1,sizeof(head));
	int n=read(),q;
	for(int i=2;i<=n;i++)
	{
		fa[i]=read();
		add(i,fa[i]);
		add(fa[i],i);
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	q=read();
	dfs(1);
	//for(int i=1;i<=n;i++)
	//printf("%d ",pos[i]);
	build(1,1,n);
	char s[15];
	while(q--)
	{
		scanf("%s",s+1);
		if(s[1]=='g')
		{
			int x=read();
			printf("%d\n",query(1,1,n,pos[x],pos[x]+size[x]-1));
		}
		else
		{
			int x=read();
			//cout<<pos[x]<<" "<<pos[x]+size[x]-1<<endl;
			modify(1,1,n,pos[x],pos[x]+size[x]-1);
		}
	}
}
/*
10
1 2 3 4 2 4 1 7 8
1 1 0 1 1 0 0 0 1 1
10
pow 1
get 2
pow 2
pow 8
get 6
pow 6
pow 10
get 6
pow 8
pow 3
*/