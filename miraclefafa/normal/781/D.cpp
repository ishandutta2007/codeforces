#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
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

const int N=510;
bitset<N> g[2][70][N],p,q;
int n,m,t,u,v;
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&t);
		--u; --v;
		g[t][0][u][v]=1;
	}
	rep(k,1,62) {
		rep(u,0,n) rep(v,0,n) {
			if (g[0][k-1][u][v]) g[0][k][u]|=g[1][k-1][v];
			if (g[1][k-1][u][v]) g[1][k][u]|=g[0][k-1][v];
		}
	}
	rep(v,0,n) if (g[0][61][0][v]) {
		puts("-1");
		return 0;
	}
	bool val=0;
	ll r=0;
	p[0]=1;
	per(k,0,62) {
//		rep(u,0,n) p[u]=q[u],q[u]=0;
		rep(u,0,n) q[u]=0;
		rep(u,0,n) if (p[u]) q|=g[val][k][u];
		if (q.any()) {
			val^=1; r+=(1ll<<k); p=q;
		}
	}
	if (r>1000000000000000000ll) r=-1;
	printf("%lld\n",r);
}