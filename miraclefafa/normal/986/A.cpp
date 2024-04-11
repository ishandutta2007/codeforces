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

const int N=101000,K=110;
int n,m,k,s,a[N],dis[N][K],q[N],x,y;
VI v[N],e[N];
int main() {
	scanf("%d%d%d%d",&n,&m,&k,&s);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		v[a[i]].pb(i);
	}
	rep(i,0,m) {
		scanf("%d%d",&x,&y);
		e[x].pb(y);
		e[y].pb(x);
	}
	rep(c,1,k+1) {
		int t=0;
		rep(i,1,n+1) dis[i][c]=n+1;
		for (auto u:v[c]) {
			q[t++]=u;
			dis[u][c]=0;
		}
		rep(i,0,t) {
			int u=q[i];
			for (auto v:e[u]) {
				if (dis[v][c]>dis[u][c]+1) {
					dis[v][c]=dis[u][c]+1;
					q[t++]=v;
				}
			}
		}
	}
	rep(i,1,n+1) {
		sort(dis[i]+1,dis[i]+k+1);
		int val=0;
		rep(j,1,s+1) val+=dis[i][j];
		printf("%d ",val);
	}
	puts("");
}