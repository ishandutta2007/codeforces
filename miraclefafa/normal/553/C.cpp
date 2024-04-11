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
vector<PII> e[N];
int n,m,u,v,c,cnt1,cnt2,col[N],vis[N],cc;
void dfs(int u,int c) {
	if (vis[u]) return;
	col[u]=c; cc|=(1<<c); vis[u]=1;
	for (auto p:e[u]) {
		dfs(p.fi,c^p.se);
	}
} 
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&c); c^=1;
		e[u].pb(mp(v,c));
		e[v].pb(mp(u,c));
	}
	rep(i,1,n+1) if (!vis[i]) {
		cc=0;
		dfs(i,0);
		if (cc==3) cnt2++; else cnt1++;
	}
	rep(i,1,n+1) {
		for (auto p:e[i]) {
			int v=p.fi;
			if ((col[i]^col[v])!=p.se) {
				puts("0");
				return 0;
			}
		}
	}
	printf("%I64d\n",powmod(2,cnt1+cnt2-1));
}