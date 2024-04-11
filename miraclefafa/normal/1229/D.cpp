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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
 
const int N=201000,M=130;
int n,k,p[M],m,g[M][M],perm[M][M],pos[N];
int q[M];
bool vis[M];
PII nxt[M];
int id[N];
ll ans;
 
map<ll,vector<bool>> add[M];
 
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,k) p[i]=i;
	m=0;
	memset(id,-1,sizeof(id));
	while (1) {
		rep(i,0,k) perm[m][i]=p[i];
		int val=0;
		rep(i,0,k) val=val*k+p[i];
		id[val]=m;
		++m;
		if (!next_permutation(p,p+k)) break;
	}
	rep(i,0,m) rep(j,0,m) {
		int val=0;
		rep(l,0,k) val=val*k+perm[j][perm[i][l]];
		assert(id[val]!=-1);
		g[i][j]=id[val];
		//printf("tab %d %d %d\n",i,j,g[i][j]);
	}
	rep(i,0,n) {
		int val=0;
		rep(j,0,k) {
			scanf("%d",&p[j]),--p[j];
			val=val*k+p[j];
		}
		pos[i]=id[val];
	}
	rep(i,0,m) nxt[i]=mp(i,n);
	per(i,0,n) {
		bool fd=0;
//		printf("gg %d %d %d\n",m,i,pos[i]);
		per(j,1,m) {
			if (nxt[j].fi==pos[i]) fd=1;
			if (fd) swap(nxt[j-1],nxt[j]);
		}
		assert(nxt[0].fi==pos[i]);
		nxt[0].se=i;
		rep(j,0,m) vis[j]=0;
		int t=0;
		q[t++]=0; vis[0]=1;
		vector<PII> v;
		v.pb(mp(1,i));
		rep(j,0,m) {
			int p=nxt[j].fi;
			if (vis[p]) continue;
			ll s=0;
			rep(i,0,m) s=s*13331+vis[i];
			if (add[p].count(s)) {
				auto vv=add[p][s];
				t=0;
				rep(i,0,m) {
					vis[i]=vv[i];
					if (vis[i]) q[t++]=i;
				}
			} else {
				int pt=t;
				q[t++]=p; vis[p]=1;
				rep(i,0,t) {
					auto add=[&](int x) {
						if (vis[x]) return;
						vis[x]=1; q[t++]=x;
					};
					rep(j,pt,t) {
						add(g[q[i]][q[j]]);
						add(g[q[j]][q[i]]);
					}
				}
				add[p][s]=vector<bool>(vis,vis+m);
			}
			v.pb(mp(t,nxt[j].se));
			//printf("%d -> %d : %d\n",i,nxt[j].se,t);
		}
		rep(i,0,SZ(v)) ans+=v[i].fi*((i==SZ(v)-1?n:v[i+1].se)-v[i].se);
	}
	printf("%lld\n",ans);
}