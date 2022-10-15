// This code wrote by chtholly_micromaker(Myukiyomekya)
#include <bits/stdc++.h>
#define reg
#define int long long
#define ALL(x) (x).begin(),(x).end()
#define mem(x,y) memset(x,y,sizeof x)
#define sz(x) (int)(x).size()
#define ln putchar('\n')
#define lsp putchar(32)
#define pb push_back
#define MP std::make_pair
#ifdef _LOCAL_
#define dbg(x) std::cerr<<__func__<<"\tLine:"<<__LINE__<<' '<<#x<<": "<<x<<"\n"
#define dprintf(x...) std::fprintf(stderr,x)
#else
#define dbg(x) 42
#define dprintf(x...) 42
#endif
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
typedef std::pair<int,int> pii;
template <class t> inline void read(t &s){s=0;
signed f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();;s*=f;}
template<class t,class ...A> inline void read(t &x,A &...a){read(x);read(a...);}
template <class t> inline void write(t x){if(x<0)putchar('-'),x=-x;
static int buf[50],top=0;while(x)buf[++top]=x%10,x/=10;if(!top)buf[++top]=0;
while(top)putchar(buf[top--]^'0');}
inline void setIn(std::string s){freopen(s.c_str(),"r",stdin);return;}
inline void setOut(std::string s){freopen(s.c_str(),"w",stdout);return;}
inline void setIO(std::string s=""){setIn(s+".in");setOut(s+".out");return;}
template <class t>inline bool ckmin(t&x,t y){if(x>y){x=y;return 1;}return 0;}
template <class t>inline bool ckmax(t&x,t y){if(x<y){x=y;return 1;}return 0;}
inline int lowbit(int x){return x&(-x);}
const int MaxN=2e5+50;
const int inf=1e18;
std::vector<int> E[MaxN];
int A[MaxN],B[MaxN],n,q;
int L[MaxN],R[MaxN],rev[MaxN],dfncnt;
inline void dfs(int u,int fa)
{
	rev[L[u]=++dfncnt]=u,A[u]+=A[fa],B[u]+=B[fa];
	for(auto v:E[u])if(v!=fa)dfs(v,u);
	R[u]=dfncnt;
}
template<int F>
struct KTT
{
#define lson (u<<1)
#define rson (u<<1|1)
	struct Node
	{
		int k,x,ps,add;
		Node(){k=x=add=0,ps=inf;}
		Node(int a,int b,int c,int d){k=a,x=b,ps=c,add=d;}
	}a[MaxN<<2];
	friend Node operator + (const Node &a,const Node &b)
	{
		Node ret;
		if(a.k*a.x*F>b.k*b.x*F)ret.k=a.k,ret.x=a.x;
		else ret.k=b.k,ret.x=b.x;
		ret.ps=std::min(a.ps,b.ps);
		int nps=(a.k==b.k?inf:(b.k*b.x-a.k*a.x)/(a.k-b.k));
		if(nps>=0)ckmin(ret.ps,nps);
		return ret;
	}
	inline void pushup(int u){a[u]=a[lson]+a[rson];}
	inline int down(int u,int v)
	{
		if (a[u].ps<v) return 0;
		a[u].ps-=v,a[u].x+=v,a[u].add+=v;
		return 1;
	}
	inline void pushdown(int u)
	{
		if(a[u].add)down(lson,a[u].add),down(rson,a[u].add),a[u].add=0;
	}
	inline void modify(int u,int l,int r,int ql,int qr,int v)
	{
		if(ql<=l&&r<=qr)if(down(u,v))return;
		pushdown(u);
		reg int mid=(l+r)>>1;
		if(ql<=mid)modify(lson,l,mid,ql,qr,v);
		if(mid<qr)modify(rson,mid+1,r,ql,qr,v);
		pushup(u);
	}
	inline Node query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l&&r<=qr)return a[u];
		pushdown(u);
		reg int mid=(l+r)>>1;
		if(ql>mid)return query(rson,mid+1,r,ql,qr);
		if(mid>=qr)return query(lson,l,mid,ql,qr);
		return query(lson,l,mid,ql,qr)+query(rson,mid+1,r,ql,qr);
	}
	inline void buildtr(int u,int l,int r)
	{
		if(l==r)return a[u]=Node(B[rev[l]],A[rev[l]],inf,0LL),void();
		reg int mid=(l+r)>>1;
		buildtr(lson,l,mid),buildtr(rson,mid+1,r),pushup(u);
	}
	inline int Gv(Node x){return x.k*x.x;}
};
KTT<+1> T1;
KTT<-1> T2;
signed main(void)
{
	read(n,q);
	int opt,x,y;
	for(int i=2;i<=n;++i)read(x),E[x].pb(i);
	for(int i=1;i<=n;++i)read(A[i]);
	for(int i=1;i<=n;++i)read(B[i]);
	dfs(1,0);
	assert(dfncnt==n);
	T1.buildtr(1,1,n),T2.buildtr(1,1,n);
	while(q--)
	{
		read(opt,x);
		if(opt==1)
			read(y),T1.modify(1,1,n,L[x],R[x],+y),
			T2.modify(1,1,n,L[x],R[x],+y);
		else write(std::max(T1.Gv(T1.query(1,1,n,L[x],R[x])),
					-T2.Gv(T2.query(1,1,n,L[x],R[x])))),ln;
	}
	return 0;
}

/*
 * Check List:
 * 1. Input / Output File (OI)
 * 2. long long 
 * 3. Special Test such as n=1
 * 4. Array Size
 * 5. Memory Limit (OI) int is 4 and longlong is 8
 * 6. Mod (a*b%p*c%p not a*b*c%p  ,  (a-b+p)%p not a-b )
 * 7. Name ( int k; for(int k...))
 * 8. more tests , (T=2 .. more)
 * 9. blank \n after a case
*/