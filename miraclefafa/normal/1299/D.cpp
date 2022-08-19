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

#define bit(x) (1ll<<(x))

const int N=101000;
bool vis[N],br[N];
int val[N],wt[N];
ll ps,st[N];
map<pair<ll,ll>,ll> hs;
vector<PII> e[N];
int n,m,mm,a,b,w,mat[N],pe[N];
array<int,3> p[N];
VI pd;
void add(ll &s,int x) {
	if (s==-1) return;
	if (s&bit(x)) s=-1;
	ll t=s;
	rep(i,0,32) if (s&bit(i)) t|=bit(i^x);
	s=t;
}

ll merge(ll s,ll t) {
	if (s==-1||t==-1) return -1;
	if ((s&t)!=1) return -1;
	if (hs.count(mp(s,t))) return hs[mp(s,t)];
	ll ns=0;
	rep(i,0,32) if (s&bit(i)) rep(j,0,32) if (t&bit(j)) ns^=bit(i^j);
	return hs[mp(s,t)]=ns;
}

set<PII> ue;
void dfs(int u) {
	vis[u]=1;
	for (auto p:e[u]) {
		int v=p.fi;
		if (!vis[v]) {
			val[v]=val[u]^p.se;
			ue.insert(mp(u,v));
			dfs(v);
		} else {
			if (!ue.count(mp(u,v))&&!ue.count(mp(v,u)))
				add(ps,val[u]^val[v]^p.se);
			ue.insert(mp(u,v));
		}
	}
}

void upd(int &a,int b) {
	a+=b; if (a>=mod) a-=mod;
}

int mid[410][410],fst[N],dp[5][410],pp[5][410];
ll lab[410];
map<ll,int> gid;

int main() {

	set<ll> pst;
	pst.insert(1);
	rep(i,0,32) {
		set<ll> qst=pst;
		for (auto x:qst) {
			ll y=x;
			add(y,i);
			pst.insert(y);
		}
		//printf("%d %d\n",i,SZ(pst));
	}
	for (auto x:pst) {
		lab[m]=x;
		gid[x]=m;
		++m;
	}
	rep(i,0,m) rep(j,0,m) {
		ll z=merge(lab[i],lab[j]);
		assert(gid.count(z));
		mid[i][j]=gid[z];
	}

	scanf("%d%d",&n,&mm);
	rep(i,0,mm) {
		scanf("%d%d%d",&a,&b,&w);
		if (a>b) swap(a,b);
		p[i]={a,b,w};
		if (a==1) br[b]=1,wt[b]=w;
	}
	rep(i,0,mm) {
		a=p[i][0]; b=p[i][1]; w=p[i][2];
		if (a==1) continue;
		if (br[a]&&br[b]) {
			mat[a]=1; mat[b]=2;
			pe[b]=w^wt[a]^wt[b];
			pd.pb(a); pd.pb(b);
		} else {
			e[a].pb(mp(b,w));
			e[b].pb(mp(a,w));
		}
	}
	rep(i,1,n+1) if (br[i]&&!mat[i]) {
		pd.pb(i);
	}
	rep(i,0,SZ(pd)) {
		ps=1;
		dfs(pd[i]);
		st[i]=ps;
	}
	dp[0][1]=1;
	rep(i,0,SZ(pd)) {
		int u=pd[i];
		if (mat[u]==2) {
			st[i]=st[i-1]=merge(st[i],st[i-1]);
		}
	}

//printf("%d\n",m);
	rep(i,0,SZ(pd)) {
		fst[i]=gid[st[i]];
	//	printf("%d %d\n",i,fst[i]);
	}

	assert(gid[-1]==0);
	dp[0][gid[1]]=1;
	rep(i,0,SZ(pd)) {
		rep(j,0,2) rep(k,0,m) pp[j][k]=dp[j][k],dp[j][k]=0;
		int gd=gid[bit(0)|bit(pe[pd[i]])];
		rep(j,0,2) rep(k,0,m) if (pp[j][k]) {
			int ck=k;
			if (mat[pd[i]]!=2||j==0) ck=mid[ck][fst[i]];
			int dk=ck;
			if (mat[pd[i]]==2) {
				if (pe[pd[i]]==0) dk=0; else dk=mid[dk][gd];
			}
			//printf("%d %d %d\n",k,fst[i],ck);
			ll val=pp[j][k];
			rep(w,0,2) {
				if (w==1&&j==1) upd(dp[w][dk],val);
				else if (w==1) upd(dp[w][ck],val);
				else upd(dp[w][k],val);
			}
		}
	}
	int ans=0;
	rep(j,0,2) rep(k,1,m) upd(ans,dp[j][k]);
	printf("%d\n",ans);
}