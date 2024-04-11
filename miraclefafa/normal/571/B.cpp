#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=301000;
int n,k,a[N];
ll dp[5010][5010];

void upd(ll &a,ll b) { if (b<a) a=b;}
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,n) scanf("%d",a+i);
	sort(a,a+n);
	int bk=n/k;
	rep(i,0,k+1) rep(j,0,i+1) dp[i][j]=1ll<<60;
	dp[0][0]=0;
	rep(i,0,k) rep(j,0,i+1) if (i*bk+j<n&&dp[i][j]<=(1ll<<40)) {
		if (i*bk+j+bk-1<n) upd(dp[i+1][j],dp[i][j]+a[i*bk+j+bk-1]-a[i*bk+j]);
		if (i*bk+j+bk<n) upd(dp[i+1][j+1],dp[i][j]+a[i*bk+j+bk]-a[i*bk+j]);
	}
	printf("%lld\n",dp[k][n%k]);
}