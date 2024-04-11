//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,a[N],ans;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		ans=0;
		for (int i=2;i<=n;i++) a[i]-=a[1];
		a[1]=0;
		vector<int>g;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
			{
				int x=a[j]-a[i];
				for (int k=1;k*k<=x;k++)
				if (x%k==0)
				{
					g.push_back(k);
					g.push_back(x/k);
				}
			}
		sort(g.begin(),g.end());
		g.push_back(a[n]+1);
		for (int p=g.size()-1;p>=0;p--)
		{
			int i=g[p];
			for (int j=1;j<=n/2+1;j++)
			{
				int sm=0;
				for (int k=j;k<=n;k++)
					if ((a[k]-a[j])%i==0) sm++;
				if (sm>=(n/2)) 
				{
					ans=i;
					break;
				}
			}
			if (ans!=0)
			{
				if (ans==a[n]+1) ans=-1;
				break;
			}
		}
		writeln(ans);
	}
			
}
/*

*/