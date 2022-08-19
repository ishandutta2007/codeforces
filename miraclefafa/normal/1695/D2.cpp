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

const int N=201000;
VI e[N];
int dp[N],n,_;
void dfs(int u,int f) {
	dp[u]=0;
	int sdp=0,s0=0;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
		if (dp[v]>0) sdp+=dp[v];
		else s0++;
	}
	dp[u]=sdp+max(s0-1,0);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,1,n+1) e[i].clear();
		rep(i,1,n) {
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].pb(v);
			e[v].pb(u);
		}
		if (n<=2) {
			printf("%d\n",n-1);
			continue;
		}
		int r=-1;
		rep(i,1,n+1) if (SZ(e[i])>=3) r=i;
		if (r==-1) {
			puts("1");
			continue;
		}
		dfs(r,0);
		printf("%d\n",dp[r]);
	}
}