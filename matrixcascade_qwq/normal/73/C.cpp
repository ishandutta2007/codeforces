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
int mp[33][33];string s;
int dp[111][111][33];
int dfs(int nw,int res,int p)
{
	if(nw==s.size())return 0;
	if(dp[nw][res][p]!=-1)return dp[nw][res][p];
	dp[nw][res][p]=dfs(nw+1,res,s[nw]-'a')+mp[p][s[nw]-'a'];
	up(i,0,25)
	{
		if(i!=(s[nw]-'a')&&res>0)dp[nw][res][p]=max(dp[nw][res][p],dfs(nw+1,res-1,i)+mp[p][i]);
	}
	return dp[nw][res][p];
}
signed main()
{
	int T=1;
	while(T--)
	{
		cin>>s>>k>>n;
		up(i,1,n)
		{
			char a,b;int c;cin>>a>>b>>c;
			mp[a-'a'][b-'a']=c;
		}
		memset(dp,-1,sizeof(dp));cout<<dfs(0,k,30);
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/