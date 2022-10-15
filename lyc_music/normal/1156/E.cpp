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
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int a[N],f[N][25],b[N],ans,n;
int Max(int x,int y)
{
	if (a[x]>a[y]) return x;
	return y;
}
int query(int l,int r)
{
	int t=log2(r-l+1);
	return Max(f[l][t],f[r-(1<<t)+1][t]);
}
void work(int l,int r)
{
	if (r-l+1<=2) return;
	int mid=query(l,r);
	if (mid-l>r-mid)
	{
		for (int i=r;i>mid;i--)
		{
			if (b[a[mid]-a[i]]>=l&&b[a[mid]-a[i]]<mid) ans++;
		}
	}
	else
	{
		for (int i=l;i<mid;i++)
		{
			if (b[a[mid]-a[i]]>mid&&b[a[mid]-a[i]]<=r) ans++;
		}
	}
	work(l,mid-1);
	work(mid+1,r);
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[a[i]]=i,f[i][0]=i;
	for (int i=1;i<=20;i++)
		for (int j=1;j+(1<<i)-1<=n;j++)
			f[j][i]=Max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
	work(1,n);
	writeln(ans);
}
/*

*/