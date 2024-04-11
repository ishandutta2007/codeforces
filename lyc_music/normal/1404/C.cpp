//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
//#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int cnt;
pa tr[N<<2];
int lson[N<<2],rson[N<<2],c[N],tag[N<<2];
int n,q,a[N],b[N],Ans[N];
int rt1[N];
vector<pa>G[N];
void update1(int k)
{
	while (k<=n) 
	{
		c[k]+=1;
		k+=(k&(-k));
	}
}
int query1(int k)
{
	int res=0;
	while (k)
	{
		res+=c[k];
		k-=(k&(-k));
	}
	return res;
}
void pushup(int k)
{
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
void pushdown(int k)
{
	if (!tag[k]) return;
	tr[k<<1].fi+=tag[k];
	tr[k<<1|1].fi+=tag[k];
	tag[k<<1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void update(int k,int l,int r,int L,int R,int val)
{
	if (L>R) return;
//	cout<<k<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if (L<=l&&r<=R)
	{
		tr[k].fi+=val;
		tag[k]+=val;
		return;
	}
	int mid=l+(r-l)/2;
	pushdown(k);
	if (L<=mid) update(k<<1,l,mid,L,R,val);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,val);
	pushup(k);
}
pa query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) return tr[k];
	pushdown(k);
	int mid=l+(r-l)/2;
	pa res=mp(inf,0);
	if (L<=mid) res=min(res,query(k<<1,l,mid,L,R));
	if (R>mid) res=min(res,query(k<<1|1,mid+1,r,L,R));
	return res;
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		tr[k]={b[l],l};
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void LYC_music()
{
	n=read();q=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=i-a[i];
	for (int i=1;i<=n;i++)
		if (b[i]<0)
		{
			b[i]=inf;
		}
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		G[l+1].push_back({n-r,i});
	}
	build(1,1,n);
	int del1=0;
	for (int i=n;i>=1;i--)
	{
		pa u=query(1,1,n,i,n);
		while (u.fi<=0)
		{
//			cout<<"?"<<i<<" "<<u.fi<<" "<<u.se<<endl;
			update(1,1,n,u.se+1,n,-1);
			update(1,1,n,u.se,u.se,inf);
			update1(u.se);
			u=query(1,1,n,i,n);
		}
		for (auto u:G[i])
		{
			Ans[u.se]=query1(u.fi)-query1(i-1);
		}
	}
	for (int i=1;i<=q;i++) writeln(Ans[i]);
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
13 5

1 2 3 4 5 6 7 8 9 10 11  12 13 
2 2 3 9 5 4 6 5 7 8  3   11 13
*/