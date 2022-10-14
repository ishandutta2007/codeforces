#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
const int inf=1ll<<50;
int q;
const int maxn=4e5+10;
int head[maxn],to[maxn],nxt[maxn],tot;
int a[maxn],b[maxn],c[maxn],w[maxn],faa[maxn],viss[maxn],fa[maxn][20],dep[maxn];
int dis1[maxn],dis2[maxn],ps[maxn];
int tree[maxn<<2],tag[maxn<<2];
vector<pair<int,int> >ve[maxn];
vector<int>pth;
int ls(int x)
{
	return x<<1;
}
int rs(int x)
{
	return x<<1|1;
}
void pushup(int x)
{
	tree[x]=min(tree[ls(x)],tree[rs(x)]);
}
void F(int x,int y)
{
	tree[x]=min(tree[x],y);
	tag[x]=min(tag[x],y);
}
void pushdown(int x)
{
	F(ls(x),tag[x]);
	F(rs(x),tag[x]);
	tag[x]=inf;
}
void build(int x,int l,int r)
{
	tree[x]=tag[x]=inf;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int nl,int nr,int p)
{
	if(nl<=l&&r<=nr)
	{
		F(x,p);
		return;
	}
	pushdown(x);
	int mid=(l+r)>>1;
	if(nl<=mid)
	{
		update(ls(x),l,mid,nl,nr,p);
	}
	if(mid<nr)
	{
		update(rs(x),mid+1,r,nl,nr,p);
	}
	pushup(x);
}
int query(int x,int l,int r,int nl,int nr)
{
	if(nl<=l&&r<=nr)
	{
		return tree[x];
	}
	pushdown(x);
	int mid=(l+r)>>1,ans=inf;
	if(nl<=mid)ans=min(ans,query(ls(x),l,mid,nl,nr));
	if(mid<nr)ans=min(ans,query(rs(x),mid+1,r,nl,nr));
	return ans;
}
void add(int x,int y,int z)
{
	to[++tot]=y;
	w[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}
int updis(int x,int y,int z,int dis[])
{
	if(dis[x]+z<dis[y])
	{
		faa[y]=x;
		dis[y]=dis[x]+z;
		return 1;
	}
	return 0;
}
void dij(int s,int dis[])
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	up(i,1,n)dis[i]=inf,viss[i]=0;
	dis[s]=0;
	q.push(mkp(dis[s],s));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(viss[x])continue;
		viss[x]=1;
		for(int i=head[x];i;i=nxt[i])
		{
			int v=to[i];
			if(updis(x,v,w[i],dis))
			{
				q.push(mkp(dis[v],v));
			}
		}
	}
}
void dfs(int x,int fat)
{
	//cout<<1;
	fa[x][0]=fat;
	dep[x]=dep[fat]+1;
	up(i,1,19)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto u:ve[x])
	{
		int w1=u.first,w2=u.second;
		if(w1==fat)continue;
		dfs(w1,x);
	}
}
void pre()
{
	up(i,2,n)
	{
		int u=faa[i],v=i;
		int w=dis1[v]-dis1[u];
		ve[u].push_back(mkp(v,w));
		ve[v].push_back(mkp(u,w));
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	down(i,19,0)
	{
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	}
	if(x==y)return y;
	down(i,19,0)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
bool chk(int u,int v,int x)
{
	return (faa[u]==v||faa[v]==u)&&(dis1[u]+x==dis1[v]||dis1[v]+x==dis1[u]);
}
signed main()
{
	n=read(),m=read(),q=read();
	up(i,1,m)
	{
		int x,y,z;
		x=read(),y=read(),z=read();
		a[i]=x;
		b[i]=y;
		c[i]=z;
		add(x,y,z);
		add(y,x,z);
	}
	dij(n,dis2);
	dij(1,dis1);

	pre();
	dfs(1,0);;	
	for(int i=n;i!=1;i=faa[i])pth.push_back(i);
	pth.push_back(1);
	pth.push_back(0);
	reverse(pth.begin(),pth.end());
	up(i,1,pth.size()-1)
	{
		ps[pth[i]]=i;
	}
	build(1,1,n);
	up(i,1,m)
	{
		int u=a[i],v=b[i],w=c[i];
		int q1=lca(u,n),q2=lca(v,n);
		int ql=ps[q1],qr=ps[q2];
		if(ql>qr)ql^=qr^=ql^=qr;
		
		if(ql==qr)++qr,++ql;
		else ++ql;
		if(chk(u,v,w))continue;
	//	cout<<ql<<" "<<qr<<endl;
		update(1,1,n,ql,qr,min(dis1[u]+dis2[v]+w,dis2[u]+dis1[v]+w));
	}
	up(cas,1,q)
	{
		int t,x;
		t=read(),x=read();
		int u=a[t],v=b[t],w=c[t];
		if(dis1[u]>dis1[v])u^=v^=u^=v;
		if(ps[u]&&ps[v]&&dis1[u]+w==dis1[v])
		{
			if(x>=w)
			{
				int anss=query(1,1,n,ps[v],ps[v]);
				printf("%lld\n",min(dis1[n]-w+x,anss));
			}
			else
			{
				printf("%lld\n",dis1[n]-w+x);	
			}
		}
		else
		{
			if(x>=w)
			{	
				printf("%lld\n",dis1[n]);
			}
			else
			{
				int ans=min(dis1[n],min(dis1[u]+x+dis2[v],dis1[v]+x+dis2[u]));
				printf("%lld\n",ans);
			}
		}
	}
}