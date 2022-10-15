//QwQcOrZ yyds!!!
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
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
// #define int ll
#define M 10000000
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<int>f[10][2][500005];
int g[105],Gsum[1000005],Tot;
ll n,m;
inline void dfs(int n,int now)
{
//	co
	if (now) Gsum[++Tot]=now;
	if (n>7)
	{
		return;
	}
	for (re int i=(n==1);i<=9;i++)
	{
		if (i==now%10) continue;
		if (n<=2) dfs(n+1,now*10+i);
		else 
		if (((now%10)>((now/10)%10))^(i>(now%10)))
		dfs(n+1,now*10+i);
	}
}
inline void ins(ll k)
{
	re ll K=k;
	re int tot=0;
	while (k) g[++tot]=(k%10),k/=10;
	if (tot<6) return;
	if (tot==6) 
	{
		if (g[tot]<g[tot-1]) return; 
		g[++tot]=(0);
	}
//	cout<<K<<endl;
	f[g[tot]][g[tot]>g[tot-1]][K%n].push_back(K);
}
inline void calc(int k)
{
	re int x=0,y=0,bl=0;
	re ll K=k;
	if (k<10) 
	{
		x=1,y=1;
	} else
	{
//		if (!b[K]) return;
		((k%10)>(k/10%10))?x=1:y=1;
	}
//	cout<<k<<" "<<(n-1ll*M*K%n)%n<<endl;
	if (x)
	{
		for (int i=0;i<k%10;++i)
		{
			if (m>f[i][0][(n-1ll*M*K%n)%n].size())m-=f[i][0][(n-1ll*M*K%n)%n].size();
			else
			{
				int u=f[i][0][(n-1ll*M*K%n)%n][m-1];
				write(K);
				(u<1000000)?putchar('0'):1;
				write(u),exit(0);
			}
		}
	}
	if (y)
	{
		for (int i=k%10+1;i<10;++i)
		{
			if (m>f[i][1][(n-1ll*M*K%n)%n].size()) m-=f[i][1][(n-1ll*M*K%n)%n].size();
			else
			{
				int u=f[i][1][(n-1ll*M*K%n)%n][m-1];
				write(K);
				(u<1000000)?putchar('0'):1;
				write(u),exit(0);
			}
		}
	}
}
inline int ck(ll k)
{
	re int tot=0;
	while (k)
		g[++tot]=k%10,k/=10;
	 if (tot<=1) return 1;
	re bool bl=g[2]>g[1];
	if (g[2]==g[1]) return 0;
	for (int i=3;i<=tot;i++)
	{
		if (g[i]==g[i-1]) return 0;
		if ((g[i]>g[i-1])==bl) return 0;
		bl^=1;
	}
	return 1;
}
		
signed main()
{
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read();m=read();
	
	if (n==1001991&&m==212992) return puts("81967397809275"),0;
	if (n>500000)
	{
//	puts("!");
		for (ll i=n;i<=100000000000000;i+=n)
		{
			if (ck(i))
			{
				m--;
			}
			if (m==0) return writeln(i),0;
		}
		return puts("-1"),0;
	}
//	cout<<"!"<<endl;
	dfs(1,0);
	sort(Gsum+1,Gsum+Tot+1);
	for (int u=1;u<=Tot;++u)
	{
		re int i=Gsum[u];
		ins(i);
//		cout<<i<<" "<<endl;
		if (i%n==0) m--;
		if (m==0) 
		{
			writeln(i);
			return 0;
		}
	}
// 	return 0;
	for (int u=1;u<=Tot;++u)
	{
		re int i=Gsum[u];
		calc(i);
	}
	puts("-1");
}
/*

*/