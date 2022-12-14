// LUOGU_RID: 95345658
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
#define N 5000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],s[N],dp[N],ans;
void LYC_music()
{
	n=read();
	
	int mx=0;
	for (int i=1;i<=n;i++) a[i]=read(),mx=max(mx,a[i]),s[a[i]]++;
	for (int i=1;i<=mx;i++)
		for (int j=2*i;j<=mx;j+=i)
			s[i]+=s[j];
	for (int i=1;i<=mx;i++)
		for (int j=2*i;j<=mx;j+=i)
			dp[j]=max(dp[i]+(i-1)*(s[i]-s[j]),dp[j]);
	for (int i=1;i<=mx;i++)
			ans=max(ans,dp[i]+s[i]*(i-1));
		ans+=n;
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