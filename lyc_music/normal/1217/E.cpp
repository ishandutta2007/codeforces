// 
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[N<<2][15],tr1[N<<2][15];
int n,m,a[N],opt,x,y;
inline void pushup(int k)
{
	for (int j=1;j<=10;j++)
	{
		if (tr[k<<1][j]<tr[k<<1|1][j])
		{
			tr[k][j]=tr[k<<1][j];
			tr1[k][j]=min(tr1[k<<1][j],tr[k<<1|1][j]);
		}
		else
		{
			tr[k][j]=tr[k<<1|1][j];
			tr1[k][j]=min(tr1[k<<1|1][j],tr[k<<1][j]);
		}
	}
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		for (int j=1;j<=10;j++)
		{
			tr[k][j]=tr1[k][j]=inf;
		}
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void update(int k,int l,int r,int i,int val)
{
	if (l==r)
	{
		int now=val;
		for (int j=1;j<=10;j++)
		{
			if (now%10>0)
			{
				tr[k][j]=val;tr1[k][j]=inf;
			} else tr[k][j]=tr1[k][j]=inf;
			now/=10;
		}
		return;
	}
	int mid=l+(r-l)/2;
	if (i<=mid) update(k<<1,l,mid,i,val);
	else update(k<<1|1,mid+1,r,i,val);
	pushup(k);
}
pa query(int k,int l,int r,int L,int R,int p)
{
	if (L<=l&&r<=R)
	{
		return {tr[k][p],tr1[k][p]};
	}
	int mid=l+(r-l)/2;
	pa res={inf,inf};
	if (L<=mid) 
	{
		pa u=query(k<<1,l,mid,L,R,p);
		if (res.fi>u.fi)
		{
			res.se=res.fi;
			res.fi=u.fi;
			res.se=min(res.se,u.se);
		} else
		{
			res.se=min(res.se,u.fi);
		}
	}
	if (R>mid)
	{
		pa u=query(k<<1|1,mid+1,r,L,R,p);
		if (res.fi>u.fi)
		{
			res.se=res.fi;
			res.fi=u.fi;
			res.se=min(res.se,u.se);
		} else
		{
			res.se=min(res.se,u.fi);
		}
	}
	return res;
}
signed main()
{
	n=read(),m=read();
	build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		update(1,1,n,i,a[i]);
	}
	for (int i=1;i<=m;i++)
	{
		opt=read(),x=read(),y=read();
		if (opt==1)
		{
			update(1,1,n,x,y);
		} else
		{
			int ans=inf;
			for (int j=1;j<=10;j++)
			{
				pa u=query(1,1,n,x,y,j);
				ans=min(ans,u.fi+u.se);
			}
			if (ans==inf) puts("-1");
			else writeln(ans);
		}
	}
}
/*

*/