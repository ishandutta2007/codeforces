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
const int maxn=202020;
bool e[maxn];
int p[maxn],tot,mu[maxn];
int sum[maxn];
void mobius(int n)
{
	e[1]=1,mu[1]=1;
	up(i,2,n)
	{
		if(!e[i])
		{
			mu[i]=-1;
			p[++tot]=i;
		}
		up(j,1,tot)
		{
			if(p[j]*i>n)break;
			mu[p[j]*i]=i%p[j]==0?0:-mu[i];
			e[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
	int k=0;
}
int a[maxn],b[maxn],c[maxn];
int q1[maxn],q2[maxn],q3[maxn],q4[maxn];
int t1,t2,t3,t4;
int s1[maxn],s2[maxn],s3[maxn],s4[maxn];
//q1 c+,mu +
//q2 c+,mu-
//q3 c-,mu+
//q4 c-,mu-
signed main()
{
	int T=1;
	while(T--)
	{
		mobius(202000);
		rd(n);upn rd(a[i]);upn rd(b[i]);
		memset(c,0,sizeof(c));
		up(j,1,n)
		{
			for(int i=j;i<=n;i+=j)
			{
				c[i]+=mu[i/j]*(a[j]-b[j]);
			}
		}
		int sum=0;
		upn sum+=abs(c[i]);
		
		//q1 c+,mu +
		//q2 c+,mu-
		//q3 c-,mu+
		//q4 c-,mu-
		upn
		{
			if(c[i]>0&&mu[i]>0)
			{
				q1[++t1]=c[i];
			}
			else if(c[i]>0&&mu[i]<0)
			{
				q2[++t2]=c[i];
			}
			else if(c[i]<0&&mu[i]>0)
			{
				q3[++t3]=c[i]*-1;
			}
			else if(c[i]<0&&mu[i]<0)
			{
				q4[++t4]=c[i]*-1;
			}
		}
		sort(q1+1,q1+t1+1);
		sort(q2+1,q2+t2+1);
		sort(q3+1,q3+t3+1);
		sort(q4+1,q4+t4+1);
		up_(t1)s1[i]=s1[i-1]+q1[i];
		up_(t2)s2[i]=s2[i-1]+q2[i];
		up_(t3)s3[i]=s3[i-1]+q3[i];
		up_(t4)s4[i]=s4[i-1]+q4[i];
		
		int q;rd(q);
//		cerr<<c[1]<<" "<<c[2]<<'\n';
//		cerr<<mu[1]<<" "<<mu[2]<<'\n';
//		cerr<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<'\n';
		while(q--)
		{
			int x;rd(x);
			int del=b[1]-x;
			if(del==0)
			{
				cout<<sum;edl;
			}
			else if(del>0)
			{
				int ans=sum;
				ans+=(t1+t4)*del;
				int w1=lower_bound(q2+1,q2+t2+1,del)-q2-1;
				ans-=w1*del-s2[w1]-s2[w1];
				
				int w2=lower_bound(q3+1,q3+t3+1,del)-q3-1;
				ans-=w2*del-s3[w2]-s3[w2];
				
				ans-=(t2-w1+t3-w2)*del;
				cout<<ans;edl;
				/*
				4 -5
				1
				del=5
				s2
				w1*del-s2
				
				*/
			}
			else
			{
				del*=-1;
				int ans=sum;
				ans+=(t2+t3)*del;
				int w1=lower_bound(q1+1,q1+t1+1,del)-q1-1;
				ans+=w1*del-s1[w1]-s1[w1];
			//	cout<<w1*del-s1[w1]-s1[w1]<<'\n';
				int w2=lower_bound(q4+1,q4+t4+1,del)-q4-1;
				ans+=w2*del-s4[w2]-s4[w2];
				
				ans-=(t1-w1+t4-w2)*del;
				cout<<ans;edl;
			}
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