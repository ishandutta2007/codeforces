//QwQcOrZ yyds!!!
#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
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
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
#define dy (y/__gcd(x,y))
#define dx (x/__gcd(x,y))
#define lcm(x,y) (x*y/__gcd(x,y))
int T,x,y,z,X,Y,b[20000007],P[20000007],si[10000005],cnt;
int work(int x)
{
//	cout<<x<<" "<<b[x]<<endl;
	return b[x];
}
void exgcd(int a,int b,int &x,int &y)
{
	if (b==0)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return;
}
signed main()
{
//	int XXX=read(),YYY=read();
//	writeln(work(6));
//	return 0;
	b[1]=1;
	for (int i=2;i<=20000000;i++)
	{
		if (!P[i]) 
		{
			P[i]=i;
			b[i]=2;
			si[++cnt]=i;
		}
//		cout<<cnt<<endl;
		for (int j=1;j<=cnt;j++)
		{
			if (i*si[j]>20000000) break;
			if (P[i]>si[j]) b[i*si[j]]=b[i]*2;
			else b[i*si[j]]=b[i];
			P[i*si[j]]=si[j];
			if (si[j]%i==0||!P[i])
				b[i*si[j]]=b[i];
			if (i%si[j]==0)break;
		}
	}
//	cout<<b[3]<<endl;
	T=read();
	while (T--)
	{
		x=read(),y=read(),z=read();
//		z/=__gcd(x,y);
		if (z%__gcd(x,y)!=0) 
		{
			puts("0");
			continue;
		}
		int ans=0;
		for (int i=1;i*i<=z;i++)
			if (z%i==0)
			{
				int now=i;
				int a=(y*now+z)/x;
				if ((y*now+z)%x==0)
				{
				if (a%now==0)
				{
					ans+=work(a/now);
 				}
				}
				if (i*i!=z)
				{
				now=z/i;
				a=(y*now+z)/x;
				if ((y*now+z)%x==0)
				{
				if (a%now==0)
				{
					ans+=work(a/now);
				}
				}
				}
			}
		writeln(ans);
	}
}
/*
1
4 2 6
*/