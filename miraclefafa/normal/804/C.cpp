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

const int N=301000;
int n,m,k,ret,x,c[N],u,v;
VI col[N],e[N];
void dfs(int u,int f) {
	set<int> cc;
	for (auto v:col[u]) {
		if (c[v]!=0) cc.insert(c[v]);
	}
	int cl=1;
	while (cc.count(cl)) cl++;
	for (auto v:col[u]) {
		if (c[v]==0) {
			c[v]=cl; cc.insert(c[v]);
			while (cc.count(cl)) cl++;
		}
	}
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)  {
		scanf("%d",&k);
		ret=max(ret,k);
		rep(j,0,k) {
			scanf("%d",&x);
			col[i].pb(x);
		}
	}
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0);
	if (ret==0) ret=1;
	printf("%d\n",ret);
	rep(i,1,m+1) if (c[i]==0) c[i]=1;
	rep(i,1,m+1) printf("%d ",c[i]);

}