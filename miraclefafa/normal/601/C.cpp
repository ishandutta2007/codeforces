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

int n,m,x;
long double dp[1010000],s[1010000];
int main() {
	scanf("%d%d",&n,&m);
	dp[0]=1;
	if (m==1) { puts("1"); return 0; }
	int S=0;
	rep(i,1,n+1) {
		scanf("%d",&x);
		S+=x;
		s[0]=dp[0];
		rep(j,1,i*m+1) s[j]=s[j-1]+dp[j];
		per(j,1,i*m+1) {
			dp[j]=s[j-1];
			if (j-m-1>=0) dp[j]-=s[j-m-1];
			if (j-x>=0) dp[j]-=dp[j-x];
			dp[j]/=(m-1);
		}
		dp[0]=0;
	//	rep(j,1,i*m+1) printf("%.10f ",dp[j]);
	//	puts("");
	}
	double prob=0;
	rep(i,0,S) prob+=dp[i];
	printf("%.10f\n",1+prob*(m-1));
}