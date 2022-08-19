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

const int N=501000,inf=1<<30;
int a[N],f[N],g[N],h[N][2],n,ans;
int solve() {
	int pos=max_element(a+1,a+n+1)-a;
	f[0]=0;
	for (int i=1;i<=n;i++) {
		f[i]=inf;
		if (a[i]>a[i-1]) f[i]=min(f[i],f[i-1]);
		if (a[i]>f[i-1]) f[i]=min(f[i],a[i-1]);
	}
	g[n]=0;
	for (int i=n;i>=1;i--) {
		g[i]=inf;
		if (a[i]>a[i+1]) g[i]=min(g[i],g[i+1]);
		if (a[i]>g[i+1]) g[i]=min(g[i],a[i+1]);
	}
	h[pos][0]=f[pos];
	h[pos][1]=-1;
	int ans=0;
	for (int i=pos+1;i<=n;i++) {
		h[i][0]=inf;
		if (a[i]<a[i-1]) h[i][0]=min(h[i][0],h[i-1][0]);
		if (a[i]<h[i-1][1]) h[i][0]=min(h[i][0],a[i-1]);
		h[i][1]=-1;
		if (a[i]>a[i-1]) h[i][1]=max(h[i][1],h[i-1][1]);
		if (a[i]>h[i-1][0]) h[i][1]=max(h[i][1],a[i-1]);
		if (h[i][1]>g[i]) ans++;
		/*printf("i : %d a[i] : %d h[i][0] : %d h[i][1] : %d g[i] : %d\n",
			i,a[i],h[i][0],h[i][1],g[i]);*/
	}
	return ans;
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	ans+=solve();
	reverse(a+1,a+n+1);
	ans+=solve();
	printf("%d\n",ans);
}