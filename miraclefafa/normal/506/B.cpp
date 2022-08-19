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
int n,m,a,b,t;
int d[N],q[N],vis[N];
VI e[N],E[N],vec;
void dfs(int u) {
	vis[u]=1; vec.pb(u);
	rep(j,0,SZ(E[u])) {
		int v=E[u][j];
		if (vis[v]==0) dfs(v);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&a,&b);
		e[a].pb(b); d[b]++;
		E[a].pb(b); E[b].pb(a);
	}
	int ret=n;
	rep(i,1,n+1) if (!vis[i]) {
		vec.clear();
		dfs(i); t=0;
		rep(j,0,SZ(vec)) if (d[vec[j]]==0) {
			q[t++]=vec[j];
		}
		rep(j,0,t) {
			int p=q[j];
			rep(k,0,SZ(e[p])) {
				int Q=e[p][k];
				if ((--d[Q])==0) q[t++]=Q;
			}
		}
		if (t==SZ(vec)) --ret;
	}
	printf("%d\n",ret);
}