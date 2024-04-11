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

const int N=101000;
const int LIM=500;
int q[N],hs[N],hv[N],dep[N],id[N],l[N],r[N],bel[N],f[N],s[N],t[N],off[N],fg[N];

int n,p,tot,ans,v,m,in[N];
VI cc[N],e[N];
vector<PII>::iterator pit[N];
vector<PII> zz[N],st[N];
PII tmp[N];
void dfs(int u,int f) {
	id[l[u]=++tot]=u;
	dep[u]=dep[f]+1;
	if (hv[u]) dfs(hv[u],u);
	rep(j,0,SZ(e[u])) if (e[u][j]!=f&&e[u][j]!=hv[u])
		dfs(e[u][j],u);
	r[u]=tot;
}

void build(int u) {
	for (auto v:cc[u]) st[u].pb(mp(t[v],v));
	sort(all(st[u]));
	int cnt=1;
	rep(i,1,SZ(st[u])) {
		if (st[u][i].fi!=st[u][i-1].fi) zz[u].pb(mp(st[u][i-1].fi,cnt)),cnt=0;
		cnt++;
	}
	zz[u].pb(mp(st[u].back().fi,cnt));
	pit[u]=zz[u].begin();
}

void rebuild(int u) {
	int t1=0;
	for (auto p:st[u]) if (!fg[p.se]) tmp[t1++]=mp(t[p.se]+=off[u],p.se);
	int t2=t1;
	for (auto p:st[u]) if (fg[p.se]) tmp[t2++]=mp(t[p.se]+=off[u],p.se);
	inplace_merge(tmp,tmp+t1,tmp+t2);
	st[u]=vector<PII>(tmp,tmp+t2);
	for (auto p:zz[u]) if (p.fi+off[u]<0) ans-=p.se;
	off[u]=0;
	zz[u].clear();
	int cnt=in[st[u][0].se];
	rep(i,1,SZ(st[u])) {
		if (st[u][i].fi!=st[u][i-1].fi) zz[u].pb(mp(st[u][i-1].fi,cnt)),cnt=0;
		cnt+=in[st[u][i].se];
	}
	zz[u].pb(mp(st[u].back().fi,cnt));
	pit[u]=zz[u].begin();
	while (pit[u]!=zz[u].end()&&pit[u]->fi<0) ++pit[u];
	for (auto p:zz[u]) if (p.fi<0) ans+=p.se;
	for (auto v:cc[u]) fg[v]=0;
}

bool rrt[N];
void HLDoT(int rt) {
	int t=1;
	q[0]=rt;
	rep(i,0,n) {
		int u=q[i];
		rep(j,0,SZ(e[u])) if (e[u][j]!=f[u])
			f[e[u][j]]=u,dep[q[t++]=e[u][j]]=dep[u]+1;
	}
	per(i,0,n) {
		int u=q[i],p=f[u];
		s[u]++,s[p]+=s[u];
		if (!l[u]) l[u]=1;
		if (hs[p]<s[u]) hs[p]=s[u],hv[p]=u,l[p]=l[u]+1;
	}
	rep(i,0,n) {
		int u=q[i];
		if (!bel[u]) bel[u]=u;
		if (hv[u]) bel[hv[u]]=bel[u];
	}
	dfs(rt,0);
	rep(i,1,n+1) if (bel[i]==i) rrt[i]=1;
	rep(i,1,n+1) if (rrt[i]) {
		int u=i;
		VI chain;
		chain.pb(u);
		while (hv[u]) {
			u=hv[u];
			chain.pb(u);
		}
		int curf=chain[0];
		rep(i,0,SZ(chain)) {
			if (i%LIM==0) curf=chain[i];
			bel[chain[i]]=curf;
			cc[curf].pb(chain[i]);
		}
	}
	rep(i,1,n+1) if (bel[i]==i) build(i);
}


void modify(int u,int x) {
	in[u]+=x;
	if (t[u]+off[bel[u]]<0) ans+=x;
	for (auto &p:zz[bel[u]]) if (p.fi==t[u]) p.se+=x;
	u=f[u];
	while (u) {
		int v=bel[u];
		if (cc[v].back()==u) {
			off[v]+=x;
			while (pit[v]!=zz[v].end()&&pit[v]->fi+off[v]<0) {
				ans+=pit[v]->se;
				pit[v]++;
			}	
			while (pit[v]!=zz[v].begin()&&(pit[v]-1)->fi+off[v]>=0) {
				ans-=(pit[v]-1)->se;
				pit[v]--;
			}
		} else {
			while (1) {
				t[u]+=x; fg[u]=1;
				if (u==v) break;
				u=f[u];
			}
			rebuild(v);
		}
		u=f[v];
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) in[i]=1;
	rep(i,2,n+1) {
		scanf("%d",&p);
		e[p].pb(i);
	}
	rep(i,1,n+1) scanf("%d",t+i);
	HLDoT(1);
	rep(i,0,m) {
		scanf("%d",&v);
		if (v>0) modify(v,-1);
		else modify(-v,1);
		printf("%d%c",ans," \n"[i==m-1]);
	}
}