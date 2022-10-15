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
int calc(int x,int y,int t)
{
	return a[x]*a[y]+t*(a[x]+a[y]);
}
int gt(int t)
{
	int ans=0;
	int p=n+1;
	for (int i=2;i<n;i++)
	{
		ans+=min(calc(1,i,t),calc(n,i,t));
	}
	int xx=calc(1,n,t);
	ans+=xx;
	return ans;
}		
void BellaKira()
{
	n=read();
	int sm=0;
	for (int i=1;i<=n;i++) a[i]=read(),sm+=a[i];
	sort(a+1,a+n+1);
	if (a[1]*(n-2)+sm>0||a[n]*(n-2)+sm<0) 
	{
		puts("INF");
		return;
	}
	int L=a[1],R=a[n];
	int L1=L,R1=R;
	int nowans=L;
	while (L<=R)
	{
		int mid=L+(R-L)/3,mid1=R-(R-L)/3;
		if (gt(mid)<gt(mid1))
		{
			nowans=mid1;
			L=mid+1;
		} else
		{
			nowans=mid;
			R=mid1-1;
		}
	}
	writeln(gt(nowans));
			
			
	
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