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

const int M=1010000,N=101000;
int n,m;
VI dg[N];
VI e[M][10],q[M];
int vis[M],t;
ll dp[M];

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,m+1) {
		int x=i;
		while (x) dg[i].pb(x%10),x/=10;
		reverse(all(dg[i]));
	}
	int cc=n;
	rep(i,1,m+1) {
		int u,v;
		scanf("%d%d",&u,&v);
		auto add=[&](int u,int v,int id) {
			int pre=u;
			rep(i,0,SZ(dg[id])) {
				int np=(i==SZ(dg[id])-1)?v:++cc;
				e[pre][dg[id][i]].pb(np);
				pre=np;
			}
		};
		add(u,v,i);
		add(v,u,i);
	}
	q[t++].pb(1);
	dp[1]=0;
	vis[1]=1;
	rep(i,0,t) {
		rep(j,0,10) {
			bool ex=0;
			for (auto u:q[i]) for (auto v:e[u][j]) {
				if (!vis[v]) {
					vis[v]=1;
					ex=1;
					q[t].pb(v);
					dp[v]=(dp[u]*10+j)%mod;
				}
			}
			if (ex) t++;
		}
	}
	rep(i,2,n+1) printf("%lld\n",dp[i]);
}