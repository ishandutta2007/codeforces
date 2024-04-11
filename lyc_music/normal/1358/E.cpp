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
#define N 500005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,a[N],c[N],b[N],s[N],s1[N];
int x;
#define lowbit(x) (x&(-x))
void update(int k,int x)
{
	while (k<=m)
	{
		c[k]=min(c[k],x);
		k+=lowbit(k);
	}
}
int query(int k)
{
	int res=inf;
	while (k)
	{
		res=min(res,c[k]);
		k-=lowbit(k);
	}
	return res;
}
signed main()
{
	n=read();m=n/2+n%2;
	for (int i=1;i<=m;i++) a[i]=read();
	x=read();
	memset(c,0x3f,sizeof(c));
	for (int i=1;i<=m;i++) b[i]=x-a[i],s[i]=s[i-1]+a[i],s1[i]=s1[i-1]+b[i],update(i,s1[i]);
	for (int i=m;i<=n;i++)
	{
		int sm=s[m]+x*(i-m);
//		cout<<sm<<endl;
		if (sm<=0)
		{
			continue;
		}
		sm+=query(n-i); 
//		cout<<"!"<<sm<<endl;
		if (sm<=0) continue;
		writeln(i);
		return 0;
	}
	puts("-1");
}
/*

*/