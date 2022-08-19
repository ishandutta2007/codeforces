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

const int N=101000;
int p[N][20],u,v,dep[N],n;
VI e[N];
ll val[N][20],vv[N],ans;

void dfs(int u,int f) {
	p[u][0]=f; val[u][0]=vv[u];
	dep[u]=dep[f]+1;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%lld",vv+i);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	rep(j,0,18) val[0][j]=1;
	rep(j,1,18) {
		rep(i,1,n+1) {
			p[i][j]=p[p[i][j-1]][j-1];
			val[i][j]=gcd(val[i][j-1],val[p[i][j-1]][j-1]);
		}
	}
	rep(i,1,n+1) {
		ll x=vv[i];
		int u=i;
		while (u) {
			int v=u;
			ll d=x;
			per(j,0,18) {
				if (dep[v]>=(1<<j)&&((d==0&&val[v][j]==0)||(d!=0&&val[v][j]%d==0)))
					v=p[v][j];
			}
			ans=(ans+d%mod*(dep[u]-dep[v])%mod)%mod;
			u=v;
			x=gcd(d,vv[u]);
		}
	}
	printf("%lld\n",ans);
}