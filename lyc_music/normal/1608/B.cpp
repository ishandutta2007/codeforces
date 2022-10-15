//The Hunting Party - Keys To The Kingdom
//~
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
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,x,y,a[N],ans;
int p;
void What_will_Diana_eat_today()
{
	T=read();
	while (T--)
	{
		n=read(),x=read(),y=read();
		ans=0;
		int X=x,Y=y;
		if (x>y)
		{
			int l=1,r=n;
			for (int i=1;i<=n;i++)
			{
				if (i%2==1)
				{
					a[i]=l++;
					if (i!=1) 
					{
						if (!y) 
						{
							ans=-1;
							break;
						}
						y--;
					}
				}
				else
				{
					a[i]=r--;
						if (!x) 
						{
							ans=-1;
							break;
						}
						x--;
				}
				if (x==0) 
				{
					p=i+1;break;
				}
			}
			for (int i=p;i<=n;i++)
				a[i]=r--;
		}
		else
		if (x<y)
		{
			swap(x,y);
			int l=1,r=n;
			for (int i=1;i<=n;i++)
			{
				if (i%2==1)
				{
					a[i]=r--;
					if (i!=1) 
					{
						if (!y) 
						{
							ans=-1;
							break;
						}
						y--;
					}
				}
				else
				{
					a[i]=l++;
					if (!x) 
					{
						ans=-1;
						break;
					}
					x--;
				}
				if (x==0) 
				{
					p=i+1;break;
				}
			}
			for (int i=p;i<=n;i++)
				a[i]=l++;
		} else
		{
			int l=1,r=n;
			for (int i=1;i<=n;i++)
			{
				if (i%2==1)
				{
					a[i]=l++;
					if (i!=1) 
					{
						if (!y) 
						{
							ans=-1;
							break;
						}
						y--;
					}
				}
				else
				{
					a[i]=r--;
						if (!x) 
						{
							ans=-1;
							break;
						}
						x--;
				}
				if (x==0&&y==0) 
				{
					p=i+1;break;
				}
			}
			for (int i=p;i<=n;i++) a[i]=l++;
		}
		for (int i=2;i<n;i++)
			if (a[i]>a[i-1]&&a[i]>a[i+1]) X--;
			else 
			if (a[i]<a[i-1]&&a[i]<a[i+1]) Y--;
		if (X!=0||Y!=0) ans=-1;
		if (ans==-1) writeln(ans);
		else
		{
			for (int i=1;i<=n;i++) writesp(a[i]);
			puts("");
		}
	}
			
}
signed main()
{
	 	  What_will_Diana_eat_today();
}
/*

*/