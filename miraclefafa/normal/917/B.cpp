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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=110;
char dp[N][N][28][2];
int n,m,u,v;
char s[10];
vector<PII> e[N];
bool dfs(int u,int v,int k,int op) {
	if (dp[u][v][k][op]!=0x11) return dp[u][v][k][op];
	if (op==0) {
		bool win=0;
		for (auto p:e[u]) if (p.se>=k) {
			win|=dfs(p.fi,v,p.se,op^1);
			if (win==1) break;
		}
		return dp[u][v][k][op]=win;
	} else {
		bool win=1;
		for (auto p:e[v]) if (p.se>=k) {
			win&=dfs(u,p.fi,p.se,op^1);
			if (win==0) break;
		}
		return dp[u][v][k][op]=win;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d%s",&u,&v,s); --u; --v;
		e[u].pb(mp(v,s[0]-'a'+1));
	}
	memset(dp,0x11,sizeof(dp));
	rep(i,0,n) {
		rep(j,0,n) if (dfs(i,j,0,0)) putchar('A'); else putchar('B');
		puts("");
	}
}