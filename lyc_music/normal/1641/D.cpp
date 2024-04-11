//~~
#pragma GCC optimize("Ofast",3)
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 2e9+1
#define mod 998244353
#define B 25001
//#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
unordered_map<int,int>Mp;
bitset<B>f[B*5],nowbt;
int ans;
int P[N];
int W[N][6];
int a[N];
int n,m,cnt;
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
void BellaKira()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) W[i][j]=read();
		a[i]=read();
		P[i]=i;
	}
	sort(P+1,P+n+1,cmp);
	ans=inf;
	for (int l=1;l<=n;l+=B-1)
	{
		cnt=0;
		int r=l+B-2;r=min(r,n);
		Mp.clear();
		for (int i=l;i<=r;i++)
			for (int j=1;j<=m;j++)
				{
					if (!Mp[W[P[i]][j]])
					{
						Mp[W[P[i]][j]]=++cnt;
						f[cnt].set();
					}
					f[Mp[W[P[i]][j]]][i-l]=0;
				}
		for (int i=1;i<=n;i++)
		{
			if (ans>a[P[i]]+a[P[1]])
			{
				nowbt.set();
				int p=0;
				for (int j=1;j<=m;j++)
					if (p+l<=r)
					{
						if (Mp[W[P[i]][j]])
						{
							nowbt&=f[Mp[W[P[i]][j]]];
						}
						p=nowbt._Find_first();
					}
				if (l+p<=r) ans=min(ans,a[P[i]]+a[P[l+p]]);
			}
		}
	}
	if (ans!=inf) 
	writeln(ans); else puts("-1");	
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/