#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=159,inf=0x3f3f3f3f3f3f3f3f;
int n,m,ans=inf,d[N];
struct edge {int u,v,w;} ed[N];
vi e[N];
bitset<N> p;

bool cmp(const edge &a,const edge &b) {return a.w<b.w;}

void bfs(int base,vi s) {
	rep(i,1,n) d[i]=inf;
	queue<int>q;
	for(auto x:s) d[x]=0, q.push(x);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(auto v:e[u]) if(d[v]==inf) d[v]=d[u]+1, q.push(v);
	}
	ans=min(ans,base+d[n]);
}

struct mat {
	bitset<N>a[N];
	friend bitset<N> operator * (mat x,bitset<N> y) {
		bitset<N> z;
		rep(i,1,n) z[i]=(x.a[i]&y).any();
		return z;
	}
	friend mat operator * (mat x,mat y) {
		mat z;
		rep(i,1,n) rep(j,1,n) if(x.a[i][j]) z.a[i]|=y.a[j];
		return z;
	}
} mt;
bitset<N> ksm(mat x,int y,bitset<N>res) {
	for(;y;y>>=1,x=x*x) if(y%2) res=x*res;
	return res;
}

signed main() {
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read(), w=read();
		ed[i]=(edge){u,v,w};
	}
	sort(ed+1,ed+m+1,cmp); p[1]=1;
	rep(i,1,m) {
		e[ed[i].u].emplace_back(ed[i].v);
		p=ksm(mt,ed[i].w-ed[i-1].w,p);
		mt.a[ed[i].v][ed[i].u]=1;
		vi g;
		rep(i,1,n) if(p[i]) g.emplace_back(i);
		bfs(ed[i].w,g);
	}
	if(ans==inf) puts("Impossible");
	else printf("%lld\n",ans);
	return 0;
}