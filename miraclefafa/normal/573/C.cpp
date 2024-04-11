#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

const int N=101000;
VI e[N],s[N];
bool dp[N][10];
int n,u,v;
void dfs(int u,int f) {
	s[u].clear();
	for (auto v:e[u]) if (v!=f) {
		s[u].pb(v);
		dfs(v,u);
	}
	rep(i,0,6) dp[u][i]=0;
	if (SZ(s[u])==0) dp[u][0]=1;
	if (dp[u][0]) dp[u][1]=1;
	else {
		if (SZ(s[u])==1&&dp[s[u][0]][1]) dp[u][1]=1;
	}
	if (dp[u][1]) dp[u][2]=1;
	else {
		if (SZ(s[u])==2&&dp[s[u][0]][1]&&dp[s[u][1]][1]) dp[u][2]=1;
	}
	if (dp[u][0]) dp[u][3]=1;
	else {
		dp[u][3]=1;
		for (auto v:s[u]) dp[u][3]&=dp[v][2];
	}
	if (dp[u][3]||dp[u][1]) dp[u][4]=1;
	else {
		int cnt=0;
		for (auto v:s[u]) if (!dp[v][2]) {
			if (!dp[v][4]) cnt+=100; else cnt+=1;
		}
		if (cnt<=1) dp[u][4]=1;
	}
	if (dp[u][4]||dp[u][2]) dp[u][5]=1;
	else {
		int cnt=0;
		for (auto v:s[u]) if (!dp[v][2]) {
			if (!dp[v][4]) cnt+=100; else cnt+=1;
		}
		if (cnt<=2) dp[u][5]=1;
	}
}int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	int root=0;
	rep(i,1,n+1) if (SZ(e[i])>=3) { root=i; break; }
	if (root==0) { puts("Yes"); return 0; }
	rep(rd,0,50) {
		dfs(root,0);
		if (dp[root][5]) { puts("Yes"); return 0; }
		VI v;
		rep(i,1,n+1) if (dp[i][4]==0) v.pb(i);
		assert(SZ(v)>=1);
		root=v[rand()%SZ(v)];
	}
	puts("No");
}