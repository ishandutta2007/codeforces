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

const int N=201000;
int n,dp[N];
PII p[N];
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d",&p[i].fi,&p[i].se);
	sort(p,p+n);
	dp[0]=0;
	rep(i,1,n) {
		int x=lower_bound(p,p+n,mp(p[i].fi-p[i].se,0))-p;
//		printf("%d %d\n",i,x);
		if (x) dp[i]=dp[x-1]+(i-x);
		else dp[i]=i;
	}
	int ans=n;
	rep(i,0,n) ans=min(ans,dp[i]+(n-1-i));
	printf("%d\n",ans);
}