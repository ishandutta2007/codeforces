//MatrixCascade AFO.
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
int fa[101010],siz[101010];
int v[101001],w[101010];
int u[101010];
int dp[101010];
int find(int x)
{
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
int chk(int x)
{
	while(x)
	{
		if(x%10!=4&&x%10!=7)return 0;
		x/=10;
	}return 1;
}
signed main()
{
	int T=1;
	while(T--)
	{
		k=0;
		n=read(),m=read();
		up(i,1,n)fa[i]=i,siz[i]=1;
		up(i,1,m)
		{
			int x=read(),y=read();
			int fx=find(x),fy=find(y);
			if(fx==fy)continue;
			fa[fx]=fy;
			siz[fy]+=siz[fx];
			siz[fx]=0;
		}
		up(i,1,n)
		{
			if(siz[i])
			{
				++u[siz[i]];
			}
		}
		up(i,1,n)
		{
			up(j,0,19)
			{
				if(u[i]>=(1<<j))
				{
					u[i]-=(1<<j);
					w[++k]=i*(1<<j);
					v[k]=(1<<j);
				}
			}
			if(u[i])
			{
				w[++k]=i*u[i];
				v[k]=u[i];
			}
		}
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		up(i,1,k)
		{
			pu(j,n,w[i])
			{
			//	cout<<1;
				dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		int ans=10101001;
		up(i,1,n)
		{
			if(chk(i))ans=min(ans,dp[i]);
		}
		if(ans>1000000)ans=0;
		cout<<ans-1<<endl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/