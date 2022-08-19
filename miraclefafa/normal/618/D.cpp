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

const int N=201000;
int n,x,y,u,v,ans;
VI e[N];
int dfs(int u,int p) {
	int c=0;
	for (auto v:e[u]) {
		if (v==p) continue;
		c+=dfs(v,u);
	}
	if (c>=2) { ans+=c-1; return 0;}
	else return 1;
}
int main() {
	scanf("%d%d%d",&n,&x,&y);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	ans=0;
	if (x>=y) {
		// wtf
		ans=n-1;
		rep(i,1,n+1) if (SZ(e[i])==n-1) ans=n-2;
	} else { ans+=dfs(u,0); --ans; }
//	printf("%d\n",ans);
	printf("%I64d\n",(ll)x*(n-1-ans)+(ll)y*ans);
}