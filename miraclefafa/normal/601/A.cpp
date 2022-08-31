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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

#include <queue>
const int N=410;
deque<pair<int,PII> > q;
int dis[N][N][2],vis[N][N][2];
int n,m,u,v,g[N][N],f[N][N];;
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	g[n][n]=1;
	rep(i,1,n+1) rep(j,1,n+1) if (g[i][j]==0&&i!=j) f[i][j]=1; f[n][n]=1;
	memset(dis,0x20,sizeof(dis));
	dis[1][1][0]=0;
	q.push_back(mp(1,mp(1,0)));
	while (!q.empty()) {
		int u=q.front().fi,v=q.front().se.fi,dir=q.front().se.se;
		q.pop_front();
		if (vis[u][v][dir]) continue;
		vis[u][v][dir]=1;
	//	printf("%d %d %d %d\n",u,v,dir,dis[u][v][dir]);
		if (dir==0) {
			rep(w,1,n+1) if (g[v][w]&&dis[u][w][1]>dis[u][v][0]+1) {
				dis[u][w][1]=dis[u][v][0]+1;
				q.push_back(mp(u,mp(w,1)));
			}
		} else {
			rep(w,1,n+1) if (f[u][w]&&(w==n||w!=u)&&dis[w][v][0]>dis[u][v][1]) {
				dis[w][v][0]=dis[u][v][1];
				q.push_front(mp(w,mp(v,0)));
			}
		}
	}
	int r=min(dis[n][n][0],dis[n][n][1]);
	if (r>=10000000) puts("-1"); else printf("%d\n",r);
}