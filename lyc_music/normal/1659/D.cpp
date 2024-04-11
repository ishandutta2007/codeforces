//~~11
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
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
int n,a[N],c[N];
int tr[N];
void upd(int x)
{
	while (x<=n)
	{
		tr[x]++;
		x+=x&-x;
	}
}
int query(int x)
{
	int res=0;
	while (x)
	{
		res+=tr[x];
		x-=x&-x;
	}
	return res;
}
void BellaKira()
{
	n=read();
	int sm=0;
	int ans=1;
	for (int i=1;i<=n;i++) c[i]=read(),sm+=c[i];
	sm/=n;
	sm=n-sm;
	for (int i=n;i>=1;i--)
	{
		upd(sm+1);
		c[i]-=query(i);
		if (i==1)
		{
			if (sm) a[i]=0;
			else a[i]=1;
			break;
		}
		if (i>sm)
		{
			if (c[i]==0)
			{
				a[i]=0;
				sm--;
			} else
			{
				if (c[i]!=i-1) ans=0;
				a[i]=1;
			}
		} else
		{
			if (c[i]==i-1)
			{
				a[i]=1;
			} else
			{
				if (c[i]!=0) ans=0;
				a[i]=0;
				sm--;
			}
		}
	}
	for (int i=1;i<=n;i++) writesp(a[i]),tr[i]=0;
	puts("");
				
			
				
	
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/