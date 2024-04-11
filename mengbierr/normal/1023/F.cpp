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
int ch[2000005][2],fa[2000005],w[2000005],mark[2000005];
int f[2000005],top,s[2000005],n,k,m;
bool rev[2000005];
bool isroot(int x)
{
	return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;
}
void pushdown(int x)
{
	if(rev[x])
	{
		rev[ch[x][0]]^=1;
		rev[ch[x][1]]^=1;
		swap(ch[x][0],ch[x][1]);
		rev[x]=0;
	}
	if(mark[x])
	{
		mark[ch[x][0]]=min(mark[ch[x][0]],mark[x]);
		mark[ch[x][1]]=min(mark[ch[x][1]],mark[x]);
		w[ch[x][0]]=min(w[ch[x][0]],mark[x]);
		w[ch[x][1]]=min(w[ch[x][1]],mark[x]);
		mark[x]=2000000000;
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
}
void splay(int x)
{
    top=0;
    s[++top]=x;
    for(int i=x;!isroot(i);i=fa[i]) s[++top]=fa[i];
    while(top) pushdown(s[top--]);
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
		splay(x);ch[x][1]=t;
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
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void dfs(int x)
{
	//cout<<"!!!"<<x<<" "<<ch[x][0]<<" "<<ch[x][1]<<endl;
	if(ch[x][0]&&!isroot(ch[x][0]))
	{
		mark[ch[x][0]]=min(mark[ch[x][0]],mark[x]);
		w[ch[x][0]]=min(w[ch[x][0]],mark[x]);
		dfs(ch[x][0]);
	}
	if(ch[x][1]&&!isroot(ch[x][1]))
	{
		mark[ch[x][1]]=min(mark[ch[x][1]],mark[x]);
		w[ch[x][1]]=min(w[ch[x][1]],mark[x]);
		dfs(ch[x][1]);
	}
}
int main()
{
	memset(w,0x7f7f7f7f,sizeof(w));
	memset(mark,0x7f7f7f7f,sizeof(mark));
	n=read();k=read();m=read();
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		int u=read(),v=read();
		link(u,n+i);
		link(n+i,v);
		f[find(u)]=find(v);
	}
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w1=read();
		int fu=find(u),fv=find(v);
		if(fu==fv)
		{
			//cout<<u<<" "<<v<<endl;
			makeroot(u);access(v);
			splay(v);
			mark[v]=min(mark[v],w1);
			w[v]=min(w[v],w1);
		}
		else
		{
			link(u,i+k+n);
			link(i+k+n,v);
			f[fu]=fv;
		}
	}
	ll ans=0;
	for(int i=1;i<=n+k+m;i++)
	{
		if(isroot(i))
		{
			//cout<<i<<' ';
			dfs(i);
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(w[i+n]>=2000000000)
		{
			puts("-1");
			return 0;
		}
		ans+=w[i+n];
	}
	cout<<ans;
}