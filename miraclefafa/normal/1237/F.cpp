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
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=4010;
int h,w,n,u1,v1,u2,v2,markc[N],markr[N],empr,empc;
int dpr[N][N],dpc[N][N],comb[N][N];
ll fac[N];
int main() {
	scanf("%d%d%d",&h,&w,&n);
	rep(i,0,n) {
		scanf("%d%d%d%d",&u1,&v1,&u2,&v2);
		markr[u1]=markr[u2]=1;
		markc[v1]=markc[v2]=1;
	}
	comb[0][0]=1;
	fac[0]=1;
	rep(i,1,3600+1) {
		fac[i]=fac[i-1]*i%mod;
		comb[i][0]=comb[i][i]=1;
		rep(j,1,i) {
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
		}
	}
	markr[0]=markc[0]=1;
	rep(i,1,h+1) empr+=!markr[i];
	rep(i,1,w+1) empc+=!markc[i];
	// 1..h
	dpr[0][0]=1;
	rep(i,1,h+1) {
		rep(j,0,i+1) {
			dpr[i][j]=dpr[i-1][j];
			if (markr[i]==0&&markr[i-1]==0&&j>0) {
				dpr[i][j]=(dpr[i][j]+dpr[i-2][j-1])%mod;
			}
		}
	}
	dpc[0][0]=1;
	rep(i,1,w+1) {
		rep(j,0,i+1) {
			dpc[i][j]=dpc[i-1][j];
			if (markc[i]==0&&markc[i-1]==0&&j>0) {
				dpc[i][j]=(dpc[i][j]+dpc[i-2][j-1])%mod;
			}
		}
	}
	ll ans=0;
	rep(sr,0,h+1) rep(sc,0,w+1) if (dpr[h][sr]&&dpc[w][sc]) {
		ans=(ans+(ll)dpr[h][sr]*comb[empr-2*sr][sc]%mod*
			dpc[w][sc]%mod*comb[empc-2*sc][sr]%mod*fac[sr]%mod*fac[sc])%mod;
	}
	printf("%lld\n",ans);
}