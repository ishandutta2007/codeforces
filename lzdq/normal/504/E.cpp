#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
const int k1=19260817,p1=1e9+7;
template <int T>
struct fast_io {
	char p[T], q[T], *p1, *p2, *q1, *q2;
	fast_io() {
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}
	inline char gc() {
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin)), p1 == p2 ? EOF : *p1++;
	}
	inline void pc(char c) {
		if (q1 == q2) q2 = (q1 = q) + fwrite(q, 1, T, stdout);
		*q1++ = c;
	}
	~fast_io() {
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1<<20> io;

int getint() {
	int res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + (ch & 15), ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}

template <typename T>
void _put(T x) {
	if (x >= 10) _put(x / 10);
	io.pc(48 ^ (x % 10));
}

template <typename T>
void Put(T x, char ch = ' ') {
	_put(x);
	io.pc(ch);
}
ll pw1[MAXN],inv1[MAXN];
ll Fstpw(ll a,int b,int mod){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int n,q;
char s[MAXN];
void getstr(){
	char ch=io.gc();
	while(ch<'a'||ch>'z') ch=io.gc();
	s[1]=ch;
	for(int i=2; i<=n; i++)
		s[i]=io.gc();
	return ;
}
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
struct node{
	int h1,len;
}f[MAXN],g[MAXN];
node operator +(node a,node b){
	static node c;
	c.h1=(a.h1*pw1[b.len]+b.h1)%p1;
	c.len=a.len+b.len;
	return c;
}
bool operator ==(node a,node b){
	return a.h1==b.h1&&a.len==b.len;
}
int fa[MAXN][20],dep[MAXN],son[MAXN],top[MAXN],mxd[MAXN];
void Dfs1(int u){
	f[u]=f[fa[u][0]]+node{s[u],1};
	g[u]=node{s[u],1}+g[fa[u][0]];
	mxd[u]=dep[u]=dep[fa[u][0]]+1;
	for(int i=1; fa[u][i]=fa[fa[u][i-1]][i-1]; i++);
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u][0]) continue;
		fa[v][0]=u;
		Dfs1(v);
		if(mxd[v]>mxd[son[u]]) son[u]=v;
		mxd[u]=max(mxd[u],mxd[v]);
	}
	return ;
}
vector<int> dw[MAXN],up[MAXN];
void Dfs2(int u){
	dw[top[u]].push_back(u);
	if(son[u]){
		top[son[u]]=top[u];
		Dfs2(son[u]);
	}
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u][0]||v==son[u]) continue;
		top[v]=v;
		Dfs2(v);
	}
	return ;
}
int Lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=18; ~i; i--)
		if(dep[fa[y][i]]>=dep[x])
			y=fa[y][i];
	if(x==y) return x;
	for(int i=18; ~i; i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int lg[MAXN];
int getfa(int x,int k){
	//printf("getfa %d %d\n",x,k);
	if(dep[x]<=k) return 0;
	if(!k) return x;
	x=fa[x][lg[k]];
	k-=1<<lg[k];
	int d=dep[x]-k,t=top[x];
	//printf("getfa %d %d\n",x,k);
	if(d>=dep[t]) return dw[t][d-dep[t]];
	return up[t][dep[t]-d];
}
inline node del_back(node a,node b){
	int h1=(a.h1-b.h1+p1)%p1*inv1[b.len]%p1;
	return (node){h1,a.len-b.len};
}
inline node del_front(node a,node b){
	int h1=(a.h1-b.h1*pw1[a.len-b.len]%p1+p1)%p1;
	return (node){h1,a.len-b.len};
}
inline node geth(int x,int p,int y,int l){
	//printf("geth %d %d %d %d\n",x,p,y,l);
	int k=dep[x]-dep[p]+1;
	if(l<=k) return del_back(g[x],g[getfa(x,l)]);
	return del_back(g[x],g[fa[p][0]])+del_front(f[getfa(y,k+dep[y]-dep[p]-l)],f[p]);
}
int main(){
	//freopen("in","r",stdin);
	//freopen("string.out","w",stdout);
	//scanf("%d",&n);
	n=getint();
	pw1[0]=inv1[0]=1;
	inv1[1]=Fstpw(k1,p1-2,p1);
	lg[0]=-1;
	for(int i=1; i<=n; i++){
		pw1[i]=pw1[i-1]*k1%p1;
		inv1[i]=inv1[i-1]*inv1[1]%p1;
		lg[i]=lg[i>>1]+1;
	}
	//scanf("%s",s+1);
	getstr();
	for(int i=1; i<n; i++){
		int u=getint(),v=getint();
		//scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	Dfs1(1);
	top[1]=1;
	Dfs2(1);
	for(int u=1; u<=n; u++)
		if(u==top[u]){
			int p=u;
			while(p&&dep[u]-dep[p]<=mxd[u]-dep[u]){
				up[u].push_back(p);
				p=fa[p][0];
			}
		}
	//scanf("%d",&q);
	q=getint();
	while(q--){
		int a=getint(),b=getint(),c=getint(),d=getint();
		//scanf("%d%d%d%d",&a,&b,&c,&d);
		int p1=Lca(a,b),p2=Lca(c,d);
		int l1=dep[a]+dep[b]-dep[p1]*2+1,l2=dep[c]+dep[d]-dep[p2]*2+1;
		int l=0,r=min(l1,l2);
		while(l<r){
			int mid=l+r+1>>1;
			if(geth(a,p1,b,mid)==geth(c,p2,d,mid)) l=mid;
			else r=mid-1;
		}
		Put(l,'\n');
		//printf("%d\n",l);
	}
	return 0;
}