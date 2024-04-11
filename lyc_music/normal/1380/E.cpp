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
int tr[N<<2],lf[N<<2],rf[N<<2];
int n,m;
int fa[N];
int siz[N];
int a[N];
vector<int>G[N];
int gf(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=gf(fa[x]);
}
void pushup(int k)
{
	tr[k]=tr[k<<1]+tr[k<<1|1];
	tr[k]+=(rf[k<<1]!=lf[k<<1|1]);
	lf[k]=lf[k<<1];
	rf[k]=rf[k<<1|1];
}
void update(int k,int l,int r,int L,int val)
{
	if (l==r)
	{
		tr[k]=0;
		lf[k]=val;
		rf[k]=val;
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L,val);
	else  update(k<<1|1,mid+1,r,L,val);
	pushup(k);
}
void LYC_music()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		update(1,1,n,i,a[i]);
		fa[i]=i;
		siz[a[i]]++;
		G[a[i]].push_back(i);
	}
	writeln(tr[1]);
	for (int i=1;i<m;i++)
	{
		int x=read(),y=read();
		x=gf(x),y=gf(y);
		if (siz[x]>siz[y]) swap(x,y);
		for (auto u:G[x])
		{
			G[y].push_back(u);
			update(1,1,n,u,y);
		}
		vector<int>().swap(G[x]);
		siz[y]+=siz[x];
		siz[x]=0;
		fa[x]=y;
		writeln(tr[1]);
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