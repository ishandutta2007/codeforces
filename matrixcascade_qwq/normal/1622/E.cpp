/*
qwq
*/


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
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fr for(auto to:
#define rf )
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
#define inf 1000000000000000000ll
ll Max(ll a=-inf,ll b=-inf,ll c=-inf,ll d=-inf,ll e=-inf,ll f=-inf,ll g=-inf,ll h=-inf)
{
	return max(max(max(a,b),max(c,d)),max(max(e,f),max(g,h)));
}
ll Min(ll a=inf,ll b=inf,ll c=inf,ll d=inf,ll e=inf,ll f=inf,ll g=inf,ll h=inf)
{
	return min(min(min(a,b),min(c,d)),min(min(e,f),min(g,h)));
}
#undef inf
int s[20];
int b[20][10101];
struct node
{
	int x,id;
}q[10101];
int cmp(node a,node b)
{
	return a.x>b.x;
}
int ans[10101],pp[10101],gg[22];
signed main()
{
	int T=read();
	while(T--)
	{
		rd(n);rd(m);
		upn rd(s[i]);
		up(i,1,m)pp[i]=0;
		upn
		{
			upm
			{
				scanf("%1lld",&b[i][j]);
			}
		}
		int msk=(1<<n)-1;
		int val=0;
		up(i,0,msk)
		{
			up(j,1,m)q[j].id=j,q[j].x=0,ans[j]=0;
			up(j,1,n)gg[j]=0;
			up(j,1,n)
			{
				up(k,1,m)
				{
					if(b[j][k]==1)
					{
						if((i&(1<<(j-1))))
						{
							q[k].x++;
						}
						else q[k].x--;
					}
				}
			}
			sort(q+1,q+m+1,cmp);
			up(j,1,m)ans[q[j].id]=j;
			up(j,1,n)
			{
				up(k,1,m)
				{
					if(b[j][k]==1)
					{
						gg[j]+=ans[k];
					}
				}
			}
			int sum=0;
			up(j,1,n)sum+=abs(gg[j]-s[j]);
			if(sum>=val)
			{
				val=sum;
				up(j,1,m)pp[j]=ans[j];
			}
		}
	//	cout<<val<<'\n';
		up(i,1,m)opl(pp[i]),cout<<" ";
		edl;
	}
}
/*
1
4 4
6 2 0 10
1001
0010
0110
0101
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/
/*
1
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
01011
4 4
6 2 0 10
1001
0010
0110
0101
*/