#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

const int N=101000;
vector<pair<int,ll> > e[N];
int ret,vis[N],n,m,u,v;
ll dep[N],w,pw[210];
struct guass {
	int cnt[66][2],rk;
	ll cyc[66],s;
	void init() {
		rep(i,0,61) cyc[i]=cnt[i][0]=cnt[i][1]=0;
		rk=0; s=0;
	}
	void dda(ll w) {
		rep(i,0,61) cnt[i][(w>>i)&1]++;
	}
	void add(ll w) {
		s|=w;
		per(i,0,61) {
			if (w&(1ll<<i)) {
				if (cyc[i]==0) {
					cyc[i]=w,rk++;
					break;
				}
			}
			w=min(w,w^cyc[i]);
		}
	}
	void count() {
		rep(i,0,61) {
			if (s&(1ll<<i)) {
				ret=(ret+(ll)(cnt[i][0]+cnt[i][1])*(cnt[i][0]+cnt[i][1]-1)/2%mod*pw[i+rk-1])%mod;
			} else {
				ret=(ret+(ll)cnt[i][0]*cnt[i][1]%mod*pw[i+rk])%mod;
			}
		}
	}
}base;
void dfs(int u,int f,ll w) {
	vis[u]=1; dep[u]=w;
	base.dda(w);
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		if (vis[v]) {
			base.add(dep[u]^dep[v]^p.se);
			continue;
		}
		dfs(v,u,w^p.se);
	}
}
int main() {
	pw[0]=1;
	rep(i,1,201) pw[i]=pw[i-1]*2%mod;
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d%lld",&u,&v,&w);
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	rep(i,1,n+1) if (!vis[i]) {
		base.init();
		dfs(i,0,0);
		base.count();
	}
	printf("%d\n",ret);
}