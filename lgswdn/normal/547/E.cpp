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

const int N=5e5+9;

int n,m,ans[N*2],p[N*2];
vector<char> s[N];
vi q[N];
char tmp[N];

namespace BIT {
	int s[N];
	int lb(int x) {return x&-x;}
	void mdf(int x,int mx) {for(;x<=mx;x+=lb(x)) s[x]++;}
	int qry(int x,int y=0) {for(;x;x-=lb(x)) y+=s[x]; return y;}
	int query(int l,int r) {return qry(r)-qry(l-1);}
}

namespace ACA {
	int tot,c[N][29],g[N],ps[N],ft[N],ff[N],dfn[N],tick,sz[N];
	vi e[N];
	void build() {
		queue<int>q; rep(i,0,25) if(c[0][i]) q.push(c[0][i]);
		while(!q.empty()) {
			int u=q.front(); q.pop();
			rep(i,0,25)
				if(!c[u][i]) c[u][i]=c[ff[u]][i];
				else ff[c[u][i]]=c[ff[u]][i], q.push(c[u][i]);
		}
		rep(i,1,tot) e[ff[i]].emplace_back(i);
	}
	void dfs(int u) {
		dfn[u]=++tick, sz[u]=1;
		for(auto v:e[u]) dfs(v), sz[u]+=sz[v];
	}
	void init() {
		build(); dfs(0);
	}

	void insert(vector<char> s,int len,int id) {
		int pos=0;
		rep(i,0,len-1) {
			int npos=(c[pos][s[i]-'a']?c[pos][s[i]-'a']:++tot);
			ft[npos]=pos, c[pos][s[i]-'a']=npos, pos=npos;
		}
		g[pos]++, ps[id]=pos;
	}
	void add(int id) {
		int u=ps[id];
		for(;u;u=ft[u]) BIT::mdf(dfn[u],tick);
	}
	int qry(int id) {
		int u=ps[id];
		return BIT::query(dfn[u],dfn[u]+sz[u]-1);
	}
}

signed main() {
	n=read(), m=read();
	rep(i,1,n) {
		scanf("%s",tmp); int len=strlen(tmp);
		rep(j,0,len-1) s[i].emplace_back(tmp[j]);
		ACA::insert(s[i],len,i);
	}
	rep(i,1,m) {
		int l=read(), r=read(), k=read();
		p[i*2-1]=p[i*2]=k;
		q[l-1].emplace_back(i*2-1), q[r].emplace_back(i*2);
	}
	ACA::init();
	rep(i,1,n) {
		ACA::add(i);
		for(auto id:q[i]) ans[id]=ACA::qry(p[id]);
	}
	rep(i,1,m) printf("%lld\n",ans[i*2]-ans[i*2-1]);
	return 0;
}