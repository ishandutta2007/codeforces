//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
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
const int maxn=2e5+10;
int a[maxn],rt[maxn],f[maxn],lg[maxn],g[maxn];
const int maxm=maxn<<5;
int q;
int ls[maxm],rs[maxm],ans[maxm];
int tot=0;
int build(int l,int r)
{
	int root=++tot;
	if(l!=r)
	{
		int mid=(l+r)>>1;
		ls[root]=build(l,mid);
		rs[root]=build(mid+1,r);
	}
	return root;
}
int insert(int pre,int l,int r,int v)
{
	int root=++tot;
	ls[root]=ls[pre],rs[root]=rs[pre],ans[root]=ans[pre]+1;
	if(l!=r)
	{
		int mid=(l+r)>>1;
		if(v<=mid)ls[root]=insert(ls[pre],l,mid,v);
		else rs[root]=insert(rs[pre],mid+1,r,v);
	}
	return root;
}long long anss=0;
int query(int l,int r,int ql,int qr,int x,int y)
{
	if(ql<=l&&r<=qr)
	{
	//	cout<<x<<" "<<y<<"nmsl\n";
		return ans[y]-ans[x];
	}
	int ansss=0;
	int mid=(l+r)>>1;
	if(ql<=mid)ansss+=query(l,mid,ql,qr,ls[x],ls[y]);
	if(mid<qr)ansss+=query(mid+1,r,ql,qr,rs[x],rs[y]);
//	cout<<ansss<<"qwq\n";
	return ansss;
}int dp[maxn][19];
int qry(int l,int r,int x)
{
	int p=upper_bound(f+1,f+q+1,x)-f-1;
	if(p==0)return 0;
	return query(1,q,p,p,rt[l-1],rt[r]);
}
int qmax(int l,int r)
{
	int len=lg[r-l+1];
	if(g[dp[l][len]]>g[dp[r-(1<<len)+1][len]])return dp[l][len];
	else return dp[r-(1<<len)+1][len];
}

void solve(int l,int r)
{
	
	if(l==r)
	{
	//	anss+=(g[l]==1);
		return;
	}
	int mid=qmax(l,r);//cout<<l<<" "<<r<<" "<<mid<<"\n";
	if(mid==l)
	{
		solve(mid+1,r);
		return;
	}
	if(mid==r)
	{
		solve(l,mid-1);
		return;
	}
	if(mid-l+1<=r-mid+1)
	{
		up(i,l,mid)
		{
			anss+=qry(mid,r,g[mid]-g[i]);
		//	cout<<qry(mid+1,r,g[mid]/g[i])<<" "<<g[mid]/g[i]<<'\n';
		}
		solve(l,mid-1);solve(mid+1,r);
		return;
	}
	up(i,mid,r)
	{
		anss+=qry(l,mid,g[mid]-g[i]);//cout<<qry(l,mid-1,g[mid]/g[i])<<" "<<g[mid]/g[i]<<'\n';
	}
	solve(l,mid-1);solve(mid+1,r);
	return;
}
int query(int r1,int r2,int l,int r,int k)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	int nw=ans[ls[r2]]-ans[ls[r1]];
	if(nw>=k)return query(ls[r1],ls[r2],l,mid,k);
	else return query(rs[r1],rs[r2],mid+1,r,k-nw);
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		lg[0]=-1;
		up(i,1,n)lg[i]=lg[i>>1]+1;
		up(i,1,n)
		{
			a[i]=read();
			g[i]=a[i];
			dp[i][0]=i;
			f[i]=a[i];
		}
		sort(f+1,f+n+1);
		q=unique(f+1,f+n+1)-f-1;
		rt[0]=build(1,q);
		up(i,1,n)
		{
			a[i]=lower_bound(f+1,f+q+1,a[i])-f;
			rt[i]=insert(rt[i-1],1,q,a[i]);
			//cout<<a[i]<<" ";
		}
		up(j,1,18)
		{
			for(int i=1;i+(1<<j)-1<=n;++i)
			{
				if(g[dp[i][j-1]]>g[dp[i+(1<<(j-1))][j-1]])dp[i][j]=dp[i][j-1];
				else dp[i][j]=dp[i+(1<<(j-1))][j-1];
			}
		}
		solve(1,n);
		cout<<anss<<'\n';
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/