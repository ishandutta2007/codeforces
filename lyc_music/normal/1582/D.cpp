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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,a[N],b[N],c[N];
map<int,int>Mp;
bool cmp(int x,int y)
{
	return (Mp[a[x]]^Mp[a[y]])?(Mp[a[x]]<Mp[a[y]]):a[x]<a[y];
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		if (n%2==0)
		{
			for (int i=1;i<=n;i+=2)
				b[i]=a[i+1],b[i+1]=-a[i];
		} else
		{
			for (int i=1;i<=n;i++) Mp[a[i]]++;
			for (int i=1;i<=n;i++) c[i]=i;
			stable_sort(c+1,c+n+1,cmp);
			for (int i=1;i<=n-3;i+=2)
			{
				b[c[i]]=a[c[i+1]],b[c[i+1]]=-a[c[i]]; 
			}
			int x=a[c[n-1]]*a[c[n]]/__gcd(a[c[n-1]],a[c[n]]);
			x=x*a[c[n-2]]/__gcd(a[c[n-2]],x);
			b[c[n-2]]=x/(a[c[n-2]]);
			b[c[n-1]]=x/(a[c[n-1]]);
			b[c[n]]=-x/(a[c[n]])*2;
		}
		for (int i=1;i<=n;i++) writesp(b[i]);
		puts("");
		Mp.clear();
	}
			
		
}
/*

*/