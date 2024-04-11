//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#include<numeric>
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
const int maxn=202020;
int vis[maxn];
vector<int>v[maxn];
int f[maxn],p[maxn];
int q[maxn],tot;
void exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return; 
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int ff(int a,int b)
{
	int x,y;
	int z;
	z=gcd(a,m);
	int d=m/z;
	exgcd(a,m,x,y);
	return (1ll*x*b/z%d+d)%d;
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),m=read();
		up(i,1,n)vis[read()]=1;
		up(i,0,m-1)
		{
			if(!vis[i])v[gcd(m,i)].emplace_back(i);
		}
		up(i,1,m)
		{
			if(m%i!=0)continue;
			f[i]+=v[i].size();
			for(int j=i+i;j<=m;j+=i)
			{
				if(m%j!=0)continue;
				if(f[j]<=f[i])f[j]=f[i],p[j]=i;
			//	cout<<i<<" "<<j<<endl;
			}
		}
		k=m;
		
		while(true)
		{
			for(auto to:v[k])q[++tot]=to;
			if(k-1==0)break;
			k=p[k];
		}
		cout<<tot<<"\n"<<q[tot]<<" ";
		pu(i,tot-1,1)
		{
			cout<<ff(q[i+1],q[i])<<" ";
		}
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/