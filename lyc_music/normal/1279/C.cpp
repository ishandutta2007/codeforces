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
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,ans,a[N],b[N],c[N];
int query(int x)
{
	int res=0;
	while (x>0)
	{
		res+=c[x];
		x-=(x&(-x));
	}
	return res;
}
void update(int x,int y)
{
	while (x<=n)
	{
		c[x]+=y;
		x+=(x&(-x));
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read(),m=read();ans=0;
		for (int i=1;i<=n;i++) a[i]=read(),b[i]=0;
		for (int i=1;i<=m;i++) b[read()]=i;
		for (int i=1;i<=n;i++)
			if (b[a[i]])
			{
				update(b[a[i]],1);
			}
		int mn=n;
		for (int i=n;i>=1;i--)
		{
			if (b[a[i]])
			{
				update(b[a[i]],-1);
				if (mn<b[a[i]]) ans+=1;
				else ans+=(i-1-query(b[a[i]]))*2+1;
				mn=min(mn,b[a[i]]);
			}
		}
		writeln(ans);
	}
		
}
/*

*/