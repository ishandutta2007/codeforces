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

const int M=(1<<20)+10;
int n,m,state[M],dp[M][22],pd[M][22];
char s[M];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%s",s);
		rep(j,0,m) state[j]|=(s[j]-'0')<<i;
	}
	rep(i,0,m) dp[state[i]][0]++;
	rep(i,0,n) {
		rep(S,0,(1<<n)) rep(j,0,n) pd[S][j]=dp[S][j],dp[S][j]=0;
		rep(S,0,(1<<n)) rep(j,0,n) {
			dp[S^(1<<i)][j+1]+=pd[S][j];
			dp[S][j]+=pd[S][j];
		}
	}
	int ans=n*m;
	rep(S,0,(1<<n)) {
		int sum=0;
		rep(j,0,n+1) sum+=dp[S][j]*min(j,n-j);
		ans=min(ans,sum);
	}
	printf("%d\n",ans);
}