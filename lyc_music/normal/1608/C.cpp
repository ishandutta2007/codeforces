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
int c[N],a[N],b[N],ans[N],p[N],pp[N];
int sb[N];
int PP[N],P[N];
int X[N],XX[N];
int n;
int sm[N];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
bool cmp1(int x,int y)
{
	return b[x]<b[y];
}
void What_will_Diana_eat_today()
{
	vector<int>g;
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),ans[i]=0;
	for (int i=1;i<=n;i++) b[i]=read();
	
	for (int i=1;i<=n;i++) p[i]=i,pp[i]=i;
	sort(p+1,p+n+1,cmp);
	sort(pp+1,pp+n+1,cmp1);

	for (int i=1;i<=n;i++) P[p[i]]=i,PP[pp[i]]=i;
	for (int i=1;i<=n;i++) X[P[i]]=PP[i],XX[PP[i]]=P[i];
	for (int i=1;i<=n;i++)	sm[i]=max(sm[i-1],X[i]);
	for (int i=1;i<=n;i++) sb[i]=max(sb[i-1],XX[i]);
	int now=n;
	for (int i=n;i>=1;i--)
		if (sb[sm[i]]>=now) now=i;
	for (int i=now;i<=n;i++) ans[p[i]]=1;
	for (int i=1;i<=n;i++) write(ans[i]);
	puts("");
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