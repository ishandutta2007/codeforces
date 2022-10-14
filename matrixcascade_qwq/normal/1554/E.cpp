#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
//#define int long long
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
const int mod=998244353;
const int maxn=2e5+10;
vector<int>v[maxn];
int ans=0;
void add(int a,int b)
{
	v[a].push_back(b);
	v[b].push_back(a);
}
int nw;
int f=1;
int b[maxn];
int dfs(int x,int fa)
{
	int q=v[x].size();
	if(f==0)return 0;
	for(auto u:v[x])
	{
		if(u!=fa)q-=dfs(u,x);
	}
	if(q%k!=0&&(q-1)%k!=0)
	{
		f=0;
	}
	if(q%k==0)
	{
		ans=__gcd(ans,q);
		return 1;
	}
	else
	{
		
		ans=__gcd(ans,q-1);return 0;
	}
	
}
void check(int x)
{
	k=x;
	f=1;
	ans=0;
	int fff=dfs(1,0);
	if(f==0)return;
	b[ans]=1;
}
signed main()
{
	int T;
	rd(T);
	while(T--)
	{
		rd(n);
		up(i,1,n)v[i].clear();
		up(i,1,n-1)
		{
			int u,v;
			rd(u),rd(v);
			add(u,v);
		}
		up(i,1,n)b[i]=0;
		m=n-1;
		up(i,2,m)
		{
			if(m%i==0)
			{
				check(i);
				while(m%i==0)m/=i;
			}
		}
		if(m!=1)
		{
			check(m);
		}
		int f=1;
		up(i,1,n-1)f*=2,f%=mod;
		b[1]=f;
		up(i,2,n)b[1]-=b[i];
		b[1]+=mod;
		b[1]%=mod;
		up(i,1,n)printf("%d ",b[i]);
		puts("");
	} 
}