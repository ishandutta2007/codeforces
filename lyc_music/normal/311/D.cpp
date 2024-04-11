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
//#define mod 998244353
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}

ll mod;
int n,q,opt,l,r,a[N];
template<ll M,ll md>
struct ss
{
	ll s[N<<2][55];
	int tr[N<<2],tag[N<<2];
	inline void pushup(int k)
	{
		for (int i=0;i<M;i++)
			s[k][i]=
			(1ll*s[k<<1][(tr[k<<1]+i)%M]+
			1ll*s[k<<1|1][(tr[k<<1|1]+i)%M])%md;
	}
	void build(int k,int l,int r)
	{
		tr[k]=0,tag[k]=0;
		if (l==r)
		{
			tr[k]=0;
			ll val=a[l]%md;
			s[k][0]=val%md;
			for (int i=1;i<M;i++)
				s[k][i]=1LL*val*1ll*val%md*1ll*val%md,val=s[k][i];
			return;
		}
		int mid=l+(r-l)/2;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		pushup(k);
	}
	inline void pushdown(int k)
	{
		tr[k<<1]+=tr[k];tr[k<<1|1]+=tr[k];
		tr[k<<1]%=M,tr[k<<1|1]%=M;
		tr[k]=0;
	}
	void update(int k,int l,int r,int p,int val,int del)
	{
		if (l==r)
		{
			tr[k]=0;
			s[k][0]=val%md;
			for (int i=1;i<M;i++)
				s[k][i]=1LL*val*1ll*val%md*1ll*val%md,val=s[k][i];
			return;
		}
		int mid=l+(r-l)/2;
		pushdown(k);
		if (p<=mid)  update(k<<1,l,mid,p,val,del);
		else update(k<<1|1,mid+1,r,p,val,del);
		pushup(k);
	}
	void update1(int k,int l,int r,int L,int R)
	{
		if (L<=l&&r<=R)
		{
			tr[k]++;
			tr[k]%=M;
			return;
		}
		int mid=l+(r-l)/2;
		if (L<=mid) 
			update1(k<<1,l,mid,L,R);
		if (R>mid) update1(k<<1|1,mid+1,r,L,R);
		pushup(k);
	}
	int query(int k,int l,int r,int L,int R,int del)
	{
		del+=tr[k];
		(del>=M)?del-=M:0;
		if (L<=l&&r<=R) 
		{
//			cout<<del<<endl;
			return s[k][del];
		}
		int mid=l+(r-l)/2;
		ll res=0;
		if (L<=mid) 
			res+=query(k<<1,l,mid,L,R,del);
		if (R>mid) res+=query(k<<1|1,mid+1,r,L,R,del);
		res%=md;
		pushup(k);
		return res;
	}
};
ss<48,95542721>s;
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) 
	{
		a[i]=read();
	}q=read();
	s.build(1,1,n);
	while (q--)
	{
		opt=read(),l=read(),r=read();
		if (opt==1)
		{
			writeln(s.query(1,1,n,l,r,0));
//			writeln(s.query(1,1,n,l,r,0));
//			writeln(t.query(1,1,n,l,r,0));
		} else
		if (opt==2)
			s.update1(1,1,n,l,r);
	}
}
/*

5 3
2 1 3 2 4
1 1 1
3 2 4
2 2 6
1 1 5



20 9
2 1 3 2 4 2 1 3 2 4 2 1 3 2 4 2 1 3 2 4
3 3 13
1 3 4
2 3 42874
3 5 16
3 1 5
1 1 7 
1 3 19
2 7 12837
1 2 18
*/