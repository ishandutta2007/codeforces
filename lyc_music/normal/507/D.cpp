//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int pow10[1005];
int dp[1005][105][2];
int n,m,K,ans;
void ad(int &x,int y)
{
	x=(x+y)%m;
}
void LYC_music()
{
	n=read(),K=read(),m=read();
	pow10[0]=1;
	for (int i=1;i<=n;i++) pow10[i]=pow10[i-1]*10%K;
	dp[0][0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<10;j++)
			for (int k=0;k<K;k++)
			{
				if (j==0&&i==n) continue;
				ad(dp[i][(j*pow10[i-1]+k)%K][1],dp[i-1][k][1]);
				if ((j*pow10[i-1]+k)%K==0&&j!=0)
					ad(dp[i][(j*pow10[i-1]+k)%K][1],dp[i-1][k][0]);
				else  ad(dp[i][(j*pow10[i-1]+k)%K][0],dp[i-1][k][0]);
//				cout<<"?"<<j<<" "<<j*pow10[i]<<endl; 
//				cout<<i-1<<" "<<k<<" "<<dp[i-1][k][0]<<" "<<dp[i-1][k][1]<<endl; 
			}
	for (int i=0;i<K;i++) ad(ans,dp[n][i][1]);
	writeln(ans);
			
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/