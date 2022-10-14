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
#define ft(x) for(int i=head[x];i;i=nxt[i])
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fp for(auto to:
#define pf )
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define mkp make_pair
#define fi first
#define se second
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
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
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
string s[4];
const int maxn=10101;
int dp[maxn][10][4];
int f[maxn];
int chk(int i,int j)
{
	up(t,0,2)
	{
		if((j&(1<<t))&&(s[t+1][i-1]=='O'||s[t+1][i+2]=='O'))return 1;
	}
	return 0;
}
const int mod=1e9+7;
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;cin>>s[1]>>s[2]>>s[3];
		s[1]=" "+s[1];s[2]=" "+s[2];s[3]=" "+s[3];
		upn
		{
			if(s[1][i]!='.')f[i]++;
			if(s[2][i]!='.')f[i]+=2;
			if(s[3][i]!='.')f[i]+=4;
		}
		dp[1][0][0]=1;
		up(t,1,n)
		{
			up(i,0,7)
			{
				up(j,0,1)
				{
					if(!dp[t][i][j])continue;
					if(i&f[t])continue;
					int val=dp[t][i][j];
				//	cout<<t<<" "<<i<<" "<<j;edl;
					int g=i|f[t];
				//	cout<<g;edl;
					int n1,f1;
					n1=7^g;f1=chk(t,n1);//cout<<f1;edl;
					(dp[t+1][n1][f1|j]+=val)%=mod;
					if(g==0||g==4)
					{
						n1=g^4;f1=chk(t,n1);
						if(s[3][t]=='O')f1=1;
						(dp[t+1][n1][f1|j]+=val)%=mod;
					//	next=s^4;tt=check(x,next)|(mp[3][x]=='O');
					//	update(dp[x+1][next][tt|t],v);
					}
					if(g<=1)
					{
						n1=g^1;f1=chk(t,n1);
						if(s[1][t]=='O')f1=1;
						(dp[t+1][n1][f1|j]+=val)%=mod;
						
					//	next=s^1;tt=check(x,next)|(mp[1][x]=='O');
					//	update(dp[x+1][next][tt|t],v);
					}
				}
			}
		}
		opl(dp[n+1][0][1]);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/