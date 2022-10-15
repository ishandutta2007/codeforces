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
#define N 300005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,sm,ans;
pa a[N];
multiset<int>S,S1;
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]={y,x};
	}
	sort(a+1,a+n+1);
	for (int i=n;i>=1;i--) S.insert(a[i].se);
	while (S1.size()<m-1&&S.size())
	{
		S1.insert((*S.rbegin()));sm+=(*S.rbegin());
		S.erase((--S.end()));
	}
	for (int i=1;i<=n;i++)
	{
		if (S.count(a[i].se)) S.erase(S.find(a[i].se));
		else
		{
			sm-=a[i].se;S1.erase(S1.find(a[i].se));
		}
		while (S1.size()<m-1&&S.size())
		{
			S1.insert((*S.rbegin()));sm+=(*S.rbegin());
			S.erase((--S.end()));
		}
		ans=max(ans,(sm+a[i].se)*a[i].fi);
	}
	writeln(ans);
		
}
/*
4 1
4 7
15 1
3 6
6 8
*/