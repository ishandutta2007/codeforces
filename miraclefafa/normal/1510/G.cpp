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

const int N=110;
int n,k,_,mark[N],p[N],dep[N];
VI s[N],od;
void dfs(int u) {
	od.pb(u);
	if (mark[u]==1) {
		for (auto v:s[u]) if (mark[v]==1) {
			dfs(v);
			od.pb(u);
		}
	}
	for (auto v:s[u]) if (mark[v]==0) {
		dfs(v);
		od.pb(u);
	}
}

void solve() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) s[i].clear(),mark[i]=0;
	int mx=0,mxv=1;
	rep(i,2,n+1) {
		scanf("%d",p+i),s[p[i]].pb(i);
		dep[i]=dep[p[i]]+1;
		if (dep[i]>mx) mx=dep[i],mxv=i;
	}
	int v=mxv;
	VI pt;
	while (v) {
		pt.pb(v);
		mark[v]=1;
		v=p[v];
	}
	reverse(all(pt));
	//printf("Ss %d\n",SZ(pt));
	if (SZ(pt)>=k) {
		printf("%d\n",k-1);
		rep(i,0,k) printf("%d ",pt[i]);
		puts("");
		return;
	}
	printf("%d\n",2*k-2-mx);
	int del=n-k;
	od.clear();
	per(i,1,n+1) if (del&&mark[i]==0) {
		mark[i]=2; --del;
	}
	dfs(1);
	od.erase(od.begin(),od.begin()+mx);
	reverse(all(od));

	for (auto x:od) printf("%d ",x);
	puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}