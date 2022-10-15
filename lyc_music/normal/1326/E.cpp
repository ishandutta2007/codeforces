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
//#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[N<<2],tag[N<<2];
int n,a[N],b[N],ans;
void pushup(int k)
{
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
void pushdown(int k)
{
	if (!tag[k]) return;
	tr[k<<1]+=tag[k];
	tr[k<<1|1]+=tag[k];
	tag[k<<1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void update(int k,int l,int r,int L,int R,int val)
{
	if (L<=l&&r<=R)
	{
		tr[k]+=val;
		tag[k]+=val;
		return;
	}
	int mid=l+(r-l)/2;
	pushdown(k);
	if (L<=mid) update(k<<1,l,mid,L,R,val);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,val);
	pushup(k);
}
int query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R)
	{
		return tr[k];
	}
	int mid=l+(r-l)/2,res=-n-1;
	pushdown(k);
	if (L<=mid) res=min(res,query(k<<1,l,mid,L,R));
	if (R>mid) res=min(res,query(k<<1|1,mid+1,r,L,R));
	return res;
}
void LYC_music()
{
	n=read();
	for (int i=1;i<=n;i++) a[read()]=i;
	for (int i=1;i<=n;i++) b[i]=read();
	ans=n;
	writesp(n);
	update(1,1,n,1,a[n],1);
	for (int i=1;i<n;i++)
	{
		update(1,1,n,1,b[i],-1);
		while (tr[1]<=0) update(1,1,n,1,a[--ans],1);
		writesp(ans);
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