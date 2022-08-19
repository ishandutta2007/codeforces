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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=2010;
ll c[N][N],sc[N][N];
int lc[N],rc[N],qc[N],n;
char s[N];
ll ans;
ll comb(int x,int y) {
	if (y<0||y>x) return 0;
	return c[x][y];
}
ll ccomb(int x,int y) {
	y=max(y,0);
	if (y>x) return 0;
	return sc[x][y];
}
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n+1) {
		lc[i]=lc[i-1]+(s[i]=='(');
		rc[i]=rc[i-1]+(s[i]==')');
		qc[i]=qc[i-1]+(s[i]=='?');
	}
	for (int i=0;i<=n;i++) {
		c[i][0]=c[i][i]=1;
		rep(j,1,i) {
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
		per(j,0,i+1) {
			sc[i][j]=(c[i][j]+sc[i][j+1])%mod;
		}
	}
	rep(d,1,n/2+1) {
		for (int pos=1;pos<=n;pos++) {
			if (s[pos]==')') continue;
			// 1..pos-1  d-1 
			// pos+1...n  d 
			ll lway=0,rway=0;
			lway=comb(qc[pos-1],d-1-lc[pos-1]);
			rway=ccomb(qc[n]-qc[pos],d-(rc[n]-rc[pos]));
			ans=(ans+lway*rway)%mod;
		}
	}
	printf("%lld\n",ans);
}