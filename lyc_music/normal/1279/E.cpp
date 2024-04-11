//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll __int128
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
#define N 55
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int Ans[N],vis[N],g[N],f[N],fac[N];
int n,m;
#define fac(x) fac[x]
int gf(int k)
{
	while (Ans[k]) k=Ans[k];
	return k;
}
void work1(int l,int r,int p)
{
//	writesp(l),writesp(r),writeln(p);
	Ans[l]=r;vis[r]=1;
	for (int i=l+1;i<r;i++)
	{
		int now=fac(r-i-1);
		for (int j=l;j<=r;j++)
			if (!vis[j]&&j!=i&&gf(j)!=i)
			{
				if (p<=now)
				{
					Ans[i]=j;
					vis[j]=1;
					break;
				}
				p-=now;
			}
	}
	for (int i=l;i<=r;i++)
		if (!vis[i]) Ans[r]=i;
}
void work(int l,int r,int p)
{
	if (l>r) return;
	int n=r-l+1,len=0;
	for (int i=1;i<=n;i++)
	{
//		cout<<i<<" "<<p<<endl;
		if (p<=g[i]*f[n-i])
		{
			len=i;
			break;
		}
		p-=g[i]*f[n-i];
	}
//	cout<<"!"<<len<<endl;
	work1(l,l+len-1,(p-1)/f[n-len]+1);
	work(l+len,r,p-((p-1)/f[n-len])*f[n-len]);
}
void solve()
{
	for (int i=1;i<=n;i++) Ans[i]=vis[i]=0;
	if (m>f[n]) puts("-1");
	else
	{
		work(1,n,m);
		for (int i=1;i<=n;i++) writesp(Ans[i]);
		puts("");
	}
}
signed main()
{
	n=50;
	g[1]=g[2]=1;
	fac[0]=1;
	for (int i=1;i<=n;i++) 
	{
		if (fac[i-1]<=1e19) fac[i]=fac[i-1]*i;
		else break;
	}
	for (int i=3;i<=n;i++) 
	{
		if (g[i-1]<=1e19)
			g[i]=g[i-1]*(i-2);
		else break;
	}
	f[0]=1;
	for (int i=1;i<=n;i++)
		for (int j=i-1;j>=0;j--)
			if (f[i]<=1e19)
			f[i]=f[i]+f[j]*g[i-j];
	int T=read();
	while (T--){n=read(),m=read();solve();}
}
/*

*/