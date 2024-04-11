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

const int N=1100000;
VI e[N];
int n,m,_,cnt,dfn[N],low[N],st[N],bel[N],top,ind;
bool ins[N];
void init() {
	cnt=0;top=0;ind=0;
	rep(i,0,n) e[i].clear();
}  
void add(int u,int v) { e[u].pb(v);}
void tarjan(int u) {
	dfn[u]=low[u]=++ind;
	ins[u]=1;
	st[++top]=u;
	rep(i,0,SZ(e[u])) {
		int v=e[u][i];
		if (!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if (ins[v]) low[u]=min(low[u],low[v]);
	} 
	if (dfn[u]==low[u]) {
		++cnt;
		while (1) {
			bel[st[top]]=cnt;
			ins[st[top]]=0;
			if (st[top--]==u) break;
		}
	}
}
void solve() {
	scanf("%d%d",&n,&m);
	cnt=0;
	init();
	rep(i,0,m) {
		int u,v;
		scanf("%d%d",&u,&v);
		if (u==v) continue;
		--u; --v;
		e[u].pb(v);
	}
	rep(i,0,n) dfn[i]=0;
	rep(i,0,n) if (!dfn[i]) tarjan(i);
	if (cnt==1) {
		puts("No");
	} else {
		puts("Yes");
		int c2=0;
		rep(i,0,n) if (bel[i]>1) c2++;
		printf("%d %d\n",n-c2,c2);
		rep(i,0,n) if (bel[i]==1) printf("%d ",i+1); puts("");
		rep(i,0,n) if (bel[i]>1) printf("%d ",i+1); puts("");
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}