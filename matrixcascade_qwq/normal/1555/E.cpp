#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define rd(x) x=read()
#define op(x) printf("%lld",x)
#define ops(x) printf("%lld ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
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
struct node
{
	int l,r,w;
}q[303030];
int cmp(node a,node b)
{
	return a.w<b.w;
}
const int maxn=4e6+10;
int ans[maxn],tag[maxn];
#define ls x<<1
#define rs x<<1|1
void pushup(int x)
{
	ans[x]=min(ans[ls],ans[rs]);
}
void f(int x,int y)
{
	ans[x]+=y;tag[x]+=y;
}
void pushdown(int x)
{
	if(tag[x])
	{
		f(ls,tag[x]);
		f(rs,tag[x]);
	}
	tag[x]=0;
}
void upd(int x,int l,int r,int ql,int qr,int p)
{
	if(ql<=l&&r<=qr)
	{
		f(x,p);
		return;
	}
	pushdown(x);
	int mid=(l+r)>>1;
	if(ql<=mid)upd(ls,l,mid,ql,qr,p);
	if(qr>mid)upd(rs,mid+1,r,ql,qr,p);
	pushup(x);
}
signed main()
{
	n=read(),m=read();
	up(i,1,n)
	{
		rd(q[i].l);rd(q[i].r);rd(q[i].w);
		q[i].r--;
	}
	int anss=10101010;
	sort(q+1,q+n+1,cmp);
	int l=1,r=0;
	while(r<n&&ans[1]==0)
	{
		++r;
		upd(1,1,m-1,q[r].l,q[r].r,1);
	}
	anss=min(anss,q[r].w-q[1].w);
	up(l,2,n)
	{
		upd(1,1,m-1,q[l-1].l,q[l-1].r,-1);
		while(r<n&&ans[1]==0)
		{
			++r;
			upd(1,1,m-1,q[r].l,q[r].r,1);
		}
		if(ans[1]!=0)anss=min(anss,q[r].w-q[l].w);
	}
	cout<<anss;
}