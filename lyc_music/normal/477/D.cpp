//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 1000000007
//#define int ll
#define N 5005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int Zg[N][N];
int B=18;
ll ans1;
string st,st1;
int n;
ll dp[N][N],s[N][N];
int Z[100005];
ll ans;
bool cmp(int x,int y,int len)
{
	if (Zg[x][y]>=len) return 1;
	return (st1[x+Zg[x][y]]<=st1[y+Zg[x][y]]);
}
inline ll val(int x,int y)
{
	ll res=0;
	for (int i=x;i<=y;i++) res=res*2+(st1[i]-'0'),res%=mod;
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>st;
	st1=st;
	n=st.length();
//	reverse(st1.begin(),st1.end());
	for (int i=1;i<=n;i++)
	{
		string nowst=st1.substr(i-1,n-i+1);
		nowst=nowst+' '+st1;
		int l=0,r=0;
		int m=nowst.length();
		Z[0]=m;
		for (int j=1;j<m;j++)
		{
			Z[j]=0;
			if (j>r)
			{
				Z[j]=0;
				while (j+Z[j]<m&&nowst[Z[j]]==nowst[j+Z[j]]) Z[j]++;
			}
			else
				if (Z[j-l]<r-j+1) Z[j]=Z[j-l];
			else
			{
				Z[j]=r-j+1;
				while (j+Z[j]<m&&nowst[Z[j]]==nowst[j+Z[j]]) Z[j]++;
			}
			if (j+Z[j]-1>r) l=j,r=j+Z[j]-1;
		}
		for (int j=n-i+2;j<m;j++) Zg[i][j-n+i-1]=Z[j];
	}
	st1=' '+st1;
	reverse(st.begin(),st.end());
	st=' '+st;
	dp[1][0]=1;
	s[1][0]=1;
	for (int i=1;i<=n;i++) s[1][i]=s[1][i-1]+dp[1][i];
	for (int i=2;i<=n;i++) 
	if (st[i]=='1')
	{
		for (int j=1;j<i;j++)
		if (st[j]=='1') 
		{
			int len=i-j;
			if (j>=len)
			{
				dp[i][j]=(len!=j)?s[j][j-len-1]:0;
				if (cmp(n-i+1,n-j+1,len))
				{
					dp[i][j]=(dp[i][j]+dp[j][j-len])%mod;
				}
			}
		}
		dp[i][0]=(dp[i][0]+1)%mod;
		s[i][0]=(s[i][0]+1)%mod;
		for (int j=1;j<i;j++) s[i][j]=(s[i][j-1]+dp[i][j])%mod;
	}
	
	for (int i=0;i<n;i++) 
	{
		ans=(ans+dp[n][i])%mod;
	}
	
	memset(dp,0x3f,sizeof(dp));
	memset(s,0x3f,sizeof(s));
//	dp[0][0]=1;
//	s[0][0]=1;
	dp[1][0]=1;
	s[1][0]=1; 
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		if (st1[j+1]=='1') 
		{
//			/*
			int len=i-j;
			if (j>=len)
			{
				dp[i][j]=min(dp[i][j],s[j][j-len+1]+1);
				if (cmp(j-len+1,j+1,len)&&st1[j-len+1]=='1')
				{
					dp[i][j]=min(dp[i][j],dp[j][j-len]+1);
				}
			} else dp[i][j]=min(dp[i][j],s[j][0]+1);
//			if (i<=20&&j<=20) cout<<"?"<<i<<" "<<j<<" "<<dp[i][j]<<" "<<cmp(2,4,2)<<" "<<s[2][1]<<endl;
		}
		dp[i][0]=1;
		s[i][0]=1;
		for (int j=n;j>=1;j--) s[i][j]=min(s[i][j+1],dp[i][j]);
	}
	
//	cout<<dp[2][1]<<" "<<endl;
	
	ans1=inf;
	for (int i=n-1;i>=max(0,n-B);i--)
	{
		ans1=min(val(i+1,n)+dp[n][i],ans1);
//		cout<<"!"<<i<<" "<<dp[n][i]<<endl;
	}
	
	if (ans1==inf)
	{
		for (int i=n-B-1;i>=0;i--)
			if (dp[n][i]<=10000)
			{
//				cout<<n<<"!"<<i<<endl;
				ans1=val(i+1,n)+dp[n][i],ans1%=mod;
				break;
			}
	}
	
	writeln(ans%mod);
	writeln(ans1%mod);
	
}
/*

*/