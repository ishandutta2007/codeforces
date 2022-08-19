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

int n,k;
double p[100],ff[100];
double dp[(1<<20)+10];
void gao(double pr,int i) {
	if (fabs(pr)<=1e-9) {
		puts("0");
		return;
	}
	dp[0]=pr;
	rep(i,0,n) ff[i]=0; ff[0]=pr;
	rep(S,1,(1<<n)) if ((S&(1<<i))==0){
		dp[S]=0;
		double prob=1;
		rep(j,0,n) if ((S&(1<<j))!=0){
			prob-=p[j];
			dp[S]+=dp[S^(1<<j)]*p[j];
		}
		dp[S]/=prob;
		ff[__builtin_popcount(S)]+=dp[S];
	}
	double v=0;
	rep(i,0,k) v+=ff[i];
	printf("%.10f\n",v);
}
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,n) scanf("%lf",p+i);
	rep(i,0,n) {
		gao(p[i],i);
	}
}