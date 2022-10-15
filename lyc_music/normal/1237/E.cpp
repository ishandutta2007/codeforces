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
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,cnt,now,del,a[N];
int ans;
void dfs(int k,int w)
{
	if (k*2<=now)
	{
		dfs(k*2,w^1);
	}
	a[++cnt]=w;
	if (k*2+1<=now)
	{
		dfs(k*2+1,w);
	}
}
		
signed main()
{
	n=read();
	if (n==2) return puts("1"),0;
	now=1;
	for (int i=1;i;i++)
	{
		if (now*2-1>n)
		{
			break;
		}
//		cout<<"?"<<i<<endl;
		now=now*2;
	}
//	cout<<"!"<<now<<endl;
	now-=1;
	cnt=0;del=0;
	dfs(1,0);
	if (a[1]==0) del++;
	for (int i=1;i<cnt;i++)
	{
		if (a[i]==a[i+1])
		{
			del++;
		}
	}
//	for (int i=1;i<=cnt;i++) writesp(a[i]);
//	puts("");
	if (now+del==n) ans++;
	
	cnt=0;del=0;
	dfs(1,1);
	if (a[1]==0) del++;
	for (int i=1;i<cnt;i++)
	{
		if (a[i]==a[i+1])
		{
			del++;
		}
	}
	if (now+del==n) ans++;
	
	writeln(ans);
	
}
/*

*/