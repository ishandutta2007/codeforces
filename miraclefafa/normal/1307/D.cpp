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
int q[N],vis[N],d1[N],d2[N];
int n,m,k,spe[N],u,v;
VI e[N];
 
void bfs(int s,int *d) {
	rep(i,1,n+1) vis[i]=0,d[i]=n+1;
	int t=0;
	vis[s]=1; d[s]=0;
	q[t++]=s;
	rep(i,0,t) {
		int u=q[i];
		for (auto v:e[u]) if (d[v]>d[u]+1) {
			d[v]=d[u]+1;
			q[t++]=v;
		}
	}
}
 
int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,k) scanf("%d",spe+i);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	bfs(1,d1);
	bfs(n,d2);
	sort(spe,spe+k,[&](int a,int b) {
		return d1[a]-d2[a]<d1[b]-d2[b];
	});
	int ans=0;
	rep(i,1,k) {
		ans=max(ans,d1[spe[i-1]]+d2[spe[i]]+1);
		//assert(d1[spe[i-1]]+d2[spe[i]]+1<=d2[spe[i-1]]+d1[spe[i]]+1);
	}
	ans=min(ans,d1[n]);
	printf("%d\n",ans);
}