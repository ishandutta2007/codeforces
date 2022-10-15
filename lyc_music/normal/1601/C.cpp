//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf (1e9+7)
#define mod 998244353
//#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
//#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
pa tr[N<<2];
int tag[N<<2];
int B[N],A[N];
int a[N],d[N],b[N];
int lst;
pa c[N];
int lstans;
ll ans;
int n,T,m;
inline void pushup(int k)
{
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
inline void pushdown(int k)
{
	if (!tag[k]) return;
	tr[k<<1].fi+=tag[k];
	tr[k<<1|1].fi+=tag[k];
	tag[k<<1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void build(int k,int l,int r)
{
	tag[k]=0;
	if (l==r)
	{
		tr[k]={0,l};
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void update(int k,int l,int r,int L,int R,int val)
{
	if (L<=l&&r<=R)
	{
		tr[k].fi+=val;
		tag[k]+=val;
		return;
	}
	pushdown(k);
	int mid=l+(r-l)/2;
	if (L<=mid)
	{
		update(k<<1,l,mid,L,R,val);
	}
	if (R>mid) update(k<<1|1,mid+1,r,L,R,val);
	pushup(k);
}
pa query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) return tr[k];
	int mid=l+(r-l)/2;
	pushdown(k);
	if (L<=mid) return query(k<<1,l,mid,L,R);
	return query(k<<1|1,mid+1,r,L,R);
}
void merge(int l,int r)
{
	if (l==r) 
	{
		B[l]=A[l];
		return;
	}
	int mid=l+(r-l)/2;
	merge(l,mid),merge(mid+1,r);
	int x=l,y=mid+1,now=l;
	while (x<=mid&&y<=r)
	{
		if (A[x]<=A[y]) B[now++]=A[x++];
		else ans+=mid-x+1,B[now++]=A[y++];
	}
	while (x<=mid)
	{
		B[now++]=A[x];
		x++;
	}
	while (y<=r)
	{
		B[now++]=A[y];
		y++;
	}
	for (int i=l;i<=r;i++) A[i]=B[i];
}	
signed main()
{
//	freopen("data.in","r",stdin);
	T=read();
	while (T--)
	{
		n=read();m=read();
		ans=0;
		b[m+1]=inf;
		for (int i=1;i<=n;i++) a[i]=read(),c[i]={a[i],i},A[i]=a[i];
		merge(1,n);
		sort(c+1,c+n+1);
		c[n+1].fi=inf;
		int x=1;
		for (int i=1;i<=m;i++) b[i]=read();
		sort(b+1,b+m+1);
		while (x<=n&&c[x].fi<b[1]) x++;
		build(1,0,n);
		for (int i=1;i<=n;i++)
		{
			if (a[i]>b[1])
			{
				update(1,0,n,i,n,1);
			} else
			if (a[i]<b[1])
			{
				update(1,0,n,0,i-1,1);
			}
		}
		lstans=0;
		lst=x-1;
		for (int i=1;i<=m;i++)
		{
			pa u=tr[1];
			if (b[i]==b[i+1])
			{
				ans+=u.fi;
				continue;
			}
			ans+=u.fi;
			lstans=u.fi;
			d[i]=u.se;
			while (x<=n&&c[x].fi<=b[i+1])
			{
				if (c[x].fi>b[i]) update(1,0,n,c[x].se,n,-1);
				if (c[x].fi!=b[i+1])
				{
					update(1,0,n,0,c[x].se-1,1);
					lst=x;
				}
				x++;
			}
			x=lst+1;
		}
		writeln(ans);
	}
}
/*
2
8 4
98 77 67 52 75 7 87 32 
39 48 83 37 
*/