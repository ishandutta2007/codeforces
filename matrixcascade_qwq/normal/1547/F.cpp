#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
//#define int long long
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
int a[505050];
int ans[2000001];
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
	ans[x]=__gcd(ans[ls(x)],ans[rs(x)]);
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		ans[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	pushup(p);
}
int qry(int p,int l,int r,int nl,int nr)
{
	if(l>=nl&&nr>=r)return ans[p];
	int mid=(l+r)>>1;
	int nw=0;
	if(nl<=mid)nw=__gcd(nw,qry(ls(p),l,mid,nl,nr));
	if(nr>mid)nw=__gcd(nw,qry(rs(p),mid+1,r,nl,nr));
	return nw;
}
signed main()
{
	int T=read();
	while(T--)
	{
		n=read();
		up(i,1,n)a[i]=read();
		int gd=0;
		up(i,1,n)gd=__gcd(gd,a[i]);
		int tot=1;
		up(i,2,n)tot+=(a[i]==a[1]);
		if(tot==n)
		{
			puts("0");
			continue;
		}
		up(i,1,n)a[i+n]=a[i];
		int mx=0;
		up(i,1,n+n)a[i]/=gd;
		build(1,1,n*2);
		int l=1,r=1;
		up(r,1,n*2)
		{
			while(l<=r&&qry(1,1,n+n,l,r)==1)++l,mx=max(mx,r-l+1);
			mx=max(mx,r-l+1);
		}
		cout<<mx<<endl;
	}
}