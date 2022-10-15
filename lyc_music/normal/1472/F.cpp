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
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m;
int ans;
pa a[N];
signed main()
{
	T=read();
	while (T--)
	{
		ans=1;
		n=read();m=read();
		for (int i=1;i<=m;i++)
		{
			a[i]={read(),read()};
			swap(a[i].fi,a[i].se);
		}
		if (m&1)
		{
			puts("NO");
			continue;
		}
		sort(a+1,a+m+1);
		for (int i=2;i<=m;i+=2)
		{
			int x=i-1;
			if (a[x].fi==a[i].fi&&a[x].se!=a[i].se)
			{
				continue;
			}
//			cout<<"?"<<x<<""<<i<<endl;
			if (a[i].se==a[x].se&&(a[i].fi-a[x].fi)%2==0)
			{
				ans=0;
				break;
			}
			if (a[i].se!=a[x].se&&(a[i].fi-a[x].fi)%2==1) 
			{
				ans=0;break;
			}
			if (i+1<m&&a[i+1].fi==a[i].fi&&a[i].se!=a[i+1].se)
			{
				ans=0;
				break;
			}
		}
		if (ans) puts("YES");
		else puts("NO");
	}
		
}
/*

*/