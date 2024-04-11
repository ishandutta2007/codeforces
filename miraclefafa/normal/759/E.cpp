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

const int N=301000;
vector<int> dp[N];
int n,a[N],b[N],dig[N],coin[N];
ll v[N];
char M[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i); a[0]=1;
	rep(i,0,n) scanf("%d",b+i);
	scanf("%s",M); int l=strlen(M); reverse(M,M+l);
	per(i,0,l) v[i/8]=v[i/8]*10+M[i]-'0'; l=(l+7)/8;
	rep(i,1,n) {
		if (a[i]==1) continue;
		ll remd=0;
		per(j,0,l) {
			remd=remd*100000000+v[j];
			v[j]=remd/a[i];
			remd%=a[i];
		}
		while (l&&v[l-1]==0) --l;
		dig[i-1]=remd;
	}
	if (l>1) {
		puts("0");
		return 0;
	}
	dig[n-1]=v[0];
	int c=0;
	rep(i,0,n) {
		c=(c+a[i]-1)/a[i]+b[i];
		coin[i]=c+1;
		dp[i]=VI(coin[i]+1,0);
	}
	dp[n]=VI(1,1);
	per(i,0,n) {
		rep(j,0,coin[i+1]+1) if ((ll)j*a[i+1]+dig[i]<=coin[i]) dp[i][j*a[i+1]+dig[i]]=dp[i+1][j];
		VI c=dp[i];
		per(j,0,coin[i]) c[j]=(c[j]+c[j+1])%mod;
		per(j,0,coin[i]) {
			dp[i][j]=c[j];
			if (j+b[i]+1<=coin[i]) dp[i][j]=(dp[i][j]-c[j+b[i]+1])%mod;
			if (dp[i][j]<0) dp[i][j]+=mod;
		}
	}
	printf("%d\n",dp[0][0]);
}