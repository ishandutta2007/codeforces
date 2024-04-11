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
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N];
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (n%2==1)
	{
		poly G;
		for (int i=3;i<=n;i+=2)
		{
			G.push_back(i-2);
			int vv=(a[i]^a[i-1]^a[i-2]);
			a[i]=a[i-1]=a[i-2]=vv;
		}
		for (int i=n-2;i>=3;i-=2)
		{
			G.push_back(i-2);
			a[i]=a[i-1]=a[i-2]=a[i]^a[i-1]^a[i-2];
		}
		for (int i=1;i<=n;i++)
			if (a[i]) return puts("NO"),void();
		puts("YES");
		writeln(G.size());
		for (auto u:G) writesp(u);
		puts("");
	} else
	{
		int nows=0;
		int x=0;
		for (int i=2;i<=n;i+=2)
		{
			nows^=a[i-1]^a[i-2];
			if (nows%2==0)
			{
				x=i;
				break;
			}
		}
		if (!x) return puts("NO"),void();
		x--;
		// cout<<"?"<<x<<endl;
		poly G;
		for (int i=3;i<=x;i+=2)
		{
			G.push_back(i-2);
			a[i]=a[i-1]=a[i-2]=a[i]^a[i-1]^a[i-2];
		}
		for (int i=x-2;i>=3;i-=2)
		{
			G.push_back(i-2);
			a[i]=a[i-1]=a[i-2]=a[i]^a[i-1]^a[i-2];
		}
		for (int i=x+3;i<=n;i+=2)
		{
			G.push_back(i-2);
			a[i]=a[i-1]=a[i-2]=a[i]^a[i-1]^a[i-2];
		}
		for (int i=n-2;i>=x+3;i-=2)
		{
			G.push_back(i-2);
			a[i]=a[i-1]=a[i-2]=a[i]^a[i-1]^a[i-2];
		}
		for (int i=1;i<=n;i++)
			if (a[i]) return puts("NO"),void();
		puts("YES");
		writeln(G.size());
		for (auto u:G) writesp(u);
		puts("");
	}
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