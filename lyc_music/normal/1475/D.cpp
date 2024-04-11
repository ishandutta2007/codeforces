//QwQcOrZ yyds!!!
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
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int a[N],b[N];
vector<int>G[3];
int n,m;
int T;
int ans,sm,sum;
signed main()
{
	T=read();
	while (T--)
	{
		
	n=read(),m=read();ans=inf;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		b[i]=read();
		G[b[i]].push_back(a[i]);
	}
	for (int i=1;i<=2;i++) sort(G[i].begin(),G[i].end());
	int l=0;
	int x=G[1].size(),y=G[2].size();
	for (int i=x-1;i>=0;i--)
	{
		int u=G[1][i];
		sum+=u;
		if (sum>=m) ans=min(ans,(int)G[1].size()-i);
	}
	for (int i=y-1;i>=0;i--)
	{
		sm+=G[2][i];
		if (sm>=m)
		{
			ans=min(ans,2*(y-i));
		} else
		{
			while (l<G[1].size()&&sm+sum-G[1][l]>=m) sum-=G[1][l],l++;
			if (sm+sum>=m) ans=min(ans,2*(y-i)+x-l);
		}
//		cout<<i<<" "<<l<<" "<<sm<<" "<<sum<<endl;
	}
	if (ans==inf) puts("-1");
	else 
	writeln(ans);
	G[1].clear(),G[2].clear();
	sm=0,sum=0;
	
	}
}
/*

*/