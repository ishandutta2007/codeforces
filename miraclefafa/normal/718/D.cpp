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
map<VI,int> pp,qq;
map<int,int> hs[N];
VI e[N];
int n,u,v,m;
int dfs(int u,int f) {
	if (hs[u].count(f)) return hs[u][f];
	VI s;
	for (auto v:e[u]) {
		if (v==f) continue;
		s.pb(dfs(v,u));
	}
	sort(all(s));
	if (SZ(s)==0) return hs[u][f]=0;
	else {
		int ret=0;
		if (pp.count(s)) ret=pp[s];
		else ret=(pp[s]=++m);
		return hs[u][f]=ret;
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	rep(i,1,n+1) {
		for (auto v:e[i]) dfs(v,i);
	}
	rep(i,1,n+1) if (SZ(e[i])<4) {
		VI s;
		for (auto v:e[i]) s.pb(dfs(v,i));
		sort(all(s));
		qq[s]=1;
	}
	printf("%d\n",SZ(qq));
}