#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
#define LOGN 18
int p[N][20],x,y,n,m,q,dep[N],go[N][20],mind[N][20];
set<PII> pool[N];
set<PII>* ins[N];
VI e[N];
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}

void upd(int &a,int b) { if (dep[b]<dep[a]) a=b;}

int tot,l[N],r[N],c[N],vis[N],cur[N],ret[N];
void dfs(int u,int f) {
	l[u]=++tot;
	for (auto v:e[u]) dfs(v,u);
	r[u]=tot;
}
void modify(int x,int s) { for (;x<=n;x+=x&-x) c[x]+=s; }
int query(int x) { int s=0; for (;x;x-=x&-x) s+=c[x]; return s; }
vector<pair<int,PII> > evt;

int main() {
	scanf("%d",&n);
	dep[1]=1;
	rep(i,2,n+1) {
		scanf("%d",&x);
		p[i][0]=x;
		dep[i]=dep[x]+1;
		e[x].pb(i);
	}
	dfs(1,0);
	rep(j,1,LOGN) rep(i,1,n+1) p[i][j]=p[p[i][j-1]][j-1];
	scanf("%d",&m);
	rep(i,1,n+1) go[i][0]=i;
	rep(i,0,m) {
		scanf("%d%d",&x,&y);
		int w=lca(x,y);
		upd(go[x][0],w); upd(go[y][0],w);
		evt.pb(mp(l[x],mp(-1e9,l[y])));
		evt.pb(mp(l[y],mp(-1e9,l[x])));
	}
	per(i,2,n+1) upd(go[p[i][0]][0],go[i][0]);
	rep(k,1,LOGN) for (int i=1;i<=n;i++) {
		go[i][k]=go[i][k-1]; upd(go[i][k],go[go[i][k-1]][k-1]);
	}
	scanf("%d",&q);
	rep(i,1,q+1) {
		scanf("%d%d",&x,&y);
		int w=lca(x,y);
		if (dep[go[x][LOGN-1]]>dep[w]||dep[go[y][LOGN-1]]>dep[w]) {
			ret[i]=-1; continue;
		}
		per(j,0,LOGN) if (dep[go[x][j]]>dep[w]) {
			x=go[x][j]; ret[i]+=(1<<j);
		}
		per(j,0,LOGN) if (dep[go[y][j]]>dep[w]) {
			y=go[y][j]; ret[i]+=(1<<j);
		}
		if (w==x||w==y) { ret[i]++; continue; }
		vis[i]=1;
		evt.pb(mp(l[x]-1,mp(i,l[y]-1)));
		evt.pb(mp(l[x]-1,mp(-i,r[y])));
		evt.pb(mp(r[x],mp(-i,l[y]-1)));
		evt.pb(mp(r[x],mp(i,r[y])));
	}
	sort(all(evt));
	for (auto p:evt) {
		int id=p.se.fi,y=p.se.se;
		if (id<-q) {
			modify(y,1);
		} else {
			if (id>0) cur[id]+=query(y);
			else cur[-id]-=query(y);
		}
	}
	rep(i,1,q+1) if (vis[i]) {
		if (cur[i]) ret[i]++; else ret[i]+=2;
	}
	rep(i,1,q+1) printf("%d\n",ret[i]);
}