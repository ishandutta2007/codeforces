//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
#include<windows.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define mod1 998244353
#define int ll
#define N 25
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<int>G[N];
int sm[N];
int pow10[N];
int B=1000000;
int n,ans;
int cnt;
void dfs(int dp,int val)
{
	++cnt;
	int xx=(cnt-val+mod1)%mod1;xx=(xx+mod1)%mod1;
	G[dp-1].push_back(xx);
	sm[dp-1]=(sm[dp-1]+xx)%mod;
	if (dp==7)
	{
		return;
	}
	for (int i=0;i<=9;i++) dfs(dp+1,val*10+i);
}
void dfs2(int dp,int val)
{
	if (val>n) return;
	if (val*B*10>n&&(val+1)*B-1<=n)
	{
		if (dp!=1)
		{
			for (int i=0;i<=6;i++)
			{
				int x=(cnt-(pow10[i]*val)%mod1+mod1)%mod1;
//				cout<<"?"<<x<<endl;
				int y=lower_bound(G[i].begin(),G[i].end(),(mod1-x))-G[i].begin();
				ans=(ans-(G[i].size()-y)*mod1%mod+x*G[i].size()%mod+sm[i]%mod+mod)%mod;
				ans=ans+mod,ans%=mod;
//				ans=(ans+sm[i])%mod;
			}
			for (int i=0;i<=6;i++) cnt+=G[i].size();
//			cout<<"?"<<ans<<" "<<val<<endl;
//			Sleep(1000);
			return;
		}
	}
	if (dp!=1)
	{
		++cnt;
		int xx=(cnt-val+mod1)%mod1;
		xx=(xx+mod1)%mod1;
		ans=(ans+xx)%mod;
	}
	for (int i=(dp==1);i<=9;i++)
		dfs2(dp+1,val*10+i);
}
signed main()
{
	pow10[0]=1;
	for (int i=1;i<=13;i++) pow10[i]=pow10[i-1]*10%mod1;
	n=read();
	dfs(1,0);
//	return 0;
	for (int i=0;i<=6;i++) sort(G[i].begin(),G[i].end());
	cnt=0;
	dfs2(1,0);
	writeln(ans);
}
/*

*/