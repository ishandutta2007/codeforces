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

const int N=55;
int f[N],s[N],p[N],R,n;
double dp[N][5050],p0;
double Q(int u,int v) {
	if (v>R) return p0;
	else return dp[u][v];
}
int main() {
	scanf("%d%d",&n,&R);
	rep(i,0,n) scanf("%d%d%d",f+i,s+i,p+i);
	double pL=0,pR=1e9;
	rep(it,0,100) {
		p0=(pL+pR)*0.5;
		rep(j,0,R+1) dp[n][j]=0;
		per(i,0,n) rep(j,0,R+1) {
			dp[i][j]=p0;
			dp[i][j]=min(dp[i][j],0.01*p[i]*(Q(i+1,j+f[i])+f[i])+(1-0.01*p[i])*(Q(i+1,j+s[i])+s[i]));
		}
		if (fabs(dp[0][0]-p0)<=1e-9) pL=p0; else pR=p0;
	}
	printf("%.10f\n",pR);
}