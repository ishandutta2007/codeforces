//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define il inline
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
#define mod 1000000007
#define Endl endl
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,v,sum,ans,now;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		int u=(n-1)%3+1;sum=0;
		if (u==1)
		{
			n=(n-1)/3;
			for (int i=0;i<=63;i+=2)
			{
				if ((1ll<<i)+sum>n) 
				{
					now=i;
					break;
				}
				sum+=(1ll<<i);
			}
			writeln((1ll<<now)+n-sum);
		} else
		if (u==2)
		{
			n=(n-1)/3;
			for (int i=0;i<=63;i+=2)
			{
				if ((1ll<<i)+sum>n) 
				{
					now=i;
					break;
				}
				sum+=(1ll<<i);
			}
			v=(1ll<<now)+n-sum;ans=v;
			for (int i=0;i<=63;i+=2)
			{
				int p=((v>>i)&1),p1=(v>>(i+1))&1;
				if (p&&p1) ans^=(1ll<<(i+1));
				if (p&&!p1) ans^=(1ll<<i),ans^=(1ll<<(i+1));
				if (!p&&p1) ans^=(1ll<<i);
			}
			writeln(ans);
		} else
		{
			n=(n-1)/3;
			for (int i=0;i<=63;i+=2)
			{
				if ((1ll<<i)+sum>n) 
				{
					now=i;
					break;
				}
				sum+=(1ll<<i);
			}
			v=(1ll<<now)+n-sum;ans=v;
			for (int i=0;i<=63;i+=2)
			{
				int p=((v>>i)&1),p1=(v>>(i+1))&1;
				if (p&&p1) ans^=(1ll<<i);
				if (p&&!p1) ans^=(1ll<<(i+1));
				if (!p&&p1) ans^=(1ll<<i),ans^=(1ll<<(i+1));
			}
			writeln(ans);
		}
	}
			
}
/*

*/