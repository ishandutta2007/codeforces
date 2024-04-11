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

const int W=105;
int R,id[110][110],tot,pr[11111];
ll a[10],f[11111][222],g[11111];
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
ll gao() {
	rep(i,0,tot) pr[i]=i;
	rep(i,0,tot) {
		rep(j,0,W) if (f[i][W+j]) {
			if (j==0) break;
			swap(pr[i],pr[i+j]);
			for (int k=i;k<=i+W&&k<tot;k++)
				swap(f[k][W+j-(k-i)],f[k][W-(k-i)]);
			break;
		}
		if (f[i][W]==0) continue;
		ll inv=powmod(f[i][W],mod-2);
		rep(j,0,W) f[i][W+j]=f[i][W+j]*inv%mod; g[i]=g[i]*inv%mod;
		for (int k=i+1;k<=i+W&&k<tot;k++) if (f[k][W-(k-i)]) {
			ll c=(mod-f[k][W-(k-i)])%mod;
			rep(j,0,W) f[k][W-(k-i)+j]=(f[k][W-(k-i)+j]+c*f[i][W+j])%mod;
			g[k]=(g[k]+c*g[i])%mod;
		}
	}
	per(i,0,tot) if (f[i][W]!=0) {
		for (int k=i-1;k>=i-W&&k>0;k--) if (f[k][W+(i-k)]) g[k]=(g[k]-f[k][W+(i-k)]*g[i])%mod;
		if (pr[i]==id[R][R]) return g[i];
	}
	assert(0);
	return 0;
}
int main() {
	scanf("%d%lld%lld%lld%lld",&R,&a[0],&a[1],&a[2],&a[3]);
	ll p=powmod(a[0]+a[1]+a[2]+a[3],mod-2);
	rep(i,0,4) a[i]=a[i]*p%mod;
	for (int i=-R;i<=R;i++) for (int j=-R;j<=R;j++) {
		if (i*i+j*j<=R*R) id[i+R][j+R]=tot++; else id[i+R][j+R]=-1;
	}
	for (int i=-R;i<=R;i++) for (int j=-R;j<=R;j++) if (i*i+j*j<=R*R) {
		int d=id[i+R][j+R];
		f[d][W]=1; g[d]=1;
		rep(dd,0,4) {
			int x=i+dx[dd],y=j+dy[dd];
			if (x*x+y*y<=R*R) f[d][W-d+id[x+R][y+R]]=mod-a[dd];
		}
	}
	ll w=gao();
	if (w<0) w+=mod;
	printf("%lld\n",w);
}