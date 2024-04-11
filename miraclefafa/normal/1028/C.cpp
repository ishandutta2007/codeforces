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

const int N=200010;
const int inf=1<<30;
int px[N],py[N],qx[N],qy[N],n;
int lx1[N],ly1[N],rx1[N],ry1[N],lx2[N],ly2[N],rx2[N],ry2[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d%d%d%d",px+i,py+i,qx+i,qy+i);
	}
	lx1[0]=-inf;
	rx1[0]=inf;
	ly1[0]=-inf;
	ry1[0]=inf;
	rep(i,1,n+1) {
		lx1[i]=max(lx1[i-1],px[i]);
		ly1[i]=max(ly1[i-1],py[i]);
		rx1[i]=min(rx1[i-1],qx[i]);
		ry1[i]=min(ry1[i-1],qy[i]);
	}
	lx2[n+1]=-inf;
	rx2[n+1]=inf;
	ly2[n+1]=-inf;
	ry2[n+1]=inf;

	per(i,1,n+1) {
		lx2[i]=max(lx2[i+1],px[i]);
		ly2[i]=max(ly2[i+1],py[i]);
		rx2[i]=min(rx2[i+1],qx[i]);
		ry2[i]=min(ry2[i+1],qy[i]);
	}

	rep(i,1,n+1) {
		int lx0=max(lx1[i-1],lx2[i+1]);
		int ly0=max(ly1[i-1],ly2[i+1]);
		int rx0=min(rx1[i-1],rx2[i+1]);
		int ry0=min(ry1[i-1],ry2[i+1]);
		if (lx0<=rx0&&ly0<=ry0) {
			printf("%d %d\n",lx0,ly0);
			return 0;
		}
	}
	assert(0);
}