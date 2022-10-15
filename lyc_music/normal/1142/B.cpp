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
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,q,a[N],nx[N],f[N][25],ST[N][25],c[N],b[N];
int getf(int x,int y)
{
	for (int i=20;i>=0;i--)
		if ((y>>i)%2) x=f[x][i];
	return x;
}
int query(int x,int y)
{
	int t=log2(y-x+1);
	return min(ST[x][t],ST[y-(1<<t)+1][t]);
}
signed main()
{
	n=read();m=read(),q=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		if (i>1) nx[a[i-1]]=a[i];
	}
	nx[a[n]]=a[1];
	for (int i=1;i<=m;i++) b[i]=read();
	f[m+1][0]=m+1;
	for (int i=m;i>=1;i--)
	{
//		b[i]=read();
		if (!c[nx[b[i]]]) 
			f[i][0]=m+1;
		else f[i][0]=c[nx[b[i]]];
		c[b[i]]=i;
//		cout<<i<<" "<<f[i][0]<<" "<<nx[b[i]]<<endl;
	}
	for (int i=1;i<=20;i++)
	{
		for (int j=1;j<=m+1;j++)
			f[j][i]=f[f[j][i-1]][i-1];
//		cout<<f[m+1][i-1]<<endl;
	}
	for (int i=m;i>=1;i--)
	{
		ST[i][0]=getf(i,n-1);
//		cout<<i<<" "<<ST[i][0]<<" "<<f[i][1]<<endl;
	}
	for (int i=1;i<=20;i++)
		for (int j=1;j+(1<<i)-1<=m;j++)
			ST[j][i]=min(ST[j][i-1],ST[j+(1<<(i-1))][i-1]);
	while (q--)
	{
		int l=read(),r=read();
		if (query(l,r)<=r) write(1);
		else write(0);
	}
	
}
/*

*/