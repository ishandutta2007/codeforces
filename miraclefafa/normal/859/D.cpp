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

const int N=1010;
double win[N][N],e[N][N],prob[N][N];
int pp,n,m;
void dfs(int p,int l,int r) {
	if (l+1==r) win[p][l]=1,e[p][l]=0;
	else {
		int md=(l+r)>>1;
		dfs(p+p,l,md);
		dfs(p+p+1,md,r);
		rep(i,l,md) rep(j,md,r) win[p][i]+=win[p+p][i]*win[p+p+1][j]*prob[i][j];
		rep(i,l,md) rep(j,md,r) e[p][i]=max(e[p][i],win[p][i]*(r-l)/2+e[p+p][i]+e[p+p+1][j]);
		rep(i,md,r) rep(j,l,md) win[p][i]+=win[p+p+1][i]*win[p+p][j]*prob[i][j];
		rep(i,md,r) rep(j,l,md) e[p][i]=max(e[p][i],win[p][i]*(r-l)/2+e[p+p+1][i]+e[p+p][j]);
	}
}
int main() {
	scanf("%d",&n);
	m=(1<<n);
	rep(i,0,m) rep(j,0,m) scanf("%d",&pp),prob[i][j]=0.01*pp;
	dfs(1,0,m);
	double mv=0;
	rep(i,0,m) mv=max(mv,e[1][i]);
	printf("%.10f\n",mv);
}