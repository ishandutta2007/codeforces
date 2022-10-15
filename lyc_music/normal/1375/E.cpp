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
//#define int ll
#define N 2005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<pa>ans;
set<int>G[N];
int n;
pa a[N];
int vis[N];
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]={read(),i};
	for (int i=1;i<=n;i++)
		for (int j=1;j<n-i+1;j++)
			if (a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				ans.push_back({min(a[j].se,a[j+1].se),max(a[j].se,a[j+1].se)});
			}
	reverse(ans.begin(),ans.end());
	writeln(ans.size());
	for (auto u:ans)
	{
		writesp(u.fi),writeln(u.se);
	}
}
/*

5 
3 4 3 1 2

7
1 5
3 5
2 5
1 4
3 4
2 4
2 3
*/