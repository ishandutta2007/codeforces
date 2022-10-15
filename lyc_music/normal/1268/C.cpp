//The Hunting Party - Keys To The Kingdom
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
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[N],tr1[N];
int a[N];
int n;
int ans[N];
void update(int x,int y)
{
	for (;x<=n;x+=(x&-x))
	{
		tr[x]+=y;
	}
}
int query(int x)
{
	int res=0;
	for (;x;x-=(x&-x))
	{
		res+=tr[x];
	}
	return res;
}
void update1(int x,int y)
{
	for (;x<=n;x+=(x&-x))
	{
		tr1[x]+=y;
	}
}
int query1(int x)
{
	int res=0;
	for (;x;x-=(x&-x))
	{
		res+=tr1[x];
	}
	return res;
}
void LYC_music()
{
	n=read();
	for (int i=1;i<=n;i++) a[read()]=i;
	update(a[1],1);
	update1(a[1],a[1]);
	writesp(0);
	for (int i=2;i<=n;i++)
	{
		int l=1,r=n,now=0;
		update(a[i],1);
		update1(a[i],a[i]);
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (query(mid-1)<=query(n)-query(mid))
			{
				now=mid;
				l=mid+1;
			} else r=mid-1;
		}
//		cout<<"?"<<now<<" "<<query1(n)-query1(now)<<endl;
		ans[i]=ans[i-1]+query(n)-query(a[i]);
		int x=0;
		if (i%2==1)
		{
			x+=(i/2+1)*(i/2);
		} else
			x+=(i/2+1)*(i/2)/2+(i/2)*(i/2-1)/2;
		writesp(ans[i]+query1(n)-query1(now)-query1(now-(i%2))-x);
	}
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/