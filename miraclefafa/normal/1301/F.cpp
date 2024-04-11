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

const int N=1010,M=2010000;
const int inf=1<<30;
int dis[41][N][N];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,k,a[N][N],d[M],q[M],vis[M];
vector<PII> col[44];
int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,n) rep(j,0,m) {
		scanf("%d",&a[i][j]);
		--a[i][j];
		col[a[i][j]].pb(mp(i,j));
	}
	rep(c,0,k) {
		rep(i,0,n*m+k) d[i]=inf;
		rep(i,0,n*m+k) vis[i]=0;
		d[n*m+c]=0;
		int h,t;
		h=t=n*m+k;
		q[t++]=n*m+c;
		while (h<t) {
			int u=q[h++];
			if (vis[u]==1) continue;
			vis[u]=1;
			if (u>=n*m) {
				for (auto p:col[u-n*m]) {
					int x=p.fi,y=p.se;
					if (d[x*m+y]>d[u]+1) {
						d[x*m+y]=d[u]+1;
						q[t++]=x*m+y;
					}
				}
			} else {
				int x=u/m,y=u%m;
				int v=a[x][y]+n*m;
				if (d[v]>d[u]) {
					d[v]=d[u];
					q[--h]=v;
				}
				rep(k,0,4) {
					int px=x+dx[k],py=y+dy[k];
					if (px>=0&&px<n&&py>=0&&py<m) {
						v=px*m+py;
						if (d[v]>d[u]+1) {
							d[v]=d[u]+1;
							q[t++]=v;
						}
					}
				}
			}
		}
		rep(i,0,n) rep(j,0,m) dis[c][i][j]=d[i*m+j];
		//rep(i,0,n) rep(j,0,m) printf("%d%c",dis[c][i][j]," \n"[j==m-1]);
		//puts("");
	}
	int q;
	scanf("%d",&q);
	rep(i,0,q) {
		int r1,c1,r2,c2;
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		int ans=abs(r1-r2)+abs(c1-c2);
		--r1; --c1; --r2; --c2;
		rep(c,0,k) ans=min(ans,dis[c][r1][c1]+dis[c][r2][c2]-1);
		printf("%d\n",ans);
	}
}