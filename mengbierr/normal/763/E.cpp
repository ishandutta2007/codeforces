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
int s[600005];int val[600005],ch[600005][2],fa[600005];
int n,m,k,Q,st[600005],top,maxx[600005],maxpla[600005],ans[600005];
int numx[600005],numy[600005];bool rev[600005];
struct data
{
	int x,y,id;
}a[500005];
struct que
{
	int id,x,y;
}q[500005];
bool cmp(const que &x,const que &y)
{
	return x.x>y.x;
}
bool cmp1(const data &x,const data &y)
{
	return x.x>y.x;
}
int lowbit(int x)
{
	return x&(-x);
}
int query(int x)
{
	int sum=0;
	for(int i=x;i;i-=lowbit(i))
	{
		sum+=s[i];
	}
	return sum;
}
void modify(int x,int y)
{
	for(int i=x;i<=n+m;i+=lowbit(i))
	{
		s[i]+=y;
	}
}

bool isroot(int x)
{
	return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;
}
void pushdown(int x)
{
	if(rev[x])
	{
		rev[x]=0;
		rev[ch[x][0]]^=1;rev[ch[x][1]]^=1;
		swap(ch[x][0],ch[x][1]);
	}
}
void update(int x)
{
	int pla,ma;
	if(maxx[ch[x][0]]>maxx[ch[x][1]])
	{
		ma=maxx[ch[x][0]];pla=maxpla[ch[x][0]];
	}
	else
	{
		ma=maxx[ch[x][1]];pla=maxpla[ch[x][1]];
	}
	if(ma>val[x])
	{
		maxpla[x]=pla;maxx[x]=ma;
	}
	else
	{
		maxx[x]=val[x];maxpla[x]=x;
	}
}
void rotate(int x)
{
	int y=fa[x],z=fa[y],l,r;
	if(ch[y][0]==x) l=0;else l=1;r=l^1;
	if(!isroot(y))
	{
		if(ch[z][0]==y) ch[z][0]=x;
		else ch[z][1]=x;
	}
	fa[y]=x;fa[x]=z;fa[ch[x][r]]=y;
	ch[y][l]=ch[x][r];ch[x][r]=y;
	update(y);update(x);
}
void splay(int x)
{
	top=0;
	st[++top]=x;
	for(int i=x;!isroot(i);i=fa[i])
	st[++top]=fa[i];
	while(top) pushdown(st[top--]);
	while(!isroot(x))
	{
		int y=fa[x],z=fa[y];
		if(!isroot(y))
		{
			if(ch[z][0]==y^ch[y][0]==x) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}
void access(int x)
{
	for(int t=0;x;t=x,x=fa[x])
	{
		splay(x);ch[x][1]=t;update(x);
	}
}
void makeroot(int x)
{
	access(x);splay(x);rev[x]^=1;
}
void link(int x,int y)
{
	makeroot(x);fa[x]=y;
}
void cut(int x,int y)
{
	makeroot(x);access(y);splay(y);
	fa[x]=ch[y][0]=0;update(y);
}
int findroot(int x)
{
	splay(x);
	while(ch[x][0]) x=ch[x][0];
	return x;
}
bool find(int x,int y)
{
	makeroot(x);
	access(y);
	return findroot(y)==x;
}
int main()
{
	n=read();k=read();m=read();
	for(int i=1;i<=n;i++)
	maxpla[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if(u>v) swap(u,v);
		a[i].x=u;a[i].y=v;
		a[i].id=i;
		val[i+n]=v;
		maxx[i+n]=v;
		maxpla[i+n]=i+n;
		numx[i]=u;numy[i]=v;
	}
	Q=read();
	for(int i=1;i<=Q;i++)
	{
		q[i].x=read();q[i].y=read();
		q[i].id=i;
	}
	sort(q+1,q+Q+1,cmp);
	sort(a+1,a+m+1,cmp1);
	int l1=1,l2=1;
	for(int i=n;i;i--)
	{
		while(l2<=m&&a[l2].x==i)
		{
			//cout<<a[l2].x<<" "<<a[l2].y<<endl; 
			if(!find(a[l2].x,a[l2].y))
			{
				link(a[l2].x,a[l2].id+n);
				link(a[l2].y,a[l2].id+n);
				modify(a[l2].y,1);
			}
			else
			{
				if(a[l2].y<maxx[a[l2].y])
				{
					modify(a[l2].y,1);
					modify(maxx[a[l2].y],-1);
					int temp=maxpla[a[l2].y];
					cut(temp,numx[temp-n]);
					cut(temp,numy[temp-n]);
					link(a[l2].x,a[l2].id+n);
					link(a[l2].y,a[l2].id+n);
				}
			}
			l2++;
		}
		while(l1<=Q&&q[l1].x==i)
		{
			ans[q[l1].id]=q[l1].y-q[l1].x+1-query(q[l1].y);
			l1++;
		}
	}
	for(int i=1;i<=Q;i++)
	{
		printf("%d\n",ans[i]);
	}
}