//~~
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
int n,a[N];
int s1[N];
int s[N];
void BellaKira()
{
	set<pa>b[2];
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	a[n+1]=0;
	int ans=0;
	int ansx=1,ansy=n-1;
	for (int i=0;i<=n+1;i++)
	{
		if (a[i]==0)
		{
			if (b[0].size())
			{
				int nowx=(*b[0].rbegin()).fi-(*b[0].begin()).fi;
				if (nowx>ans)
				{
					ansx=(*b[0].begin()).se;
					ansy=n-(*b[0].rbegin()).se;
					ans=nowx;
				}
			}
			if (b[1].size())
			{
				int nowx=(*b[1].rbegin()).fi-(*b[1].begin()).fi;
				if (nowx>ans)
				{
					ansx=(*b[1].begin()).se;
					ansy=n-(*b[1].rbegin()).se;
					ans=nowx;
				}
			}
			b[0].clear();
			b[1].clear();
			s1[i]=1;
			s[i]=0;
			
			if (s1[i]==-1)
			b[0].insert(mp(s[i],i));
			else 
			b[1].insert(mp(s[i],i));
			// cout<<"?"<<i<<" "<<s1[i]<<" "<<s[i]<<endl;
		}
		else
		{
			s1[i]=s1[i-1]*(a[i]/abs(a[i]));
			s[i]=s[i-1]+(abs(a[i])==2);
			// cout<<"?"<<i<<" "<<s1[i]<<" "<<s[i]<<endl;
			if (s1[i]==-1)
			b[0].insert(mp(s[i],i));
			else 
			b[1].insert(mp(s[i],i));
		}
	}
	writesp(ansx),writeln(ansy);
			
			
		
	
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