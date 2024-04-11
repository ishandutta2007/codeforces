//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define int long long
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
map<int,int>mp,s;
void solve(int x)
{
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0)
		{
			int f=0;
			while(x%i==0)++f,x/=i;
			mp[i]|=(1<<(f-1));
		}
	}
	if(x==1)return;mp[x]|=1;
}
int calc(int x)
{if(x==0)return 0;
	if(s.find(x)!=s.end())return s[x];
	
	map<int,int>f;
	int fw=0;int l=0;fw=x;while(fw)fw/=2,++l;
	up(i,1,l)
	{
		f[calc((x>>i)|(x&(1<<(i-1))-1))]=1;
	}
	up(i,0,10100101)if(!f[i]){s[x]=i;return i;}
}
signed main()
{
	int T=1;
	while(T--)
	{
		int sum=0;
		n=read();
		up(i,1,n)
		{
			int nw=read();
			solve(nw); 
		}
		for(auto it:mp)
		{
			sum^=calc(it.second);
		}
		if(sum)puts("Mojtaba");
		else puts("Arpa");
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/