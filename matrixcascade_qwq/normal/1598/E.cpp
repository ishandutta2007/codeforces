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
int a[1010][1010];
int dp[1010][1010][2];
signed main()
{
	int T=1;
	while(T--)
	{
		int n=read(),m=read(),q=read();
		
		up(i,1,n)
		{
			up(j,1,m)
			{
				a[i][j]=1;
			}
		}
		int ans=0;
		up(i,1,n)
		{
			up(j,1,m)
			{
				dp[i][j][0]=dp[i][j][1]=1;
				dp[i][j][0]+=dp[i-1][j][1];
				dp[i][j][1]+=dp[i][j-1][0];
				ans+=dp[i][j][0]+dp[i][j][1]-1;
			}
		}
		while(q--)
		{
			int x=read(),y=read();
			int nx=x,ny=y;
			int lf=0;
			while(1)
			{
				if(lf%2==0)
				{
					--nx;
					if(a[nx][ny]==0)break;
					lf++;
				}
				else
				{
					--ny;
					if(a[nx][ny]==0)break;
					lf++;
				}
			}
			int rf=0;
			nx=x,ny=y;
			while(1)
			{
		//		cout<<nx<<" "<<ny<<" qwq"<<endl;
				if(rf%2==1)
				{
					++nx;
					if(a[nx][ny]==0)break;
					rf++;
				}
				else
				{
					++ny;
					if(a[nx][ny]==0)break;
					rf++;
				}
			}
			int sum1=(rf+1)*(lf+1);
			nx=x,ny=y;
			lf=0;
			while(1)
			{
				if(lf%2==1)
				{
					--nx;
					if(a[nx][ny]==0)break;
					lf++;
				}
				else
				{
					--ny;
					if(a[nx][ny]==0)break;
					lf++;
				}
			}
			rf=0;
			nx=x,ny=y;
			while(1)
			{
				if(rf%2==0)
				{
					++nx;
					if(a[nx][ny]==0)break;
					rf++;
				}
				else
				{
					++ny;
					if(a[nx][ny]==0)break;
					rf++;
				}
			}
			int sum2=(rf+1)*(lf+1);
			a[x][y]=1-a[x][y];
		//	cout<<sum1<<" "<<sum2<<'\n'; 
			sum1+=sum2;sum1--;
			if(a[x][y]==1)ans+=sum1;
			else ans-=sum1;
			cout<<ans<<'\n';
		}
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/