//~~
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
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tag[N<<2];
int tr[N<<2];
int suf[N],pre[N];
int a[N];
vector<int>M[N];
int nxt[N];
int n,ans;
int lft[N],rgt[N];
int L[N],R[N];
int p[N];
bool cmp(int x,int y)
{
	return lft[x]<lft[y];
}
void pushdown(int k)
{
	if (!tag[k]) return;
	tr[k<<1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tr[k<<1|1]+=tag[k];
	tag[k<<1]+=tag[k];
	tag[k]=0;
}
void pushup(int k)
{
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
void build(int k,int l,int r)
{
	tag[k]=0;
	if (l==r)
	{
		tr[k]=suf[l+1];
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void update(int k,int l,int r,int L,int R,int val)
{
	// cout<<k<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<val<<endl;
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
	if (L>R) return inf;
	if (L<=l&&r<=R)
	{
		return tr[k];
	}
	int mid=l+(r-l)/2;
	pushdown(k);
	int res=inf;
	if (L<=mid) res=min(res,query(k<<1,l,mid,L,R));
	if (R>mid) res=min(res,query(k<<1|1,mid+1,r,L,R));
	return res;
}
void BellaKira()
{
	n=read();
	ans=inf;
	for (int i=1;i<=n;i++) a[i]=read(),M[a[i]].push_back(i);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+(a[i]==0);
	suf[n+1]=0;
	nxt[n+1]=n+1;
	for (int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+(a[i]==0),nxt[i]=nxt[i+1];
		if (a[i]==0) nxt[i]=i;
	}
	if (pre[n]==0)
	{
		for (int i=1;i<=n;i++) M[i].clear();
		return puts("0"),void();
	}
	int tot0=pre[n];
	for (int i=1;i<=n;i++)
		if (pre[i]>tot0/2) R[i]=1,L[i]=0;
		else L[i]=1,R[i]=0;
	build(1,0,n);
	// return;
	for (int i=1;i<=n;i++)
	{
		lft[i]=0,rgt[i]=n+1;
		for (auto u:M[i])
		{
			if (L[u]) lft[i]=u;
		}
		reverse(M[i].begin(),M[i].end());
		for (auto u:M[i])
		{
			if (R[u]) rgt[i]=u;
		}
	}
	for (int i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+n+1,cmp);
	int lt=1;
	while (lt<=n&&pre[lft[p[lt]]]<=pre[0]) update(1,0,n,0,nxt[rgt[p[lt]]]-1,-1),lt++;
	ans=min(ans,n+query(1,0,n,0,n));
	// cout<<"?"<<Pl<<endl;
	for (int i=1;i<=n;i++)
	{
		while (lt<=n&&pre[lft[p[lt]]]<=pre[i]) update(1,0,n,0,nxt[rgt[p[lt]]]-1,-1),lt++;
		// cout<<"?"<<lt<<" "<<endl;
		ans=min(ans,n+query(1,0,n,i,n)+pre[i]);
	}
	writeln(min(ans,tot0/2));
	for (int i=1;i<=n;i++) M[i].clear();
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/