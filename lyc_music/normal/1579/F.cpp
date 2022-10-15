//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define mod 998244353
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,d,a[N],b[N],ans;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();d=read();ans=0;
		for (int i=0;i<n;i++)
		{
			a[i]=read();b[i]=0;
		}
		for (int i=0;i<n;i++)
		{
			if (!b[i])
			{
				int x=i;
				int sm=a[i];
				int t=0,mnt=0,y=0;
				vector<int>g;
				while (!b[x])
				{
					b[x]=1;
					sm&=a[x];
					x=(x-d+n)%n;
					g.push_back(a[x]);
					t++;
				}
				for (int i=0;i<t;i++) g.push_back(g[i]);
				for (int i=0;i<g.size();i++)
				{
					if (g[i]==0)
					{
						mnt=max(mnt,y);
						y=0;
					} else y++;
				}
				mnt=max(mnt,y);
				if (sm) 
				{
					ans=-1;
					break;
				} else
				{
					ans=max(ans,mnt);
				}
			}
		}
		writeln(ans);
	}
		
}
/*

*/