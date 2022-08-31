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

int n,m,u,v,col[N];
VI e[N],vec[10];
void dfs(int u) {
	for (auto v:e[u]) {
		if (col[v]==0) {
			col[v]=3-col[u];
			dfs(v);
		} else if (col[u]+col[v]!=3) {
			puts("-1");
			exit(0);
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	rep(i,1,n+1) if (col[i]==0) {
		col[i]=1;
		dfs(i);
	}
	rep(i,1,n+1) vec[col[i]].pb(i);
	printf("%d\n",SZ(vec[1]));
	for (auto p:vec[1]) printf("%d ",p);
	puts("");
	printf("%d\n",SZ(vec[2]));
	for (auto p:vec[2]) printf("%d ",p);
	puts("");
}