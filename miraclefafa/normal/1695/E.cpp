#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=601000;
vector<VI> ans;
VI cyc;
int n,f[N],se[N],x[N],y[N];
vector<PII> e[N];
int vis[N],vise[N];
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
int tot;
void dfs(int u,int pe) {
	vis[u]=++tot;
	cyc.pb(u);
	for (auto [v,id]:e[u]) {
		if (id==pe) continue;
		if (vis[v]) {
			if (vis[v]<=vis[u]) {
				cyc.pb(v);
				cyc.pb(u);
			}
		} else {
			dfs(v,id);
			cyc.pb(u);
		}
	}
}


int main() {
	scanf("%d",&n);
	rep(i,1,2*n+1) f[i]=i;
	rep(i,0,n) {
		scanf("%d%d",x+i,y+i);
		f[find(x[i])]=find(y[i]);
		e[x[i]].pb(mp(y[i],i));
		if (x[i]!=y[i]) e[y[i]].pb(mp(x[i],i));
	}
	rep(i,0,n) {
		se[find(x[i])]++;
	}
	rep(i,1,2*n+1) if (se[i]==1) {
		puts("-1");
		return 0;
	}
	rep(i,1,2*n+1) if (!vis[i]) {
		cyc.clear();
		dfs(i,-1);
		cyc.pop_back();
		//printf("ooo %d %d\n",SZ(cyc),se[find(i)]);
		assert(SZ(cyc)==2*se[find(i)]);
		ans.pb(cyc);
	}
	VI r1,r2;
	string c1,c2,c3,c4;
	printf("%d %d\n",2,n);
	for (auto x:ans) {
		int m=SZ(x);
		rep(i,0,m/2) {
			r1.pb(x[i]);
			if (i%2==0) {
				if (i!=m/2-1) {
					c1.pb('L');
					c2.pb('L');
				} else {
					c1.pb('U');
					c2.pb('D');
				}
				if (i==0) {
					c3.pb('U');
					c4.pb('D');
				} else {
					c3.pb('R');
					c4.pb('R');
				}
			} else {
				c1.pb('R');
				c2.pb('R');
				if (i!=m/2-1) {
					c3.pb('L');
					c4.pb('L');
				} else {
					c3.pb('U');
					c4.pb('D');
				}
			}
		}
		per(i,m/2,m) {
			r2.pb(x[i]);
		}
	}
	for (auto x:r1) printf("%d ",x); puts("");
	for (auto x:r2) printf("%d ",x); puts("");
	puts(c1.c_str());
	puts(c2.c_str());
	puts(c3.c_str());
	puts(c4.c_str());
}