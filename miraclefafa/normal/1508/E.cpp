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

const int N=301000;
int l1[N],l2[N],a[N],pos[N],dep[N],ve[N];
int cc,cnt2,lab,n;
VI e[N];
void dfs(int u) {
	sort(all(e[u]),[&](int p,int q) { return a[p]<a[q]; });
	for (auto v:e[u]) dfs(v);
	l2[u]=++cnt2;
}

void dfs2(int u) {
	if (l2[u]>lab) l1[u]=++cc; else l1[u]=-1;
	for (auto v:e[u]) dfs2(v);
}
void dfs3(int u) {
	ve[l1[u]=++cc]=u;

	for (auto v:e[u]) {
		//p[v][0]=u;
		dep[v]=dep[u]+1;
		dfs3(v);
	}
}



int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",a+i),pos[a[i]]=i;
	lab=n;
	rep(i,1,n) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		if (a[u]<a[v]) lab=min(lab,a[u]);
	}
	int cnt=0;
	while (1) {
		int u=pos[lab];
		int lb=n+1;
		for (auto v:e[u]) if (a[v]>lab) lb=min(lb,a[v]);
		//printf("zz %d %d\n",u,lb);
		if (lb<=n) {
			int v=pos[lb];
			swap(a[u],a[v]);
			pos[a[u]]=u;
			pos[a[v]]=v;
			cnt++;
		} else {
			break;
		}
	}
	//rep(i,1,n+1) printf("%d ",a[i]);
	dfs(1);
	//rep(i,1,n+1) printf("%d\n",l2[i]);
	rep(i,1,n+1) if (l2[i]<=lab&&l2[i]!=a[i]) {
		puts("NO");
		return 0;
	}
	cc=lab;
	dfs2(1);

	//rep(i,1,n+1) printf("%d\n",l1[i]);

	rep(i,1,n+1) if (l2[i]>lab&&l1[i]!=a[i]) {
		puts("NO");
		return 0;
	}
	cc=0;
	dfs3(1);
	ll r=0;
	rep(i,1,lab+1) {
		r+=dep[pos[i]];
	}
	puts("YES");
	r-=cnt;
	printf("%lld\n",r);
	rep(i,1,n+1) printf("%d ",l1[i]); puts("");
}