#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
vector<PII> frac;
int deg[N],req[N],vis[N],q[N];
VI blk,ret,e[N];
int u,v,x,n,m,k;

bool cmp(PII a,PII b) {
	return 1ll*a.fi*b.se<1ll*a.se*b.fi;
}
bool pmc(PII a,PII b) {
	return 1ll*a.fi*b.se==1ll*a.se*b.fi;
}
bool check(PII fr) {
	
	rep(i,1,n+1) deg[i]=SZ(e[i]);
	rep(i,1,n+1) req[i]=(1ll*deg[i]*fr.fi+fr.se-1)/fr.se;
	rep(i,1,n+1) vis[i]=0;
	int t=0;
	rep(i,0,k) vis[q[t++]=blk[i]]=1;
	rep(i,0,t) {
		u=q[i];
		for (auto v:e[u]) {
			--deg[v];
			if (deg[v]<req[v]&&!vis[v]) {
				vis[v]=1; q[t++]=v;
			} 
		}
	}
	return t<n;
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,k) {
		scanf("%d",&x);
		blk.pb(x);
	}
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	rep(i,1,n+1) if (SZ(e[i])) {
		rep(j,0,SZ(e[i])+1) {
			frac.pb(mp(j,SZ(e[i])));
		}
	}
	sort(all(frac),cmp); 
	frac.erase(unique(all(frac),pmc),frac.end());
	int l=0,r=SZ(frac);
	while (l+1<r) {
		int md=(l+r)>>1;
		if (check(frac[md])) l=md; else r=md;
	}
	check(frac[l]);
	rep(i,1,n+1) if (!vis[i]) ret.pb(i);
	printf("%d\n",SZ(ret));
	for (auto v:ret) printf("%d ",v);
}