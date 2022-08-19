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

const int N=2010;
int n,prob[N],x,q;
double dp[N],pd[N];
void upd(int &a,int b) { a=min(a,b); }
int main() {
	scanf("%d",&n);
	rep(i,0,2001) prob[i]=1e9;
	dp[0]=1;
	rep(i,0,100000) {
		rep(j,0,n+1) pd[j]=dp[j],dp[j]=0;
		rep(j,0,n+1) {
			dp[j]+=pd[j]*j/n;
			dp[j+1]+=pd[j]*(n-j)/n;
		}
//		printf("%.10f %d\n",dp[n],i+1);
		upd(prob[(int)((dp[n]+1e-9)*2000)],i+1);
		if (dp[n]>=0.5) break;
	}
	per(i,0,2000) prob[i]=min(prob[i],prob[i+1]);
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d",&x);
		printf("%d\n",prob[x]);
	}
}