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
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],s[N],sum,m;
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		s[i]=sum-a[i];
	m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		int p=lower_bound(a+1,a+n+1,x)-a;
		int ans=LONG_LONG_MAX;
		if (p!=n+1&&p!=0)
		ans=min(ans,max(0ll,(y-(sum-a[p]))));
		int p1=lower_bound(a+1,a+n+1,sum-y)-a;
		p1--;
		if (p1!=n+1&&p1!=0)
		{
			ans=min(ans,max(0ll,max(0ll,x-a[p1])));
		}
		if (p-p1>1)
		{
			p1++;
			ans=min(ans,max(0ll,(y-(sum-a[p1])))+max(0ll,max(0ll,x-a[p1])));
		}
		writeln(ans);
	}
		
		
		
}
/*

*/