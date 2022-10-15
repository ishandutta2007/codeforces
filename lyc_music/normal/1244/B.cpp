//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=Next[i])
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
//#define mod 1000000007
//#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll a){if(a<0){a=-a; putchar('-');}write(a); putchar(' ');}
inline void writeln(ll a){if(a<0){a=-a; putchar('-');}write(a); puts("");}
int n,l,r,ans,T;
char a[100005];
signed main()
{
	T=read();
	while (T--)
	{
		n=read();ans=n;l=inf,r=0;
		for (int i=1;i<=n;i++) 
		{
			cin>>a[i];
			if (a[i]=='1') l=min(l,i),r=max(r,i);
		}
		if (l==r) ans=max(ans,max(l*2,(n-l+1)*2)); else
		if (l<r) ans=max(ans,max(l*2,(n-l+1)*2)),ans=max(ans,max(r*2,(n-r+1)*2)),ans=max(ans,(r-l+1)*2+max(n-r,l-1));
		writeln(ans);
	}
}