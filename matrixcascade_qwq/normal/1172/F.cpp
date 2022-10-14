#include <bits/stdc++.h>
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
int mod;
const int maxn=1e6+10;
int a[maxn],sum[maxn<<2];
vector<int>v[maxn<<2];
const int inf=1e15;
int ls(int x)
{
	return x<<1;
}
int rs(int x)
{
	return x<<1|1;
}
void pushup(int p,int l,int r)
{
	int mid=(l+r)>>1;
	sum[p]=sum[ls(p)]+sum[rs(p)];
	int nw=0;
	up(i,0,mid-l+1)
	{
		if(nw==r-mid+1)--nw;
		for(;nw<=r-mid;++nw)
		{
			int ns=v[ls(p)][i+1]-1-i*mod+sum[ls(p)];
			if(v[rs(p)][nw]>ns)
			{	
				--nw;
				break;
			}
			v[p][i+nw]=min(v[p][i+nw],max(v[ls(p)][i],v[rs(p)][nw]+i*mod-sum[ls(p)]));
		}
	}
}
void build(int p,int l,int r)
{
	v[p].resize(r-l+3);
	up(i,0,r-l+2)
	{
		v[p][i]=inf;
	}
	v[p][0]=-inf;
	if(l==r)
	{
		sum[p]=a[l];
		v[p][1]=mod-a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	pushup(p,l,r);
}
int query(int p,int l,int r,int nl,int nr,int w)
{
	if(l==nl&&r==nr)
	{
		int ps=upper_bound(v[p].begin(),v[p].end(),w)-v[p].begin();
		ps--;
		return w+sum[p]-1ll*ps*mod;
	}
	int mid=(l+r)>>1;
	if(mid<nl)return query(rs(p),mid+1,r,nl,nr,w);
	if(mid>=nr)return query(ls(p),l,mid,nl,nr,w);
	return query(rs(p),mid+1,r,mid+1,nr,query(ls(p),l,mid,nl,mid,w));
}
signed main()
{
	n=read(),m=read(),mod=read();
	up(i,1,n)a[i]=read();
	build(1,1,n);
	while(m--)
	{
		int l=read(),r=read();
		printf("%lld\n",query(1,1,n,l,r,0));
	}
}