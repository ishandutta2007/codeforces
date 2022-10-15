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
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],s[N];
int ans;
multiset<pa>S;
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+a[i];
	for (int i=3;i<=n;i++)
	{
		S.insert({-a[i-2]-s[i-2],i-2});
		auto it=S.upper_bound({a[i]-s[i-1],11451419});
		if (it==S.begin()) continue;
		it--;
		do
		{
			int u=(*it).se;
			if ((a[i]^a[u])==(s[i-1]-s[u])) ans++;
			if (it==S.begin()) break;
			it--;
		}while (114514);
	}
	writeln(ans);
}
/*

*/