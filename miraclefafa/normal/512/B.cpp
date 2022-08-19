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

const int inf=0x20202020;
const int N=310;
int n,l[N],c[N];
map<int,int> dp;
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",l+i);
	rep(i,0,n) scanf("%d",c+i);
	dp[0]=0;
	rep(i,0,n) for (auto it:dp) {
//		printf("%d %d\n",it.fi,it.se);
		int d=__gcd(it.fi,l[i]);
		if (!dp.count(d)) dp[d]=inf;
		dp[d]=min(dp[d],it.se+c[i]);
	}
	if (!dp.count(1)) puts("-1");
	else printf("%d\n",dp[1]);
}