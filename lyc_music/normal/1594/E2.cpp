//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
map<int,int>dp[15];
map<int,int>b,c;
int a;
string st[N];
int T,n;
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void ad(int &x,int y)
{
	x=(x+y)%mod;
}
void dfs(int k,int dep)
{
//	cout<<k<<" "<<dep<<endl;
	if (dep>T) return;
	if (!b[k])
	{
//		cout<<"!"<<k<<" "<<dep<<endl;
		for (int i=0;i<6;i++) dp[i][k]=quickPower(4,(1ll<<(T-dep+1))-2);
		return;
	}
	else
	if (dep<T)
	{
		dfs(k*2,dep+1);
		dfs(k*2+1,dep+1);
		for (int i=0;i<6;i++) dp[i][k]=1;
		for (int i=0;i<6;i++)
		{
			int sm=0;
			for (int j=0;j<6;j++)
				if (i/2!=j/2)
				ad(sm,dp[j][k*2]);
			dp[i][k]=dp[i][k]*sm%mod;
		}
		for (int i=0;i<6;i++)
		{
			int sm=0;
			for (int j=0;j<6;j++)
				if (i/2!=j/2)
					ad(sm,dp[j][k*2+1]);
			dp[i][k]=dp[i][k]*sm%mod;
		}
		if (c.count(k))
		{
			for (int i=0;i<6;i++)
				if (c[k]!=i) dp[i][k]=0;
		}
	}
	else
	{
		dp[c[k]][k]=1;
	}
//	cout<<"!!!"<<k<<" "<<c[k]<<endl;
//	for (int i=0;i<6;i++) cout<<dp[i][k]<<" ";
//	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>T;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a>>st[i];
			if (st[i][0]=='w')c[a]=0;
			else if (st[i][0]=='y') c[a]=1;
			else if (st[i][0]=='g') c[a]=2;
			else if (st[i][0]=='b') c[a]=3;
			else if (st[i][0]=='r') c[a]=4;
			else c[a]=5;
			int x=a;
			while (x)
			{
				b[x]=1;
				x/=2;
			}
		}
		dfs(1,1);
		int ans=0;
		for (int i=0;i<6;i++) ans+=dp[i][1],ans%=mod;
		writeln(ans);
		
}
/*

*/