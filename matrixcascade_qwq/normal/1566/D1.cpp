//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
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
struct node
{
	int x,y,ans;
}f[101010];
int a[101001];
int cmp(node a,node b)
{
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
int pmc(node a,node b)
{
	return a.y<b.y;
}
int bit[333][333];
int lowbit(int x)
{
	return x&(-x);
}
void add(int kk,int x,int y=1)
{
	for(;x<=m;x+=lowbit(x))
	{
		bit[kk][x]+=y;
	}
	return;
}
int qry(int k,int x)
{
	int ans=0;
	for(;x>=1;x-=lowbit(x))
	{
		ans+=bit[k][x];
	}
//	cout<<ans<<" qwq"<<endl;
	return ans;
}
int g(int x)
{
	return x*(x-1)/2;
}
int q[322][322];
signed main()
{
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		k=n*m;
		up(i,0,n+1)up(j,0,m+1)bit[i][j]=0;
		up(i,1,k)a[i]=read(),f[i].x=a[i],f[i].y=i;
		up(i,1,n)q[i][m+1]=-1;
		sort(f+1,f+k+1,cmp);
		up(i,1,k)f[i].ans=i;
		sort(f+1,f+k+1,pmc);
		int sum=0;
		up(i,1,k)
		{
			int x=(f[i].ans-1)/m+1;
			int y=(f[i].ans-1)%m+1;//x,y zuobiao
			q[x][y]=f[i].x;
			sum+=qry(x,y);
			add(x,y);
			//cout<<sum<<endl;
		}
	//	puts("");
		up(i,1,n)
		{
			int fir=0;
			int l=0;
			up(j,1,m+1)
			{
				if(q[i][j]==fir)
				{
					++l;
				}
				else
				{
					sum-=g(l);
					fir=q[i][j];l=1;
				}
			}
		}
		cout<<sum<<'\n';
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/