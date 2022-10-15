//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
//#define ll ll
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf (1ll<<60)
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
//#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}

inline void write(ll x){if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}

int n,m,a[N],b[N],p[N];
ll ans;
int sm;
bool cmp(int x,int y)
{
	return b[x]-a[x]<b[y]-a[y];
}
struct
{
	int tr[N<<2],tag[N<<2];
	inline void pushup(int k)
	{
		tr[k]=min(tr[k<<1],tr[k<<1|1]);
	}
	inline void pushdown(int k)
	{
		if (!tag[k]) return;
		tag[k<<1]+=tag[k];
		tag[k<<1|1]+=tag[k];
		tr[k<<1]+=tag[k];
		tr[k<<1|1]+=tag[k];
		tag[k]=0;
	}
	inline void build(int k,int l,int r,int val)
	{
		if (l==r)
		{
			tr[k]=val+l;
			return;
		}
		int mid=l+(r-l)/2;
		build(k<<1,l,mid,val);
		build(k<<1|1,mid+1,r,val);
		pushup(k);
	}
	inline void update(int k,int l,int r,int L,int R,int del)
	{
		if (L<=l&&r<=R)
		{
			tr[k]+=del;
			tag[k]+=del;
			return;
		}
		int mid=l+(r-l)/2;
		pushdown(k);
		if (L<=mid) update(k<<1,l,mid,L,R,del);
		if (R>mid) update(k<<1|1,mid+1,r,L,R,del);
		pushup(k);
	}
	inline int query(int k,int l,int r,int L,int R)
	{
		if (L<=l&&r<=R) return tr[k];
		int mid=l+(r-l)/2,res=inf;
		pushdown(k);
		if (L<=mid) res=min(res,query(k<<1,l,mid,L,R));
		if (R>mid) res=min(res,query(k<<1|1,mid+1,r,L,R));
		return res;
	}
}tr1,tr2,tr3;
signed main()
{
//	freopen("tryagain.in","r",stdin);
//	freopen("tryagain.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=a[i+n]=read();
	}
	for (int i=1;i<=n;i++)
	{
		b[i]=b[i+n]=read();
	}
	n=n*2,m/=2;
	for (int i=1;i<=n;i++) ans+=a[i];
	ans*=m;
	if (m*n<=1000000)
	{
		for (int i=n+1;i<=n*m;i++)
			a[i]=a[i-n];
		for (int i=n+1;i<=n*m;i++)
			b[i]=b[i-n];
		for (int i=1;i<=n*m;i++) p[i]=i;
		sort(p+1,p+n*m+1,cmp);
		tr1.build(1,1,n*m,0);
		for (int i=1;i<=n*m;i++)
		{
			int u=p[i];
			if (tr1.query(1,1,n*m,u,n*m)>=2)
			{
				tr1.update(1,1,n*m,u,n*m,-2);
				ans+=(ll)(b[u]-a[u]);
				sm+=1;
			}
			if (sm==n*m/2) break;
		}
		writeln(ans);
		return 0;
	}
	tr1.build(1,1,n,0);
	tr2.build(1,1,n,n*(m-2));
	tr3.build(1,1,n,n*(m-1));
	for (int i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+n+1,cmp);
//	writeln(ans);
	for (int i=1;i<=n;i++)
	{
		int j=p[i];
		if (tr1.query(1,1,n,j,n)>=2&&tr2.query(1,1,n,j,n)>=2*(m-1)&&tr2.query(1,1,n,1,n)>=2*(m-2)&&tr3.query(1,1,n,j,n)>=2*m&&tr3.query(1,1,n,1,n)>=2*(m-1))
		{
			tr1.update(1,1,n,j,n,-2);
			tr2.update(1,1,n,1,n,-2*(m-2));
			tr2.update(1,1,n,j,n,-2);
			tr3.update(1,1,n,1,n,-2*(m-1));
			tr3.update(1,1,n,j,n,-2);
			ans+=(ll)(b[j]-a[j])*m;
			sm+=m;
		} else
		if (tr2.query(1,1,n,j,n)>=2*(m-2)&&tr2.query(1,1,n,1,n)>=2*(m-3)&&tr3.query(1,1,n,1,n)>=2*(m-2)&&tr3.query(1,1,n,j,n)>=2*(m-1))
		{
			tr2.update(1,1,n,1,n,-2*(m-3));
			tr2.update(1,1,n,j,n,-2);
			tr3.update(1,1,n,1,n,-2*(m-2));
			tr3.update(1,1,n,j,n,-2);
			ans+=(ll)(b[j]-a[j])*(m-1);
			sm+=m-1;
		} else
		if (tr3.query(1,1,n,j,n)>=2)
		{
			tr3.update(1,1,n,j,n,-2);
			ans+=(ll)(b[j]-a[j]);
			sm+=1;
		}
		if (sm==n*m/2) break;
	}
	writeln(ans);	
}
/*
2 2
4 100 
96 30 

1777121053130538551
34248607756555550046


*/