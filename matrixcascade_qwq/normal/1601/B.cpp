//MatrixCascade AFO.
//qqqqqqqqqqqqqq

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
int a[444444],b[444444],c[444444];
//int ans[808080];
//#define ls (x<<1)
//#define rs (x<<1|1)
//#define mid ((l+r)>>1)
//void pushup(int x)
//{
//	return min(ans[ls],ans[rs]);
//}
//void update(int x,int l,int r,int p,int q)
//{
//	if(l==r)
//	{
//		ans[p]=q;
//		return;
//	}
//	if(p<=mid)update(ls,l,mid,p,q);
//	else update(rs,mid+1,r,p,q);
//	pushup(x);
//}
//int query(int x,int l,int r,int ql,int qr)
//{
//	if(ql<=l&&r<=qr)
//	{
//		return ans[x];
//	}
//	int ff=1e12;
//	if(ql<=mid)ff=min(ff,query(ls,l,mid,ql,qr));
//	if(mid<qr)ff=min(ff,query(rs,mid+1,r,ql,qr));
//	return ff;
//}
struct node
{
	int x,id,y,d;
}q[444444];
int cmp(node a,node b)
{
	return a.d<b.d;
}
int cmp2(node a,node b)
{
	return a.id<b.id;
}
int f[444444];
vector<int>v[444444];
int g[444444],tot=0;
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		up(i,1,n)a[i]=read();
		
		up(i,1,n)b[i]=read(),c[i]=i+b[i];
		up(i,1,n)
		{
			q[i].x=a[i];q[i].id=i;q[i].y=b[i];q[i].d=i-a[i];
		}
		sort(q+1,q+n+1,cmp);
		up(i,1,n)
		{
			v[c[i]].push_back(i);
		}
		int i=1;
		int pre=0;
		memset(f,0x3f,sizeof(f));
		while(i<=n)
		{
			int qq=0,val=0;
			while(q[i].id-q[i].x<=pre&&i<=n)
			{
				f[q[i].id]=pre;qq=1;
				for(int to:v[q[i].id])val=max(val,to);++i;
			}
			pre=val;
			if(qq==0)break;
		}
		sort(q+1,q+n+1,cmp2);
		if(f[n]>1000000)
		{
			puts("-1");
			return 0;
		}
		int nw=f[n];
		for(;nw;nw=f[nw])
		{//cout<<nw;
			g[++tot]=nw;nw+=q[nw].y;
		};
		cout<<tot+1<<'\n';
		up(i,1,tot)cout<<g[i]<<" ";
		cout<<0; 
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/