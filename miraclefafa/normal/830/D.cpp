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
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int k;
ll dp[410][410];
void upd(ll &a,ll b) { a=a+b; }
int main() {
	scanf("%d",&k);
	dp[1][0]=1;
	dp[1][1]=1;
	rep(i,2,k+1) {
		rep(l,0,k+1) rep(r,0,k+1) {
			ll c=dp[i-1][l]*dp[i-1][r]%mod;
			if (l+r<=k) upd(dp[i][l+r],c); // not take
			if (l+r+1<=k) upd(dp[i][l+r+1],c); // take
			if (l>0&&l+r<=k) upd(dp[i][l+r],c*2*l);
			if (r>0&&l+r<=k) upd(dp[i][l+r],c*2*r);
			if (l+r>0&&l+r-1<=k) upd(dp[i][l+r-1],c*(l+r)*(l+r-1));
		}
		rep(l,0,k+1) dp[i][l]%=mod;
	}
	printf("%lld\n",dp[k][1]);
}