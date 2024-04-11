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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
vector<PII> e[N];
VI ee[N];
int col[N],ind[N],rk[N],tt,n,m,op[N],u[N],v[N];
VI vv;

void dfs(int u) {
	vv.pb(u);
	for (auto x:e[u]) {
		int v=x.fi;
		if (col[v]==0) {
			col[v]=3-col[u];
			dfs(v);
		} else if (col[v]!=3-col[u]) {
			puts("NO");
			exit(0);
		}
	}
}
bool gao() {
// 1 L 2 R
	for (auto x:vv) {
		ee[x].clear();
		ind[x]=0;
	}
	auto add=[&](int a,int b) {
		ee[a].pb(b);
		ind[b]++;
	};
	for (auto x:vv) for (auto xx:e[x]) {
		int y=xx.fi;
		if (col[x]==1&&col[y]==2) {
			if (xx.se==1) add(x,y); else add(y,x);
		}
	}
	queue<int> q;
	for (auto x:vv) {
		if (ind[x]==0) q.push(x);
	}
	rep(i,0,SZ(vv)) {
		if (q.empty()) return 0;
		int u=q.front(); q.pop();
		rk[u]=tt+1+i;
		for (auto v:ee[u]) {
			--ind[v];
			if (ind[v]==0) q.push(v);
		}
	}
	return 1;
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d%d",op+i,u+i,v+i);
		e[u[i]].pb({v[i],op[i]});
		e[v[i]].pb({u[i],op[i]});
	}
	rep(i,1,n+1) if (col[i]==0) {
		vv.clear();
		col[i]=1;
		dfs(i);
		if (!gao()) {
			for (auto x:vv) col[x]=3-col[x];
			if (!gao()) {
				puts("NO");
				exit(0);
			}
		}
		tt+=SZ(vv);
	}
	puts("YES");
	rep(i,1,n+1) printf("%c %d\n"," LR"[col[i]],rk[i]);
}