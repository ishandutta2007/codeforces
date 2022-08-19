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

int grid[666][666],tot;
int n,p[666666],vis[666666];
PII q[666666];
int main() {
	scanf("%d",&n);
	if (n<=2) {
		puts("-1");
		return 0;
	}
	q[0]=mp(1,1);
	q[1]=mp(1,2);
	q[2]=mp(2,2);
	q[3]=mp(2,0);
	q[4]=mp(1,0);
	q[5]=mp(0,2);
	q[6]=mp(0,1);
	q[7]=mp(0,0);
	q[8]=mp(2,1);

	if (n>3) {
		rep(j,0,n) {
			if (j%2==0) {
				rep(i,3,n) grid[i][j]=++tot;
			} else {
				per(i,3,n) grid[i][j]=++tot;
			}
		}
		grid[2][n-1]=++tot;
		per(i,3,n-1) grid[2][i]=++tot;
		grid[0][3]=++tot;
		rep(i,4,n) grid[0][i]=++tot;
		grid[1][n-1]=++tot;
		per(i,3,n-1) grid[1][i]=++tot;
	}
	rep(i,0,9) grid[q[i].fi][q[i].se]=++tot;
/*	grid[1][1]=++tot; grid[1][2]=++tot;
	grid[2][1]=++tot; grid[1][2]=++tot;
	grid[1][1]=++tot; grid[1][2]=++tot;
	grid[1][1]=++tot; grid[1][2]=++tot;

	per(i,)
	rep(i,)
	grid[]

	rep(i,0)



	rep(i,0,n*n) p[i]=i;
	while (1) {
		random_shuffle(p,p+n*n);
		rep(i,0,n*n) vis[i]=0;
		int x=0; vis[0]=1;
		int pQueen=0,pRook=0;
		rep(i,1,n*n) {
			int ff=0;
			rep(j,0,n*n) if (!vis[j]) {
				int a=p[x]/n,b=p[x]%n,c=p[j]/n,d=p[j]%n;
				if (a==c||b==d||a-b==c-d||a+b==c+d) {
					vis[j]=1; x=j;
					ff=1;
					break;
				}
			}
			if (!ff) {
				pQueen++;
				rep(j,0,n*n) if (!vis[j]) { vis[j]=1; x=j; break;}
			}
			printf("%d%c",x+1," *"[!ff]);
		}
		puts("");
		rep(i,0,n*n) vis[i]=0;
		x=0; vis[0]=1;
		rep(i,1,n*n) {
			int ff=0;
			rep(j,0,n*n) if (!vis[j]) {
				int a=p[x]/n,b=p[x]%n,c=p[j]/n,d=p[j]%n;
				if (a==c||b==d) {
					vis[j]=1; x=j;
					ff=1;
					break;
				}
			}
			if (!ff) {
				pRook++;
				rep(j,0,n*n) if (!vis[j]) { vis[j]=1; x=j; break;}
			}
			printf("%d ",x+1);
		}
		puts("");
		printf("%d %d\n",pRook,pQueen);
		if (pRook<pQueen) {
			rep(i,0,n*n) grid[p[i]/n][p[i]%n]=i+1;
			rep(i,0,n) rep(j,0,n) printf("%d%c",grid[i][j]," \n"[j==n-1]);
			puts("");
			rep(i,0,n*n) printf("q[%d]=mp(%d,%d);\n",i,p[i]/n,p[i]%n);
			break;
		}
	}*/

	rep(i,0,n) rep(j,0,n) printf("%d%c",grid[i][j]," \n"[j==n-1]);
//	puts("");

}