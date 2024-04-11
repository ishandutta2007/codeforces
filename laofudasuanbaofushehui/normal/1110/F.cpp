#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
#include<assert.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

template<typename T>inline bool upmin(T &x,T y) { return y<x?x=y,1:0; }
template<typename T>inline bool upmax(T &x,T y) { return x<y?x=y,1:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1LL<<62;
const int mod=1e9+7;

int qpow(int x,int y) {
	int ans=1;
	while (y) {
		if (y&1) ans=1LL*ans*x%mod;
		x=1LL*x*x%mod;y>>=1;
	}
	return ans;
}

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

namespace io {
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	inline char getc() {
		return gc();
	}
	inline void flush() {
		fwrite(obuf,1,oS-obuf,stdout);
		oS=obuf;
	}
	inline void putc(char x) { *oS++=x; if (oS==oT) flush(); }
	template<class I> inline bool gi(I&x) {
		for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1; else if (c==-1) return false;
		for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
		return true;
	}
	template<class I> inline void print(I x) {
		if (!x) putc('0');
		if (x<0) putc('-'),x=-x;
		while (x) st[++tp]=x%10+'0',x/=10;
		while (tp) putc(st[tp--]);
	}
	inline bool gs(char*s, int&l) {
		for (c=gc();c<'a'||c>'z';c=gc()) if (c==-1) return false;
		for (l=0;c<='z'&&c>='a';c=gc()) s[l++]=c;
		s[l]=0;
		return true;
	}
	inline void printld(double x, int digit) {
		if (x < 0) putc('-'), x = -x;
		x += 0.5 * pow(0.1, digit);
		print((LL)x), putc('.');
		for (x -= (LL)x; digit; --digit) x = x * 10, putc((int)x + '0'), x -= (int)x;
	}
	inline void ps(const char*s) { for (int i=0,n=strlen(s);i<n;i++) putc(s[i]); }
	struct IOFLUSHER{ ~IOFLUSHER() { flush(); } } _ioflusher_;
};
using io::getc;
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;
using io::printld;

const int N=1e6+100;

struct Tag{
	LL w;
	friend Tag operator + (const Tag &a,const Tag &b) { return (Tag){a.w+b.w}; }
	void clear() { w=0; }
};
struct Node{
	LL w;
	friend Node operator + (const Node &a,const Node &b) { return (Node){min(a.w,b.w)}; }
	Node operator + (const Tag &b) { return (Node){w+b.w}; }
	void init(LL _w) { w=_w; }
};

template<typename Tag,typename Node>struct segment_tree{
#define lc (i<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)

	Tag tag[N*4];
	Node s[N*4];

	void mark(int i,int l,int r,Tag t) {
		s[i]=s[i]+t;
		tag[i]=tag[i]+t;
	}

	void pushdown(int i,int l,int r) {
		mark(lc,l,mid,tag[i]);
		mark(rc,mid+1,r,tag[i]);
		tag[i].clear();
	}

	void update(int i) {
		s[i]=s[lc]+s[rc];
	}

	void build(int i,int l,int r) {
		tag[i].clear();
		if (l==r) s[i].init(i,l);
		else {
			build(lc,l,mid);
			build(rc,mid+1,r);
			update(i);
		}
	}

	void modify(int i,int l,int r,int L,int R,Tag t) {
		if (L<=l&&r<=R) mark(i,l,r,t);
		else {
			pushdown(i,l,r);
			if (L<=mid) modify(lc,l,mid,L,R,t);
			if (mid<R) modify(rc,mid+1,r,L,R,t);
			update(i);
		}
	}

	void modify(int i,int l,int r,int k,Node t) {
		if (l==r) s[i]=t;
		else {
			pushdown(i,l,r);
			k<=mid?modify(lc,l,mid,k,t):modify(rc,mid+1,r,k,t);
			update(i);
		}
	}

	Node query(int i,int l,int r,int L,int R) {
		if (L<=l&&r<=R)
			return s[i];
		else {
			pushdown(i,l,r);
			if (R<=mid) return query(lc,l,mid,L,R);
			if (mid<L) return query(rc,mid+1,r,L,R);
			return query(lc,l,mid,L,R)+query(rc,mid+1,r,L,R);
		}
	}
	
#undef lc
#undef rc
#undef mid
};
segment_tree<Tag,Node>T;

int n,tot,L[N],R[N];
VI e[N],q[N];LL d[N];
LL ans[N];
int l[N],r[N];
void dfs1(int k,LL s) {
	l[k]=++tot;
	s+=d[k];
	if (e[k].empty())
		T.modify(1,1,n,l[k],(Node){s});
	else {
		T.modify(1,1,n,l[k],(Node){OO});
		for (int t:e[k])
			dfs1(t,s);
	}
	r[k]=tot;
}
void dfs2(int k) {
	for (int t:q[k])
		ans[t]=T.query(1,1,n,L[t],R[t]).w;
	for (int t:e[k]) {
		T.modify(1,1,n,1,l[t]-1,(Tag){d[t]});
		T.modify(1,1,n,l[t],r[t],(Tag){-d[t]});
		if (r[t]!=n) T.modify(1,1,n,r[t]+1,n,(Tag){d[t]});
		dfs2(t);
		T.modify(1,1,n,1,l[t]-1,(Tag){-d[t]});
		T.modify(1,1,n,l[t],r[t],(Tag){d[t]});
		if (r[t]!=n) T.modify(1,1,n,r[t]+1,n,(Tag){-d[t]});
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int m,i,k;
	gi(n),gi(m);
	for (i=2;i<=n;i++)
		gi(k),e[k].pb(i),gi(d[i]);
	dfs1(1,0);
	for (i=1;i<=m;i++)
		gi(k),gi(L[i]),gi(R[i]),q[k].pb(i);
	dfs2(1);
	for (i=1;i<=m;i++)
		print(ans[i]),putc(10);
	return 0;
}