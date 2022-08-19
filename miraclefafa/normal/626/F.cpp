#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int dp[210][210][1010];
int n,v,a[510],ans;
void upd(int &a,ll b) { a=(a+b)%mod;}
int main() {
	scanf("%d%d",&n,&v);
	rep(i,0,n) scanf("%d",a+i);
	sort(a,a+n); reverse(a,a+n);
	dp[0][0][0]=1;
	rep(i,0,n) rep(j,0,i+1) rep(k,0,v+1) if (dp[i][j][k]) {
		int s=j*a[i]+k,ret=dp[i][j][k];
		// close
		if (j>0&&s-a[i]-(j-1)*a[i+1]<=v)
			upd(dp[i+1][j-1][s-a[i]-(j-1)*a[i+1]],(ll)ret*j);
		// open
		if (s+a[i]-(j+1)*a[i+1]<=v) 
			upd(dp[i+1][j+1][s+a[i]-(j+1)*a[i+1]],ret);
		// open & close put in
		if (s-j*a[i+1]<=v) upd(dp[i+1][j][s-j*a[i+1]],(ll)ret*(j+1));
	}
	rep(k,0,v+1) upd(ans,dp[n][0][k]);
	printf("%d\n",ans);
}