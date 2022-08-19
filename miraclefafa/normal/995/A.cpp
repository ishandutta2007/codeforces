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

const int N=1010;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
PII q[N];
int vis[5][N],car[5][N],n;
PII pre[5][N];
vector<VI> ret;
void getpath(int x,int y) {
	rep(i,0,4) rep(j,0,n) vis[i][j]=0,pre[i][j]=mp(-1,-1);
	int t=0;
	q[t++]=mp(x,y);
	vis[x][y]=1;
	rep(i,0,t) {
		int px=q[i].fi,py=q[i].se;
		if (car[px][py]==0) {
			while (1) {
				int qx=pre[px][py].fi,qy=pre[px][py].se;
				if (qx==-1&&qy==-1) break;
				assert(car[qx][qy]>0);
				ret.pb(VI{car[qx][qy],px,py});
				car[px][py]=car[qx][qy];
				car[qx][qy]=0;
				px=qx; py=qy;
			}
			return;
		}
		rep(k,0,4) {
			int qx=px+dx[k],qy=py+dy[k];
			if (qx>=1&&qx<=2&&qy>=0&&qy<n&&car[qx][qy]!=-1&&!vis[qx][qy]) {
				pre[qx][qy]=mp(px,py);
				vis[qx][qy]=1;
				q[t++]=mp(qx,qy);
			}
		}
	}
}
void go(int x,int y,int c) {
	int posx=-1,posy=-1;
	rep(i,1,3) rep(j,0,n) if (car[i][j]==c) {
		posx=i; posy=j;
		break;
	}
	int goalx=x^1,goaly=y;
	while (posx!=goalx||posy!=goaly) {
		int nxtx=-1,nxty=-1;
		rep(i,0,4) {
			int curx=posx+dx[i],cury=posy+dy[i];
			if (abs(curx-goalx)+abs(cury-goaly)<abs(posx-goalx)+abs(posy-goaly)) {
				nxtx=curx,nxty=cury;
				break;
			}
		}
		car[posx][posy]=-1;
		getpath(nxtx,nxty);
		ret.pb(VI{c,nxtx,nxty});
		car[posx][posy]=0;
		car[nxtx][nxty]=c;
		posx=nxtx; posy=nxty;
	}
	ret.pb(VI{c,goalx^1,goaly});
	car[goalx][goaly]=car[goalx^1][goaly]=0;
}
int main() {
	scanf("%d%*d",&n);
	rep(i,0,4) rep(j,0,n) scanf("%d",&car[i][j]);
	rep(j,0,n) {
		if (car[0][j]==car[1][j]&&car[0][j]!=0) {
			ret.pb(VI{car[1][j],0,j});
			car[0][j]=car[1][j]=0;
		}
		if (car[2][j]==car[3][j]&&car[2][j]!=0) {
			ret.pb(VI{car[2][j],3,j});
			car[2][j]=car[3][j]=0;
		}
	}
	bool empty=0;
	rep(j,0,n) if (car[1][j]==0||car[2][j]==0) empty=1;
	if (!empty) {
		puts("-1");
		return 0;
	}
	rep(j,0,n) {
		if (car[0][j]) go(0,j,car[0][j]);
		if (car[3][j]) go(3,j,car[3][j]);
	}
	printf("%d\n",SZ(ret));
	for (auto p:ret) {
		printf("%d %d %d\n",p[0],p[1]+1,p[2]+1);
	}
}