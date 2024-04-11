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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=401000;
char dir[]="UDLR";
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int totl,totr;
vector<string> g;
VI son[N];
int ty[N],mate[N],par[N],l[N],r[N],rp[N],vis[N];
int n,m,o;
char s[N];
vector<PII> eadd[N],erem[N];

void dfs(int u,int &tot) {
	if (u>=n*m) l[u]=tot+1; else l[u]=++tot;
	for (auto x:son[u]) dfs(x,tot);
	r[u]=tot;
}

struct node {
	int mv,cnt;
	int fg;
}nd[4*N];
void upd(int p) {
	nd[p].mv=min(nd[p+p].mv,nd[p+p+1].mv);
	nd[p].cnt=0;
	rep(i,0,2) if (nd[p+p+i].mv==nd[p].mv) nd[p].cnt+=nd[p+p+i].cnt;
}
void setf(int p,int v) {
	nd[p].fg+=v;
	nd[p].mv+=v;
}
void build(int p,int l,int r) {
	nd[p].fg=0;
	if (l==r) {
		nd[p].cnt=1;
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}
void push(int p) {
	if (nd[p].fg) {
		setf(p+p,nd[p].fg);
		setf(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
}

void modify(int p,int l,int r,int tl,int tr,int v) {
	if (tl>tr) return;
	if (tl==l&&tr==r) return setf(p,v);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,v);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,v);
		else modify(p+p,l,md,tl,md,v),modify(p+p+1,md+1,r,md+1,tr,v);
		upd(p);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%s",s);
		g.pb(string(s,s+m));
	}
	rep(i,0,n) rep(j,0,m) {
		int id=i*m+j;
		par[id]=-1;
		ty[id]=(i+j)%2;
		rp[id]=id;
		rep(k,0,4) if (g[i][j]==dir[k]) {
			int px=i+2*dx[k],py=j+2*dy[k];
			mate[id]=(i+dx[k])*m+j+dy[k];
			if (px>=0&&px<n&&py>=0&&py<m) {
				par[i*m+j]=px*m+py;
			}
		}
	}
	int z=n*m;
	rep(i,0,n*m) if (!vis[i]) {
		++o;
		int u=i;
		while (u!=-1&&vis[u]==0) {
			vis[u]=o;
			u=par[u];
		}
		if (u==-1||vis[u]!=o) continue;
		int v=u;
		par[z]=-1; ty[z]=(i/m+i%m)%2;
		while (1) {
			rp[v]=z;
			par[v]=z;
			v=par[v];
			if (v==u) break;
		}
		z++;
	}
	rep(i,0,z) if (par[i]==-1) par[i]=z+ty[i];
	z+=2;
	rep(i,0,z-2) {
		//printf("par[%d]=%d\n",i,par[i]);
		son[par[i]].pb(i);
	}
	dfs(z-2,totl);
	dfs(z-1,totr);
	//printf("oo %d %d\n",totl,totr);
	rep(i,0,n*m) if (ty[i]==0) {
		//printf("rec %d %d %d %d\n",l[rp[i]],r[rp[i]],l[rp[mate[i]]],r[rp[mate[i]]]);
		eadd[l[rp[i]]].pb({l[rp[mate[i]]],r[rp[mate[i]]]});
		erem[r[rp[i]]].pb({l[rp[mate[i]]],r[rp[mate[i]]]});
	}
	build(1,1,totr);
	ll ans=0;
	rep(i,1,totl+1) {
		for (auto p:eadd[i]) modify(1,1,totr,p.fi,p.se,1);
		if (nd[1].mv==0) ans+=totr-nd[1].cnt; else ans+=totr;
		//printf("%d %lld\n",i,ans);
		for (auto p:erem[i]) modify(1,1,totr,p.fi,p.se,-1);
		//printf("zz %d %d\n",nd[1].mv,nd[1].cnt);
	}
	printf("%lld\n",ans);
}