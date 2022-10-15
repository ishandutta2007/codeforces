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
//#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int p,n,m,a[N],b[N];
void What_will_Diana_eat_today()
{
	p=read(),n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read();
	vector<int>g;
	int l=1,r=1,ans=1;
	while (l<=n||r<=m)
	{
//		if (g.size()) cout<<"!!!"<<g.back()<<" "<<p<<endl;
		if (r>m)
		{
			if (a[l]==0)
			{
				p++;
			} else
			{
				if (p<a[l])
				{
					ans=0;
					break;
				}
			}
			g.push_back(a[l]);
			l++;
		}
		else
		if (l>n)
		{
			if (b[r]==0)
			{
				p++;
			} else
			{
				if (p<b[r])
				{
					ans=0;
					break;
				}
			}
			g.push_back(b[r]);
			r++;
		} else
		{
//			cout<<"?"<<l<<" "<<r<<" "<<a[l]<<" "<<b[r]<<endl;
			if (a[l]==0&&b[r]==0)
			{
				g.push_back(a[l]);
				p++;
				l++;
				continue;
			}
			if (a[l]==0)
			{
				g.push_back(a[l]);
				p++;
				l++;
				continue;
			}
			if (b[r]==0)
			{
				g.push_back(b[r]);
				p++;
				r++;
				continue;
			}
			
			if (a[l]!=0&&p>=a[l])
			{
				g.push_back(a[l]);
				l++;
				continue;
			}
			
			if (b[r]!=0&&p>=b[r])
			{
				g.push_back(b[r]);
				r++;
				continue;
			}
			ans=0;
			break;
		}
	}
	if (!ans) puts("-1");
	else 
	{
		for (int u:g) writesp(u);
		puts("");
	}		
}
signed main()
{
	int T=read();
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*

*/