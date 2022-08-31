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

const int N=201000;
VI e[N],son[N];
int n,u,v,k,col[N];
void dfs(int u,int f) {
	for (auto v:e[u]) if (v!=f) {
		son[u].pb(v);
	}
	int c=1;
	for (auto v:son[u]) {
		while (c==col[u]||c==col[f]) ++c;
		col[v]=c++;
	}
	for (auto v:son[u]) dfs(v,u);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	k=0;
	rep(i,1,n+1) k=max(k,SZ(e[i])+1);
	col[1]=1;
	dfs(1,0);
	printf("%d\n",k);
	rep(i,1,n+1) printf("%d ",col[i]); 
	puts("");
}