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

const int N=2010;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
deque<PII> q;
int n,m,r,c,x,y;
int dis[N][N];
int ans;
bool vis[N][N];
char s[N][N];
int main() {
	scanf("%d%d",&n,&m);
	scanf("%d%d",&r,&c);
	--r; --c;
	scanf("%d%d",&x,&y);
	rep(i,0,n) scanf("%s",s[i]);
	memset(dis,0x20,sizeof(dis));
	dis[r][c]=0; q.push_back(mp(r,c));
	while (!q.empty()) {
		int x=q.front().fi,y=q.front().se;
		q.pop_front();
		if (vis[x][y]) continue;
		vis[x][y]=1;
		rep(k,0,4) {
			int nx=x+dx[k],ny=y+dy[k];
			if (nx>=0&&nx<n&&ny>=0&&ny<m&&s[nx][ny]=='.') {
				if (k==2) {
					if (dis[nx][ny]>dis[x][y]+1) {
						dis[nx][ny]=dis[x][y]+1;
						q.push_back(mp(nx,ny));
					}
				} else {
					if (dis[nx][ny]>dis[x][y]) {
						dis[nx][ny]=dis[x][y];
						q.push_front(mp(nx,ny));
					}
				}
			}
		}
	}
	rep(i,0,n) rep(j,0,m) {
		if (dis[i][j]>n*m) continue;
		int l=dis[i][j],r=j-(c-l);
		if (l<=x&&r<=y) ans++;
	}
	printf("%d\n",ans);
}