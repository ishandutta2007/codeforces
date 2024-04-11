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
int n,q,a[N],x,y,z;
struct node
{
	int l,sm,L,R,L1,R1;
}tr[N<<2];
node merge(node x,node y)
{
	node res;
	res.l=x.l+y.l;
	res.sm=x.sm+y.sm;
	res.L=x.L,res.L1=x.L1;
	res.R=y.R;res.R1=y.R1;
	if (y.R==y.l&&x.R1<=y.L1) res.R+=x.R;
	if (x.R1<=y.L1) res.sm+=x.R*y.L;
	if (x.L==x.l&&x.R1<=y.L1) res.L+=y.L;
	return res;
}
void build(int k,int l,int r)
{
	if (l==r) 
	{
		tr[k].l=1,tr[k].sm=1,tr[k].L=1,tr[k].L1=a[l],tr[k].R=1,tr[k].R1=a[l];
		return;
	}
	build(k<<1,l,l+(r-l)/2);
	build(k<<1|1,l+(r-l)/2+1,r);
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
}
void update(int k,int l,int r,int p,int val)
{
	if (l==r)
	{
		tr[k].L1=tr[k].R1=val;
		return;
	}
	int mid=l+(r-l)/2;
	if (p<=mid) update(k<<1,l,mid,p,val);
	else update(k<<1|1,mid+1,r,p,val);
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
}
node query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) return tr[k];
	int mid=l+(r-l)/2;
	if (R<=mid) return query(k<<1,l,mid,L,R);
	if (L>mid) return query(k<<1|1,mid+1,r,L,R);
	return merge(query(k<<1,l,mid,L,R),query(k<<1|1,mid+1,r,L,R));
}	
signed main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	while (q--)
	{
		x=read();
		if (x==1) y=read(),z=read(),update(1,1,n,y,z);
		else y=read(),z=read(),writeln(query(1,1,n,y,z).sm);
	}
}
/*

*/