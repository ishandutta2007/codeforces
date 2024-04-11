//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
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
#define ls x<<1
#define rs x<<1|1
#define mid ((l+r)>>1)
const int maxn=800080;
int ans[maxn][33];
int w[10];
void pushup(int x)
{
	up(i,0,m)
	{
		ans[x][i]=max(ans[ls][i],ans[rs][i]);
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		up(i,1,k)w[i]=read();
		up(i,0,m)
		{
			up(j,1,k)
			{
				if(i&(1<<(j-1)))ans[x][i]+=w[j];
				else ans[x][i]-=w[j];
			}
		}
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);pushup(x);
}
void update(int x,int l,int r,int ql)
{
	if(l==r)
	{
		up(i,1,k)w[i]=read();
		up(i,0,m)ans[x][i]=0;
		up(i,0,m)
		{
			up(j,1,k)
			{
				if(i&(1<<(j-1)))ans[x][i]+=w[j];
				else ans[x][i]-=w[j];
			}
		}
		return;
	}
	if(ql<=mid)update(ls,l,mid,ql);
	else update(rs,mid+1,r,ql);
	pushup(x);
}
struct node
{
	int ans[33];
};
node merge(node a,node b)
{
	node c;
	memset(c.ans,0,sizeof(c.ans));
	up(i,0,m)c.ans[i]=max(a.ans[i],b.ans[i]);
	return c;
}
node query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		node nw;
		memset(nw.ans,0,sizeof(nw.ans));
		up(i,0,m)nw.ans[i]=ans[x][i];
		return nw;
	}
	node nw;
	if(ql<=mid)nw=query(ls,l,mid,ql,qr);
	if(mid<qr)
	{
		if(ql<=mid)
		{
			nw=merge(nw,query(rs,mid+1,r,ql,qr));
		}
		else nw=query(rs,mid+1,r,ql,qr);
	}
	return nw;
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),k=read();m=(1<<k)-1;
		build(1,1,n);
		int q=read();
		while(q--)
		{
			int opt,l,r;
			opt=read(),l=read();
			if(opt==1)
			{
				update(1,1,n,l);
			}
			else
			{
				r=read();
				node ans=query(1,1,n,l,r);
				int ww=-110101010;
				up(i,0,m)ww=max(ww,ans.ans[i]+ans.ans[m^i]);
				printf("%d\n",ww);
			}
		}
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/