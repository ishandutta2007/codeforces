//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
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
struct node
{
	int mx,sum;
}tr[N<<2];
int T,n,a[N],b[N],ans,c[N];
set<int>S;
void pushup(int k)
{
	tr[k].mx=max(tr[k<<1].mx,tr[k<<1].sum+tr[k<<1|1].mx);
	tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
}
void build(int k,int l,int r)
{
	if (l==r) tr[k].mx=tr[k].sum=-1,tr[k].mx+=(l%2==0);
	else
	{
		build(k<<1,l,l+(r-l)/2);
		build(k<<1|1,l+(r-l)/2+1,r);
		pushup(k);
	}
}
void update(int k,int l,int r,int p,int val)
{
	if (l==r) 
	{
		tr[k].mx=tr[k].sum=val,tr[k].mx+=(l%2==0);
		return;
	}
	int mid=l+(r-l)/2;
	if (p<=mid) update(k<<1,l,mid,p,val);
	else update(k<<1|1,mid+1,r,p,val);
	pushup(k);
}
node query(int k,int l,int r,int L,int R)
{
//	cout<<k<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if (L<=l&&r<=R) return tr[k];
	int mid=l+(r-l)/2;
	if (L<=mid&&R>mid) 
	{
		node x=query(k<<1,l,mid,L,R),y=query(k<<1|1,mid+1,r,L,R);
		x.mx=max(x.mx,x.sum+y.mx);
		x.sum+=y.sum;
		return x;
	} else
	if (L<=mid) return query(k<<1,l,mid,L,R);
	if (R>mid) return query(k<<1|1,mid+1,r,L,R);
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read(); ans=0;
		for (int i=1;i<=n;i++) a[i]=read(),b[a[i]]=i,c[i]=0;
		int r=n,l=n;
		build(1,1,n);
		for (int i=n;i>=1;i--)
		{
			c[b[i]]=1;
			while (c[r]) r--;
			update(1,1,n,b[i],1);
			l=min(l,b[i]);
			if (r!=i-1)
			{
//				cout<<l<<" "<<i<<" "<<query(1,1,n,l+1,r).mx<<endl;
				if (query(1,1,n,l+1,r).mx==-1)
					ans=max(ans,i-l+(l%2==0));
				else 
				ans=max(ans,i-l+max(0ll,query(1,1,n,l+1,r).mx));
			}
		}
		writeln(ans);
	}
}
/*
1
9
1 2 6 9 7 4 8 3 5
*/