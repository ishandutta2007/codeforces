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
//const ll mod=1000000007;
int mod;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=1010;
ll dp[N][20],pd[N][20],f[N],t[20];
int n,d;

int main() {
	scanf("%d%d%d",&n,&d,&mod);
	if (n<=2) {
		puts("1");
		return 0;
	}
	if ((n-2)%(d-1)!=0) {
		puts("0");
		return 0;
	}
	dp[0][0]=1;
	rep(i,1,n/2+1) if ((i-1)%(d-1)==0) {
		if (i==1) f[i]=1; else f[i]=dp[i-1][d-1];
		t[0]=1;
		rep(j,1,d+1) {
			t[j]=t[j-1]*(f[i]+j-1)%mod*powmod(j,mod-2)%mod;
		}
		rep(p,0,n+1) rep(q,0,d+1) pd[p][q]=0;
		rep(r,0,d+1) rep(q,0,d+1) if (r+q<=d) rep(p,0,n+1) if (p+q*i<=n) {
			pd[p+q*i][r+q]=(pd[p+q*i][r+q]+dp[p][r]*t[q])%mod;
		}
		rep(p,0,n+1) rep(q,0,d+1) if (pd[p][q]) {
			dp[p][q]=pd[p][q];
		}
	}
	int ret=dp[n-1][d];
	if (n%2==0) {
		ret=(ret-dp[n/2-1][d-1]*(dp[n/2-1][d-1]-1)/2)%mod;
		if (ret<0) ret+=mod;
	}
	printf("%d\n",ret);
}