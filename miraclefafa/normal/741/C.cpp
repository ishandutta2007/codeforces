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

const int N=201000;
int n,u,v,lab[N],vis[N];
PII f[N];
VI e[N];
void dfs(int u,int d) {
	lab[u]=d; vis[u]=1;
	for (auto v:e[u]) {
		if (vis[v]) continue;
		dfs(v,d^1);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d%d",&u,&v);
		f[i]=mp(u,v);
		e[u].pb(v);
		e[v].pb(u);
	}
	rep(i,1,n+1) {
		e[2*i-1].pb(2*i);
		e[2*i].pb(2*i-1);
	}
	rep(i,1,2*n+1) if (!vis[i]) dfs(i,0);
	rep(i,1,n+1) printf("%d %d\n",lab[f[i].fi]+1,lab[f[i].se]+1);
}