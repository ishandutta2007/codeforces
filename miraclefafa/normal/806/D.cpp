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

const int N=2010;
const ll inf=1ll<<60;
int n,g[N][N],ze[N],vis[N][4];
ll dis[N][4];

void upd(int u,int v,ll w) { if (w<dis[u][v]) dis[u][v]=w;}
int main() {
	scanf("%d",&n);
	ll mv=inf;
	rep(i,0,n) {
		rep(j,i+1,n) scanf("%d",&g[i][j]),g[j][i]=g[i][j],mv=min(mv,(ll)g[i][j]);
	}
	rep(i,0,n) rep(j,0,n) if (i!=j) g[i][j]-=mv;
	rep(i,0,n) rep(j,0,n) if (i!=j&&g[i][j]==0) ze[i]=ze[j]=1;
	rep(i,0,n) {
		dis[i][0]=ze[i]?0:inf;
		dis[i][1]=dis[i][2]=inf;
	}
	rep(rd,0,3*n) {
		ll mv=inf+1; PII v=mp(-1,-1);
		rep(i,0,n) rep(j,0,3) if (!vis[i][j]&&dis[i][j]<mv) mv=dis[i][j],v=mp(i,j);
		vis[v.fi][v.se]=1;
		if (v.se==0) {
			rep(j,0,n) if (j!=v.fi) upd(j,1,mv),upd(j,2,mv+g[v.fi][j]);
		} else if (v.se==1) {
			rep(j,0,n) if (j!=v.fi) upd(j,2,mv+2*g[v.fi][j]);
		} else {
			rep(j,0,n) if (j!=v.fi) upd(j,2,mv+g[v.fi][j]);			
		}
	}
	rep(i,0,n) dis[i][0]=min(dis[i][0],dis[i][2]);
	rep(i,0,n) printf("%lld\n",dis[i][0]+mv*(n-1));
}