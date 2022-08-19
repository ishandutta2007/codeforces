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
int n,p,sz[N],cnt[N];
VI e[N];
void dfs(int u) {
	bool lv=1;
	for (auto v:e[u]) {
		lv=0;
		dfs(v);
		sz[u]+=sz[v];
	}
	sz[u]+=lv;
	cnt[sz[u]]++;
}
int main() {
	scanf("%d",&n);
	rep(i,2,n+1) {
		scanf("%d",&p);
		e[p].pb(i);
	}
	dfs(1);
	for (int i=1;i<=n;i++) {
		for (int j=0;j<cnt[i];j++) printf("%d ",i);
	}
	puts("");
}