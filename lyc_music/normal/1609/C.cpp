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
#define N 1000005 
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int e,n,vis[N],f[N],s[N],ans,a[N];
void LYC_music()
{
	e=read();n=read();
	swap(e,n);
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) s[i%e]=0,f[i]=0;
	ans=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==1)
		{
			s[i%e]++;
		}
		else
		{
			if (!vis[a[i]])
				f[i]=f[i]+s[i%e],s[i%e]=0;
			else s[i%e]=0;
		}
	}
	for (int i=1;i<=n;i++) s[i%e]=0;
	for (int i=n;i>=1;i--)
	{
		if (a[i]==1)
		{
			s[i%e]++;
//			ans+=(s[i%e]-1);
		}
		else
		{
			if (!vis[a[i]])
				ans+=(f[i]+1)*(s[i%e]+1)-1,s[i%e]=0;
			else s[i%e]=0;
		}
	}
	writeln(ans);
	
			
}
signed main()
{
	vis[1]=1;
	for (int i=2;i<=1000000;i++)
	{
		if (!vis[i])
		{
			for (int j=2*i;j<=1000000;j+=i) vis[j]=1;
		}
	}
	int T=read();
	while (T--)
	{
		LYC_music();
	}
}
/*
1
9 1
1 2 1 3 1 5 1 7 1
*/