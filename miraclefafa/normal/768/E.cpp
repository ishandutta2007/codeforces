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

const int N=66;
map<ll,int> dp[N];
int sg[66],n,x,r;
int calc(int x,ll ban) {
	if (dp[x].count(ban)) return dp[x][ban];
	else {
		ll r=0;
		rep(i,1,x+1) if (((ban>>i)&1)==0) {
			r|=1ll<<calc(x-i,ban|(1ll<<i));
		}
		rep(i,0,62) if (((r>>i)&1)==0) {
			return dp[x][ban]=i;
		}
	}
}
int main() {
	rep(i,1,61) {
		sg[i]=calc(i,0);
	}
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",&x);
		r^=sg[x];
	}
	puts(r?"NO":"YES");
}