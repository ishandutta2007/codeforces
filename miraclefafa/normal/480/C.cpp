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

const int N=5010;
int n,a,b,k;
ll dp[N],pd[N],ret;
int main() {
	scanf("%d%d%d%d",&n,&a,&b,&k);
	dp[a]=1;
	rep(i,0,k) {
		memset(pd,0,sizeof(pd));
		rep(x,1,n+1) if (x!=b) {
			int l=max(x-abs(x-b)+1,1),r=min(x+abs(x-b),n+1);
			pd[l]=(pd[l]+dp[x])%mod; pd[r]=(pd[r]-dp[x])%mod;
		}
		rep(x,1,n+1) {
			pd[x]=(pd[x]+pd[x-1])%mod;
			dp[x]=(pd[x]-dp[x])%mod;
		}
	}
	rep(x,1,n+1) if (x!=b) ret=(ret+dp[x])%mod;
	if (ret<0) ret+=mod;
	printf("%I64d\n",ret);
}